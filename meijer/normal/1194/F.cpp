#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=3e5, MOD=1e9+7;
ll n, T, t[MX], fact[MX];

ll modpow(ll x, ll N) {
    if(N == 0) return 1;
    ll a = modpow(x,N/2);
    a = (a*a)%MOD;
    if(N%2) a = (a*x)%MOD;
    return a;
}
ll inv(ll x) {
    return modpow(x, MOD-2);
}
ll bico(ll N, ll k) {
    return (fact[N]*inv((fact[k]*fact[N-k])%MOD))%MOD;
}
void fillFact() {
    fact[0] = 1;
    REP(i,1,n+1) fact[i] = (fact[i-1]*i)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>T;
    RE(i,n) cin>>t[i];
    fillFact();
    ll P=0, Q=modpow(2,n), mxT=T, prevP=0, prevMi=0;
    bool prev=0;
    RE(i,n) {
        mxT -= t[i];
        ll mnT = mxT-i-1;
        if(mxT < 0) break;
        if(mnT >= 0) {
            P = (P+Q)%MOD;
        } else {
            if(prev) {
                ll newP = (2*prevP + bico(i, prevMi+1));
                REP(j,mxT+1,prevMi+2) {
                    newP = newP - bico(i+1, j);
                    while(newP < 0) newP += MOD;
                    newP %= MOD;
                }

                P = (P + newP*modpow(2,n-i-1))%MOD;
                prevMi = mxT;
                prevP = newP;
            } else {
                prev = 1;
                ll range    = i+1;
                prevMi      = mxT;
                RE(j,prevMi+1)
                    prevP = (prevP+bico(range, j))%MOD;
                P = (P + prevP*modpow(2,n-i-1))%MOD;
            }
        }
    }
    cout<<(P*inv(Q))%MOD<<endl;
}