#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=2e5;

int n, m;
vector<pair<int, ii>> edges;
map<ll, ll> memAns;
ll ans=0;

ll getAns(ll sz) {
    return (sz*(sz-1))/2;
}
struct UF {
    vi p, r, sz;
    void resize(int s) {
        p.resize(s);
        r.resize(s);
        sz.resize(s);
        REP(i,0,s)
            p[i]=i, r[i]=sz[i]=1;
    }
    int unionFind(int i) {return p[i]==i?i:p[i]=unionFind(p[i]);}
    bool isSameSet(int i, int j) {return unionFind(i)==unionFind(j);}
    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            i=unionFind(i); j=unionFind(j);
            ans -= getAns(sz[i]);
            ans -= getAns(sz[j]);
            ans += getAns(sz[i]+sz[j]);
            if(r[i] < r[j]) {
                p[j] = i;
                sz[i] += sz[j];
            } else {
                p[i] = j;
                sz[j] += sz[i];
                if(r[i] == r[j]) r[j]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    edges.reserve(n-1);
    REP(i,0,n-1) {
        int u, v, w;
        cin>>u>>v>>w; u--, v--;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(), edges.end());
    UF uf; uf.resize(n);
    REP(i,0,edges.size()) {
        uf.unionSet(edges[i].second.first, edges[i].second.second);
        memAns[edges[i].first] = ans;
    }
    REP(i,0,m) {
        int q; cin>>q;
        if(i!=0) cout<<" ";
        auto it = memAns.upper_bound(q);
        if(it == memAns.begin()) cout<<0;
        else it--, cout<<it->second;
    }
    cout<<endl;
}