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

const ll MX=2e5 + 10;
ll n, m;
ll x[MX], lAns[MX];

inline void addValueLazy(ll l, ll r, ll value) {
    lAns[l]   += value;
    lAns[r+1] -= value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,m) cin>>x[i], x[i]--;
    RE(i,n) lAns[i] = 0;
    RE(i,m-1) {
        ll mx = x[i+1], mn=x[i];
        if(mx == mn) continue;
        if(mx < mn) swap(mn, mx);
        addValueLazy(0,mn-1,mx-mn);
        addValueLazy(mx+1,n-1,mx-mn);
        addValueLazy(mn+1,mx-1,mx-mn-1);
        addValueLazy(mx,mx,mn+1);
        addValueLazy(mn,mn,mx);
    }
    ll v=0;
    v+=lAns[0]; cout<<v;
    REP(i,1,n) v+=lAns[i], cout<<" "<<v;
    cout<<endl;
}