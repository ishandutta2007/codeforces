#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
const int N = 4e5;
const int mod = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= mod)
    {
        x -= mod;
    }
    while(x < 0)
    {
        x += mod;
    }
    return x;
}
int sub(int x, int y)
{
    return add(x, -y);
}
int mul(int x, int y)
{
    return 1LL * x * y % mod;
}
int binpow(int x, int y)
{
    int z = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
        {
            z = mul(z, x);
        }
        x = mul(x, x);
        y /= 2;
    }
    return z;
}
int global_hash = 0;
void reverse(deque <pair <int, int> > &d)
{
    stack <pair <int, int> > s;
    while(!d.empty())
    {
        s.push(d.back());
        d.pop_back();
    }
    while(!s.empty())
    {
        d.push_front(s.top());
        s.pop();
    }
}
void safe_push_front(deque <pair <int, int> > &d, int c, int& res)
{
    int z = d.front().X ^ 1;
    res = add(res, mul(binpow(2, c), z));
    d.push_front(make_pair(z, c));
}
void safe_push_back(deque <pair <int, int> > &d, int c, int& res)
{
    int z = d.back().X ^ 1;
    res = add(res, mul(binpow(2, c), z));
    d.push_back(make_pair(z, c));
}
deque <pair <int, int> > ds[N * 2];
struct path{
    int s, t, d, c;
    path(){};
    path(int s, int t, int d, int c):s(s),t(t),d(d),c(c){};
    void push_front(int i )
    {
        safe_push_front(ds[d], i, c);
    }
    void push_back(int i)
    {
        safe_push_back(ds[d], i, c);
    }
    void pop_front()
    {
        ds[d].pop_front();
    }
    void pop_back()
    {
        ds[d].pop_back();
    }
    int front()
    {
        return ds[d].front().Y;
    }
    int back()
    {
        return ds[d].back().Y;
    }
    void reverse()
    {
        ::reverse(ds[d]);
        swap(s, t);
    }
    int size()
    {
        return sz(ds[d]);
    }
};
path link_to_left(path x, path y)
{
    path z = x;
    while(y.size() > 0)
    {
        z.push_back(y.front());
        y.pop_front();
    }
    z.t = y.t;
    return z;
}
path link_to_right(path x, path y)
{
    path z = y;
    while(x.size() > 0)
    {
        z.push_front(x.back());
        x.pop_back();
    }
    z.s = x.s;
    return z;
}
int cur = 0;
path make(int x, int y, int i)
{
    ds[cur].push_back(make_pair(0, i));
    return path(x, y, cur++, 0);
}
set <int> paths;
vector <int> g[N * 2];
path ps[N * 2];
path merge(path x, path y, int v)
{
    if(x.size() > y.size())
    {
        swap(x, y);
    }
    if(y.s == v)
    {
        if(x.t != v)
        {
            x.reverse();
        }
        return link_to_right(x, y);
    }
    else
    {
        if(x.s != v)
        {
            x.reverse();
        }
        return link_to_left(y, x);
    }
}
int cur2 = 0;
void modify(vector <int>& v, int x, int y)
{
    for(int i = 0; i < sz(v); i++)
    {
        if(v[i] == x)
        {
            v[i] = y;
        }
    }
}
void reassign(path p, int x, int y)
{
    modify(g[p.s], x, y);
    modify(g[p.t], x, y);
}
void merge_paths(int x, int y, int v)
{
    if(x == y)
    {
        return;
    }
    global_hash = sub(global_hash, ps[x].c);
    global_hash = sub(global_hash, ps[y].c);
    ps[cur2++] = merge(ps[x], ps[y], v);
    paths.erase(x);
    paths.erase(y);
    paths.insert(cur2 - 1);
    reassign(ps[x], x, cur2 - 1);
    reassign(ps[y], y, cur2 - 1);
    global_hash = add(global_hash, ps[cur2 - 1].c);
}
void relax(int v)
{
    while(g[v].size() >= 2)
    {
        int x = g[v].back();
        g[v].pop_back();
        int y = g[v].back();
        g[v].pop_back();
        merge_paths(x, y, v);
    }
}
void add_edge(int x, int y, int i)
{
    int c = cur2;
    ps[cur2++] = make(x, y, i);
    g[x].push_back(c);
    g[y].push_back(c);
    paths.insert(c);
    relax(x);
    relax(y);
}
void print_coloring()
{
    vector <int> ans;
    for(auto x : paths)
    {
        for(auto y : ds[ps[x].d])
        {
            if(y.X == 1)
            {
                ans.push_back(y.Y);
            }
        }
    }
    cout << sz(ans) << "\n";
    for(auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
    fflush(stdout);
}
int e = 0;
void process()
{
    int t;
    cin >> t;
    if(t == 1)
    {
        int x, y;
        cin >> x >> y;
        y += N + 1;
        add_edge(x, y, ++e);
        cout << global_hash<< "\n";
        fflush(stdout);
    }
    else
    {
        print_coloring();
    }
}
signed main()
{

    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        y += N + 1;
        add_edge(x, y, ++e);
    }
    int q;
    cin >> q;
    while(q--)
    {
        process();
    }
    return 0;
}