#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int N = 5e5;
set <int> st;
set <int> g[N];
set <int> t[N];
void dfs(int u)
{
    st.erase(u);
    int pos = -1;
    while(true)
    {
        auto it = st.upper_bound(pos);
        if(it == st.end())
        {
            break;
        }
        int v = *it;
        pos = v;
        if(g[u].find(pos) != g[u].end())
        {
            continue;
        }
        t[u].insert(v);
        t[v].insert(u);
        dfs(v);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n, m;
        cin >> n >> m;
        st.clear();
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++)
        {
            g[i].clear();
            t[i].clear();
            st.insert(i);
        }
        vector <int> deg(n);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].insert(v);
            g[v].insert(u);
        }
        while(st.size() != 0)
        {
            int v = *st.begin();
            dfs(v);
        }
        set <pair <int, int> > st1;
        int it = n;
        for(int i = 0; i < n; i++)
        {
            deg[i] = t[i].size();
            if(deg[i] == 0)
            {
                a[i] = b[i] = it;
                it--;
            }
            else
            {
                st1.insert({deg[i], i});
            }
        }
        vector <pair <int, vector <int> > > res;
        while(st1.size() > 0)
        {
            int v = st1.begin() -> second;
            int u = *t[v].begin();
            st1.erase({t[u].size(), u});
            vector <int> leaves;
            for(auto to : t[u])
            {
                st1.erase({deg[to], to});
                if(deg[to] == 1)
                {
                    leaves.push_back(to);
                }
                else
                {
                    deg[to]--;
                    st1.insert({deg[to], to});
                    t[to].erase(u);
                }
            }
            res.push_back({u, leaves});
        }
        int l, r;
        l = r = 0;
        for(int i = 0; i < res.size(); i++)
        {
            a[res[i].X] = ++l;
            for(auto v : res[i].Y)
            {
                a[v] = ++l;
                b[v] = ++r;
            }
            b[res[i].X] = ++r;
        }
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        for(int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}