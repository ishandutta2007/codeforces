#include <vector>
#include <set>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;

class vertex
{
    public:
        int v;
        long long w;
        vertex(int vv = 0, long long ww = 0)
        {
            v = vv;
            w = ww;
        }
};

bool operator < (vertex a, vertex b)
{
    return a.w < b.w || a.w == b.w && a.v < b.v;
}

class edge
{
    public:
        int f, to;
        long long w;
        edge(int ff = 0, int tt = 0, long long ww = 0)
        {
            f = ff;
            to = tt;
            w = ww;
        }
};

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

class mst
{
    public:
        vector<int> p;
        
        void init(int n)
        {
            srand(137);
            p.resize(n);
            for(int i = 0; i < n; ++i)
                p[i] = i;
        }
        int get(int v)
        {
            return v == p[v] ? v : p[v] = get(p[v]);
        }
        void unite(int a, int b)
        {
            a = get(a);
            b = get(b);
            if(rand() & 1)
                swap(a, b);
            if(a != b)
                p[a] = b;
        }
        long long weight(int n, vector<edge> e)
        {
            sort(e.begin(), e.end(), cmp);
            init(n);
            
            long long res = 0;
            
            for(int i = 0; i < e.size(); ++i)
            {
                int from = e[i].f, to = e[i].to;
                if(get(from) != get(to))
                {
                    res += e[i].w;
                    unite(from, to);
                }
            }
            return res;
        }
};

#define pii pair<int, long long>
vector<pii> g[100000];
vector<long long> d(100000, (long long)1e18);
vector<int> p(100000, -1);

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[v].push_back(pii(u, w));
        g[u].push_back(pii(v, w));
    }
    
    int k;
    cin >> k;
    
    set<vertex> s;
    
    for(int i = 0; i < k; ++i)
    {
        int nn;
        cin >> nn;
        --nn;
        p[nn] = nn;
        d[nn] = 0;
        s.insert(vertex(nn, d[nn]));
    }
    
    while(!s.empty())
    {
        vertex v = *s.begin();
        s.erase(*s.begin());
        
        for(int i = 0; i < g[v.v].size(); ++i)
        {
            int to = g[v.v][i].first;
            if(d[to] > d[v.v] + g[v.v][i].second)
            {
                s.erase(vertex(to, d[to]));
                p[to] = p[v.v];
                d[to] = d[v.v] + g[v.v][i].second;
                s.insert(vertex(to, d[to]));
            }
        }
    }
    
    vector<int> port;
    for(int i = 0; i < n; ++i)
        if(p[i] >= 0)
            port.push_back(p[i]);
    sort(port.begin(), port.end());
    
    map<int, int> mp;
    int cnt = 0;
    for(int i = 0; i < port.size(); ++i)
    {
        if(i && port[i] == port[i - 1])
            continue;
        mp.insert(make_pair(port[i], cnt));
        ++cnt;
    }
    
    vector<edge> e;
    for(int v = 0; v < n; ++v)
        for(int i = 0; i < g[v].size(); ++i)
        {
            if(p[v] == -1 || p[g[v][i].first] == -1)
                continue;
            e.push_back(edge(mp[p[v]], mp[p[g[v][i].first]], d[v] + d[g[v][i].first] + g[v][i].second));
        }
            
    mst ans;
    cout << d[0] + ans.weight(cnt, e);
    
    cin >> n;
    
    return 0;
}