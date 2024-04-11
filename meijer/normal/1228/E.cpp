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

const int MX=300, MOD=1e9 + 7;
ll n, k;
ll mem[MX][MX];
ll CMEM[MX][MX];
ll modPowK[MX];
ll modPowL[MX];

ll C(ll N, ll K) {
    if(CMEM[N][K] == -1) {
        if(K == 0 || K == N) {
            CMEM[N][K] = 1;
        } else {
            CMEM[N][K] = C(N-1, K-1) + C(N-1, K);
            CMEM[N][K] %= MOD;
        }
    }
    return CMEM[N][K];
}
ll getAns(ll wleft, ll h) {
    if(h == 0) return (wleft == 0 ? 1 : 0);
    if(mem[wleft][h] == -1) {
        ll ans=0;
        ll wused = n-wleft;
        REP(i,1,wused+1) {
            ans += ((C(wused, i)*modPowL[n-i])%MOD)*getAns(wleft, h-1);
            ans %= MOD;
        }
        REP(i,1,wleft+1) {
            ans += ((((C(wleft, i)*modPowK[wused])%MOD)*modPowL[wleft-i])%MOD)*getAns(wleft-i, h-1);
            ans %= MOD;
        }
        mem[wleft][h] = ans;
    }
    return mem[wleft][h];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    RE(i,n+1) RE(j,n+1) mem[i][j]=CMEM[i][j]=-1;
    modPowK[0]=modPowL[0]=1;
    REP(i,1,n+1) {
        modPowK[i] = modPowK[i-1]*k;
        modPowK[i] %= MOD;
        modPowL[i] = modPowL[i-1]*(k-1);
        modPowL[i] %= MOD;
    }
    cout<<getAns(n,n)<<endl;
}