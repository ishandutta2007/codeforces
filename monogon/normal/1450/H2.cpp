#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int mxN = 200001;
ll fact[mxN], ifact[mxN];
ll nCr(int n, int r) {
    if(r > n || r < 0)return 0;
    return ((fact[n]*ifact[n-r])%MOD*ifact[r])%MOD;
}
ll binpow(ll a,ll b) {
    ll res=1;
    while(b) {
        if(b&1)res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
        
    }
    return res;
}
ll modInv(ll a) {
    return binpow(a, MOD-2);
}
string s;
int n, q;
int b[2], w[2], f[2];
ll tpow[mxN];
ll tinv[mxN];
ll ans[4]; 
ll lft, func;
void print() {
    ll res = (ans[1]*lft + ans[2]*func)%MOD;
    res = (ans[0]*func + ans[3]*lft - res + MOD)%MOD;
    res = (res * tinv[lft])%MOD;
    cout<<res<<"\n";
}
void fix() {
    ans[0] = ans[1] = ans[2] = ans[3] = 0;
    int parity = abs(func)&1;
    for(int i = parity; i <= min(func-2, lft); i+=2) {
        ans[0] = (ans[0] + nCr(lft, i))%MOD;
    }
    for(int i = parity; i <= min(func-2, lft); i+=2) {
        ans[1] = (ans[1] + nCr(lft-1, i-1))%MOD;
    }
    for(int i = func+2; i <= lft; i+=2) {
        ans[3] = (ans[3] + nCr(lft-1, i-1))%MOD;
    }
    for(int i = func+2; i <= lft; i+=2) {
        ans[2] = (ans[2] + nCr(lft, i))%MOD;
    }
}
void inc() { // increase the numerator
    ans[0] = (2*ans[0] - nCr(lft-1, func-2) + MOD)%MOD;
    ans[1] = (2*ans[1] - nCr(lft-2, func-3) + MOD)%MOD;
    ans[2] = tpow[lft-1] - ans[2];
    ans[2] = 2*ans[2] - nCr(lft-1, func);
    ans[2] = ((tpow[lft] - ans[2])%MOD + MOD)%MOD;
    ans[3] = tpow[lft-2] - ans[3];
    ans[3] = 2*ans[3] - nCr(lft-2, func-1);
    ans[3] = ((tpow[lft-1] - ans[3])%MOD + MOD)%MOD;
    lft++;
}
void binc() { //increase denominator
    ans[0] = (ans[0] + nCr(lft-1, func-1))%MOD;
    ans[1] = (ans[1] + nCr(lft-2, func-2))%MOD;
    ans[2] = (ans[2] - nCr(lft-1, func+1) + MOD)%MOD;
    ans[3] = (ans[3] - nCr(lft-2, func) + MOD)%MOD;
    func++;
}
void dec() { //decrease the numerator
    ans[0] = ((ans[0] + nCr(lft-2, func-2))*tinv[1])%MOD;
    ans[1] = ((ans[1] + nCr(lft-3, func-3))*tinv[1])%MOD;
    ans[2] = tpow[lft-1] - ans[2];
    ans[2] = ((ans[2] + nCr(lft-2, func))*tinv[1])%MOD;
    ans[2] = (tpow[lft-2] - ans[2] + MOD)%MOD;
    ans[3] = tpow[lft-2] - ans[3];
    ans[3] = ((ans[3] + nCr(lft-3, func-1))*tinv[1])%MOD;
    ans[3] = (tpow[lft-3] - ans[3] + MOD)%MOD;
    lft--;
}
void bdec() { //decrease denominator
    ans[0] = (ans[0] - nCr(lft-1, func-2) + MOD)%MOD;
    ans[1] = (ans[1] - nCr(lft-2, func-3) + MOD)%MOD;
    ans[2] = (ans[2] + nCr(lft-1, func))%MOD;
    ans[3] = (ans[3] + nCr(lft-2, func-1))%MOD;
    func--;
}
int main() {
    fact[0] = 1;
    tpow[0] = 1;
    for(int i = 1; i < mxN; ++i){
        fact[i] = (fact[i-1]*i)%MOD;
        tpow[i] = (tpow[i-1]*2)%MOD;
    }
    ifact[mxN-1] = modInv(fact[mxN-1]);
    tinv[mxN-1] = modInv(tpow[mxN-1]);
    for(int i = mxN-2; i >= 0; --i) {
        ifact[i] = (ifact[i+1]*(i+1))%MOD;
        tinv[i] = (tinv[i+1]*2)%MOD;
    }
    cin>>n>>q>>s;
    for(int i = 0; i < n; ++i) {
        if(s[i]=='w') {
            w[i&1]++;
        }else if(s[i]=='b') {
            b[i&1]++;
        }else {
            f[i&1]++;
        }
    }
    lft = f[0] + f[1];
    func = n/2 - b[1] - w[0];
    fix();
    print();
    for(int i = 0; i < q; ++i) {
        int a;
        char c;
        cin>>a>>c;
        a--;
        //uncolor
        if(s[a]=='w') {
            inc();
            if((a&1)^1) binc();
        }else if(s[a]=='b') {
            inc();
            if(a&1) binc();
        }
        //recolor
        if(c=='w') {
            dec();
            if((a&1)^1) bdec();
        }else if(c=='b') {
            dec();
            if(a&1) bdec();
        }
        s[a] = c;
        if(lft<=2) fix();
        print();
    }
    return 0;
}