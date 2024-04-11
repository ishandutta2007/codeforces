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

const ll MX=1e6, SGMX=MX*4;
ll n, x[MX], y[MX], c[MX], b[MX], e[MX], SA[MX];
ll X[MX], Y[MX], C[MX], N;
ll SEG[SGMX], SEGMX[SGMX], SEGMXL[SGMX];
set<ll> positions;
map<ll, ll> posToI;
ll P[MX];

void buildSeg(ll p=0, ll l=0, ll r=N-1) {
    SEG[p]=SEGMX[p]=0;
    SEGMXL[p]=l;
    if(l != r) {
        ll m=(l+r)/2;
        buildSeg(p*2+1,l,m);
        buildSeg(p*2+2,m+1,r);
    }
}
void updateSeg(ll i, ll j, ll v, ll lazy=0, ll p=0, ll l=0, ll r=N-1) {
    SEG[p] += lazy;
    SEGMX[p] += lazy;
    if(j < l || i > r) return;
    if(i <= l && j >= r) {
        SEG[p] += v;
        SEGMX[p] += v;
    } else {
        ll m=(l+r)/2;
        updateSeg(i,j,v,SEG[p],p*2+1,l,m);
        updateSeg(i,j,v,SEG[p],p*2+2,m+1,r);
        SEG[p] = 0;
        SEGMX[p] = max(SEGMX[p*2+1], SEGMX[p*2+2]);
        SEGMXL[p] = (SEGMX[p*2+1]>SEGMX[p*2+2] ? SEGMXL[p*2+1] : SEGMXL[p*2+2]);
    }
}
void updatePositions() {
    RE(i,n) positions.insert(X[i]), positions.insert(Y[i]);
    ll j = 0;
    for(ll i:positions)
        P[j] = i, posToI[i] = j++;
    N = j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>X[i]>>Y[i]>>C[i];
    RE(i,n) if(X[i] > Y[i]) swap(X[i], Y[i]);
    RE(i,n) SA[i] = i;
    updatePositions();
    buildSeg();

    sort(SA, SA+n, [](ll i, ll j) {
        return Y[i]<Y[j];
    });
    RE(i,n) x[i] = X[SA[i]], y[i] = Y[SA[i]], c[i] = C[SA[i]];
    RE(i,n) b[i] = posToI[x[i]], e[i] = posToI[y[i]];
    ll ans=0, ansL=2e9, ansR=2e9;
    RE(i,n) {
        if(i!=0 && y[i] != y[i-1]) {
            if(SEGMX[0] > ans) {
                ans = SEGMX[0];
                ansR = y[i-1];
                ansL = P[SEGMXL[0]];
            }
        }
        if(i==0 || y[i] != y[i-1]) {
            ll beg = (i==0 ? 0 : e[i-1]);
            REP(j,beg,e[i])
                updateSeg(0,j,-P[j+1]+P[j]);
        }
        updateSeg(0,b[i],c[i]);
}
    if(SEGMX[0] > ans) {
        ans = SEGMX[0];
        ansR = y[n-1];
        ansL = P[SEGMXL[0]];
    }
    cout<<ans<<endl;
    cout<<ansL<<" "<<ansL<<" "<<ansR<<" "<<ansR<<endl;
}