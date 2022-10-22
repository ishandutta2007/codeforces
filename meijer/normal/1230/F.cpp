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

const int MX=2e5;
ll n,m,q,a[MX],b[MX];
vector<ll> to[MX]; ll from[MX];
ll ans=0;

void makeRichest(ll nRich) {
    ans -= to[nRich].size()*from[nRich];
    for(ll a : to[nRich]) {
        from[nRich]++;
        ans -= to[a].size()*from[a];
        to[a].pb(nRich);
        from[a]--;
        ans += to[a].size()*from[a];
    }
    to[nRich].clear();
}
ll getAns() {
    RE(u,n)
        ans += from[u]*to[u].size();
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,m) cin>>a[i]>>b[i],a[i]--,b[i]--;

    RE(i,m) {
        if(b[i] < a[i]) swap(a[i], b[i]);
        to  [a[i]].pb(b[i]);
        from[b[i]]++;
    }

    cin>>q;
    cout<<getAns()<<endl;
    RE(i,q) {
        ll v;
        cin>>v; v--;
        makeRichest(v);
        cout<<ans<<endl;
    }
}