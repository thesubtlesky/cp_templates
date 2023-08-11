ll p = 50, m = MOD;

vector<ll> hashPrefixes;
vector<ll> powers;
void calculateHashPrefixes(string &s){
    int n = sz(s);
    hashPrefixes.clear();
    powers.resize(n,1);
    For(1,n){
        powers[i] = (powers[i-1]*p)%m;
    }
    For(0,n){
        int character = s[i]-'a'+1;
        if(i == 0){
            hashPrefixes.push_back(character);
        }else{
            hashPrefixes.push_back((hashPrefixes[i-1] + character*powers[i])%m);
        }
    }
}

ll susbstringHash(int l, int r){
    if(l == 0){
        return hashPrefixes[r];
    }
    ll a = mod_sub(hashPrefixes[r], hashPrefixes[l-1], m);
    ll b = powers[l];
    return mod_div(a, b, m);
    // ll modinverse_b = expo(b, m-2, m);
    // return (a*modinverse_b)%m;
}
