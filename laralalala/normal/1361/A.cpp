#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 500005

vector<int> g[MAXN];
int t[MAXN],act[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    vector<pii> p;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<n;i++)
    {
        cin >> t[i];
        p.push_back(pii(t[i],i));
    }

    sort(all(p));
    bool ok=1;
    for(int i=0;i<n;i++)
    {
        int u=p[i].s;
//        cout << u  << ' ' << t[u] << '\n';
        set<int> s;
        for(auto v : g[u])
            s.insert(act[v]);
        int c=1;
        while(s.find(c)!=s.end())
            c++;
        ok&=(c==t[u]);
        act[u]=c;
    }

    if(ok)
    {
        for(int i=0;i<n;i++)
            cout << p[i].s+1 << ' ';
        cout << '\n';
    }
    else
        db(-1)

    return 0;
}
/**
3 3
1 2
2 3
3 1
2 1 3
**/