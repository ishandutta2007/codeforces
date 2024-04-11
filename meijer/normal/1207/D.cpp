#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const ll MX=3e5+1e4;
const ll MOD=998244353;

ll n;
ll a[MX], b[MX];
ll SAA[MX], SAB[MX];
ll fact[MX];

ll countPerm(vi& v) {
    ll bTot = 1, last=0, cnt=0;
    REP(i,0,v.size()) {
        if(v[i] != last) last=v[i], bTot = (bTot*fact[cnt])%MOD, cnt=0;
        cnt++;
    }
    bTot = (bTot*fact[cnt])%MOD;
    return bTot;
}
ll getAB() {
    ll tot = 1, last=0, mx=0, nmx=0;
    vi l;
    REP(i,0,n) {
        ll v = a[SAA[i]];
        if(v != last) {
            last=v, mx=nmx;
            sort(l.begin(), l.end());
            tot = (tot*countPerm(l))%MOD;
            l.clear();
        }
        l.push_back(b[SAA[i]]);
        nmx = max(nmx, b[SAA[i]]);
        if(b[SAA[i]] < mx) tot=0;
    }
    sort(l.begin(), l.end());
    tot = (tot*countPerm(l))%MOD;
    l.clear();
    return tot;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) cin>>a[i]>>b[i];
    REP(i,0,n) SAA[i]=SAB[i]=i;
    sort(SAA,SAA+n, [](int i, int j) {
        return a[i]<a[j];
    });
    sort(SAB,SAB+n, [](int i, int j) {
        return b[i]<b[j];
    });
    fact[0]=1;
    REP(i,1,n+10) fact[i] = (fact[i-1]*i)%MOD;
    ll aTot = 1, last=0, cnt=0;
    REP(i,0,n) {
        ll v = a[SAA[i]];
        if(v != last) last=v, aTot = (aTot*fact[cnt])%MOD, cnt=0;
        cnt++;
    }
    aTot = (aTot*fact[cnt])%MOD;
    ll bTot = 1; last=0, cnt=0;
    REP(i,0,n) {
        ll v = b[SAB[i]];
        if(v != last) last=v, bTot = (bTot*fact[cnt])%MOD, cnt=0;
        cnt++;
    }
    bTot = (bTot*fact[cnt])%MOD;

    ll ans=fact[n]-aTot-bTot+getAB();
    while(ans < 0) ans+=MOD;
    ans %= MOD;
    cout<<ans<<endl;
}