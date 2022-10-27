#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;
const int N = 2e5 + 100;
int dsu[N], rang[N];
int pred(int a)
{
    if(dsu[a] == a)return a;
    else return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
    a = pred(a);
    b = pred(b);
    if(a == b)
    {
        return;
    }
    if(rang[a] < rang[b])
    {
        swap(a, b);
    }
    dsu[b] = a;
    if(rang[a] == rang[b])
    {
        rang[a]++;
    }
}
vector <pair <int, int> > g[N];
vector <pair <int, pair <int, int> > > ver;
int n, m;
int _xor;
ll stupid()
{
    for(int i = 0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
    }
    sort(ver.begin(), ver.end());
    set <int> st;
    vector <pair <int, int> > ver1;
    for(int i = 0; i < n; i++)
    {
        st.insert(i);
        sort(g[i].begin(), g[i].end());
    }
    while(sz(st) > 0)
    {
        queue <int> q;
        q.push(*st.begin());
        st.erase(*st.begin());
        while(sz(q) > 0)
        {
            int v = q.front();
            q.pop();
            set <int> :: iterator it, it1;
            while(sz(st) > 0 && (sz(g[v]) == 0 || *st.begin() < g[v][0].X))
            {
                ver1.push_back({v, *st.begin()});
                q.push(*st.begin());
                st.erase(*st.begin());
            }
            for(int i = 0; i < sz(g[v]); i++)
            {
                it = st.upper_bound(g[v][i].X);
                while(it != st.end() && (i == sz(g[v]) - 1 || *it < g[v][i + 1].X))
                {
                    ver1.push_back({v, *it});
                    it1 = it;
                    it1++;
                    q.push(*it);
                    st.erase(*it);
                    it = it1;
                }
            }
        }
    }
    if(1LL * n * (n - 1) / 2 > sz(ver) + sz(ver1))
    {
        ll sum = 0;
        for(int i = 0; i < sz(ver1); i++)
        {
            unite(ver1[i].X, ver1[i].Y);
        }
        for(int i = 0; i < sz(ver); i++)
        {
            if(pred(ver[i].Y.X) != pred(ver[i].Y.Y))
            {
                unite(ver[i].Y.X, ver[i].Y.Y);
                sum += ver[i].X;
            }
        }
        return sum;
    }
    ll ans = 1e18;
    for(int f1 = 0; f1 < sz(ver1); f1++)
    {
        for(int i = 0; i < n; i++)
        {
            dsu[i] = i;
            rang[i] = 1;
        }
        ll s = 0;
        for(int i = 0; i < sz(ver1); i++)
        {
            if(i != f1)
            {
                unite(ver1[i].X, ver1[i].Y);
            }
        }
        for(int i = 0; i < sz(ver); i++)
        {
            if(ver[i].X <= _xor && pred(ver[i].Y.X) != pred(ver[i].Y.Y))
            {
                unite(ver[i].Y.X, ver[i].Y.Y);
                s += ver[i].X;
            }
        }
        if(pred(ver1[f1].X) != pred(ver1[f1].Y))
        {
            s += _xor;
            unite(ver1[f1].X, ver1[f1].Y);
        }
        for(int i = 0; i < sz(ver); i++)
        {
            if(pred(ver[i].Y.X) != pred(ver[i].Y.Y))
            {
                unite(ver[i].Y.X, ver[i].Y.Y);
                s += ver[i].X;
            }
        }
        ans = min(ans, s);
    }
    return ans;
}
int stupid1()
{
    for(int i = 0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
    }
    sort(ver.begin(), ver.end());
    vector <pair <int, pair <int, int> > > u;
    for(int i = 0; i < sz(ver); i++)
    {
        if(pred(ver[i].Y.X) != pred(ver[i].Y.Y))
        {
            u.push_back(ver[i]);
            unite(ver[i].Y.X, ver[i].Y.Y);
        }
    }
    swap(u, ver);
    set <int> st;
    vector <pair <int, int> > ver1;
    for(int i = 0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
        st.insert(i);
        sort(g[i].begin(), g[i].end());
    }
    while(sz(st) > 0)
    {
        queue <int> q;
        q.push(*st.begin());
        st.erase(*st.begin());
        while(sz(q) > 0)
        {
            int v = q.front();
            q.pop();
            set <int> :: iterator it, it1;
            while(sz(st) > 0 && (sz(g[v]) == 0 || *st.begin() < g[v][0].X))
            {
                ver1.push_back({v, *st.begin()});
                q.push(*st.begin());
                st.erase(*st.begin());
            }
            for(int i = 0; i < sz(g[v]); i++)
            {
                it = st.upper_bound(g[v][i].X);
                while(it != st.end() && (i == sz(g[v]) - 1 || *it < g[v][i + 1].X))
                {
                    ver1.push_back({v, *it});
                    it1 = it;
                    it1++;
                    q.push(*it);
                    st.erase(*it);
                    it = it1;
                }
            }
        }
    }
    if(1LL * n * (n - 1) / 2 > m + sz(ver1))
    {
        ll sum = 0;
        for(int i = 0; i < sz(ver1); i++)
        {
            unite(ver1[i].X, ver1[i].Y);
        }
        for(int i = 0; i < sz(ver); i++)
        {
            if(pred(ver[i].Y.X) != pred(ver[i].Y.Y))
            {
                unite(ver[i].Y.X, ver[i].Y.Y);
                sum += ver[i].X;
            }
        }
        swap(u, ver);
        return sum;
    }
    ll ans = 1e18;
    for(int f1 = 0; f1 < sz(ver1); f1++)
    {
        for(int i = 0; i < n; i++)
        {
            dsu[i] = i;
            rang[i] = 1;
        }
        ll s = 0;
        for(int i = 0; i < sz(ver1); i++)
        {
            if(i != f1)
            {
                unite(ver1[i].X, ver1[i].Y);
            }
        }
        for(int i = 0; i < sz(ver); i++)
        {
            if(ver[i].X <= _xor && pred(ver[i].Y.X) != pred(ver[i].Y.Y))
            {
                unite(ver[i].Y.X, ver[i].Y.Y);
                s += ver[i].X;
            }
        }
        if(pred(ver1[f1].X) != pred(ver1[f1].Y))
        {
            s += _xor;
            unite(ver1[f1].X, ver1[f1].Y);
        }
        for(int i = 0; i < sz(ver); i++)
        {
            if(pred(ver[i].Y.X) != pred(ver[i].Y.Y))
            {
                unite(ver[i].Y.X, ver[i].Y.Y);
                s += ver[i].X;
            }
        }
        ans = min(ans, s);
    }
    swap(ver, u);
    return ans;
}
int solve()
{
    sort(ver.begin(), ver.end());
    set <int> st;
    vector <pair <int, int> > ver1;
    for(int i = 0; i < n; i++)
    {
        st.insert(i);
        sort(g[i].begin(), g[i].end());
    }
    while(sz(st) > 0)
    {
        queue <int> q;
        q.push(*st.begin());
        st.erase(*st.begin());
        while(sz(q) > 0)
        {
            int v = q.front();
            q.pop();
            set <int> :: iterator it, it1;
            while(sz(st) > 0 && (sz(g[v]) == 0 || *st.begin() < g[v][0].X))
            {
                ver1.push_back({v, *st.begin()});
                q.push(*st.begin());
                st.erase(*st.begin());
            }
            for(int i = 0; i < sz(g[v]); i++)
            {
                while(sz(st) > 0)
                {
                    it = st.upper_bound(g[v][i].X);
                    if(it == st.end())
                    {
                        break;
                    }
                    if(i != sz(g[v]) - 1 && g[v][i + 1].X <= *it)
                    {
                        break;
                    }
                    ver1.push_back({v, *it});
                    q.push(*it);
                    st.erase(*it);
                }
            }
        }
    }
    if(1LL * n * (n - 1) / 2 > sz(ver) + sz(ver1))
    {
        cout << "A";
        ll sum = 0;
        for(int i = 0; i < sz(ver1); i++)
        {
            unite(ver1[i].X, ver1[i].Y);
        }
        for(int i = 0; i < sz(ver); i++)
        {
            if(pred(ver[i].Y.X) != pred(ver[i].Y.Y))
            {
                unite(ver[i].Y.X, ver[i].Y.Y);
                sum += ver[i].X;
            }
        }
        return sum;
    }
    ll sum = 0;
    for(int i = 0; i < sz(ver); i++)
    {
        if(ver[i].X < _xor && pred(ver[i].Y.X) != pred(ver[i].Y.Y))
        {
            unite(ver[i].Y.X, ver[i].Y.Y);
        }
    }
    int f1 = -1;
    for(int i = 0; i < sz(ver1); i++)
    {
        if(pred(ver1[i].X) == pred(ver1[i].Y))
        {
            f1 = i;
        }
        else
        {
            unite(ver1[i].X, ver1[i].Y);
        }
    }
    if(f1 == -1)
    {
        for(int i = 0; i < n; i++)
        {
            dsu[i] = i;
            rang[i] = 1;
        }
        sum = 0;
        for(int i = 0; i < sz(ver1); i++)
        {
            unite(ver1[i].X, ver1[i].Y);
        }
        sum += _xor;
        for(int i = 0; i < sz(ver); i++)
        {
            if(pred(ver[i].Y.X) != pred(ver[i].Y.Y))
            {
                sum += ver[i].X;
                unite(ver[i].Y.X, ver[i].Y.Y);
            }
        }
        cout << sum;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
    }
    for(int i = 0; i < sz(ver1); i++)
    {
        if(i != f1)
        {
            unite(ver1[i].X, ver1[i].Y);
        }
    }
    sum = 0;
    for(int i = 0; i < sz(ver); i++)
    {
        if(pred(ver[i].Y.X) != pred(ver[i].Y.Y))
        {
            sum += ver[i].X;
            unite(ver[i].Y.X, ver[i].Y.Y);
        }
    }
    for(int i = 0; i < n; i++)
    {
        assert(pred(i) == pred(0));
    }
    return sum;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
        g[i].clear();
    }
    map <pair <int, int>, int> mp;
    _xor = 0;
    ver.clear();
    vector <pair <int, pair <int, int> > > op;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
       // w = rand() % (10);
        cin >> u >> v >> w;
        u--;
        v--;
        mp[{u, v}] = mp[{v, u}] = 1;
        ver.push_back({w, {u, v}});
        op.push_back(ver.back());
        _xor ^= w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cout << stupid1();
    return 0;
}