#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 200005

vector<pii> g[MAXN];
vector<pip> edges;
bool mk[MAXN];
ll d[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k,u,v,w;
    cin >> n >> m >> k;
    for(ll i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        edges.push_back(pip(w,pii(u,v)));
    }

    sort(edges.begin(),edges.end());

    for(ll i=0;i<min(k,m);i++)
    {
        u=edges[i].second.first;
        v=edges[i].second.second;
        w=edges[i].first;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }

    vector<ll> ds;
    for(ll i=1;i<=n;i++)
    {
        priority_queue<pii,vector<pii>,greater<pii> > pq;
        vector<ll> nodes;
        pq.push(pii(0,i));
        while(!pq.empty())
        {
            pii x=pq.top();
            pq.pop();
            u=x.second;
            w=x.first;
            if(mk[u])
                continue;
            mk[u]=1;
            d[u]=w;
            nodes.push_back(u);
            for(auto y : g[u])
            {
                ll v=y.first;
                ll w0=y.second;
                if(!mk[v])
                    pq.push(pii(w+w0,v));
            }
        }

        for(auto v : nodes)
        {
            if(v<i)
                ds.push_back(d[v]);
            mk[v]=0;
        }
    }

    sort(ds.begin(),ds.end());

    db(ds[k-1])

    return 0;
}