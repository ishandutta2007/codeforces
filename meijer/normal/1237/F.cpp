#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=3700;
const ll MOD=998244353;
ll n, h, w, H, W;

ll fact[MX];
ll memR[MX][MX], memC[MX][MX];
ll BICO[MX][MX];
bitset<MX> usedC, usedR;

void fillFact() {
    fact[0] = 1;
    REP(i,1,MX) fact[i] = (fact[i-1]*i)%MOD;
}
ll bico(ll N, ll k) {
    if(BICO[N][k] == -1) {
        if(k == 0 || k == N) BICO[N][k] = 1;
        else if(k > N) BICO[N][k] = 0;
        else BICO[N][k] = (bico(N-1, k-1) + bico(N-1, k))%MOD;
    }
    return BICO[N][k];
}

ll getR(ll y, ll i) {
    if(i == 0)
        return 1;
    if(y <= 0)
        return 0;
    if(memR[y][i] == -1) {
        memR[y][i] = getR(y-1,i);
        if(usedR[y] == 0 && usedR[y-1] == 0)
            memR[y][i] = (memR[y][i]+getR(y-2, i-1))%MOD;
    }
    return memR[y][i];
}
ll getC(ll x, ll i) {
    if(i == 0)
        return 1;
    if(x <= 0)
        return 0;
    if(memC[x][i] == -1) {
        memC[x][i] = getC(x-1,i);
        if(usedC[x] == 0 && usedC[x-1] == 0)
            memC[x][i] = (memC[x][i]+getC(x-2, i-1))%MOD;
    }
    return memC[x][i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>w>>n; H=h, W=w;
    usedC.reset(); usedR.reset();
    RE(i,n) {
        ll r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;;
        usedR[--r1]=usedR[--r2]=usedC[--c1]=usedC[--c2]=1;
    }
    RE(i,MX) RE(j,MX) memR[i][j]=memC[i][j]=BICO[i][j]=-1;
    RE(i,h) if(usedR[i]) H--;
    RE(i,w) if(usedC[i]) W--;
    fillFact();

    ll ans=0;
    for(ll dh=0; dh*2 <= W; dh++) {
        for(ll dv=0; dv*2 <= H; dv++) {
            ll R = (getR(h-1, dv)*bico(H-dv*2,dh))%MOD;
            ll C = (getC(w-1, dh)*bico(W-dh*2,dv))%MOD;
            ll added = (R*C)%MOD;
            added = (added*fact[dh])%MOD;
            added = (added*fact[dv])%MOD;
            ans = (ans+added)%MOD;
        }
    }
    cout<<ans<<endl;
}