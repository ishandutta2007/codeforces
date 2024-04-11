
#include <bits/stdc++.h>
#define X first
#define ll long long
#define Y second
#define sz(a) (int)a.size()
using namespace std;
//#define int long long
const int maxn = 4e5 + 100;
const int maxm = 26;
char s[maxn];
int tot;
int n;
struct node{
    int dis;
    node *pre, *next[maxm];
}sa[maxn], *root;

node *new_node()
{
    return &sa[++tot];
}
int vertex[maxn];
void build_sa()
{
    node *cur = root = new_node();
    for(int i = n; i >= 1; i--)
    {
        int x = s[i] - 'a';
        node *p = cur;
        cur = new_node();
        cur -> dis = p -> dis + 1;
        vertex[i] = cur-sa;
        for(;p && !p -> next[x]; p = p -> pre)
        {
            p -> next[x] = cur;
        }
        if(!p)
        {
            cur -> pre = root;
        }
        else
        {
            node *q = p -> next[x];
            if(q -> dis == p -> dis + 1)
            {
                cur -> pre = q;
            }
            else
            {
                node *r = new_node();
                *r = *q;
                r -> dis = p -> dis + 1;
                cur -> pre = q -> pre = r;
                for(;p && p -> next[x] == q; p = p -> pre)
                {
                    p -> next[x] = r;
                }
            }
        }
    }
}
vector <int> g[maxn];
int _sz[maxn], son[maxn], father[maxn],pre[maxn], dis[maxn];
void dfs1(int v)
{
    _sz[v] = 1;
    if(!sz(g[v]))
    {
        return;
    }
    son[v] = -1;
    for(auto to : g[v])
    {
        dfs1(to);
        if(son[v] == -1 || _sz[to] > _sz[son[v]])
        {
            son[v] = to;
        }
        _sz[v] += _sz[to];
    }
}
void dfs2(int x)
{
    if(!father[x])
    {
        father[x] = x;
    }
    if(!sz(g[x]))
    {
        return;
    }
    father[son[x]] = father[x];
    dfs2(son[x]);
    for(auto to : g[x])
    {
        if(son[x] != to)
        {
            dfs2(to);
        }
    }
}
void build_tree()
{
    for(int i = 1; i <= tot; i++)
    {
        pre[i] = sa[i].pre ? sa[i].pre - sa : 0;
        dis[i] = sa[i].dis;
        if(pre[i])
        {
            g[pre[i]].push_back(i);
        }
    }
    dfs1(1);
    dfs2(1);
}
struct point{
    int no, len, pos;
};
vector<point> p[maxn];
int q;
struct query{
    int id, len, bound;
    bool operator<(const query &A)const{
        return bound < A.bound;
    }
};
vector <query> q1[maxn], q2[maxn];
void make_vertex(int v)
{
    int x = vertex[v];
    while(x > 1)
    {
        int y = father[x];
        p[y].push_back({v, dis[x] - dis[pre[y]], v + dis[pre[y]] + 1});
        x = pre[y];
    }
}
void make_query(int l, int len, int id)
{
    int x = vertex[l];
    while(x > 1)
    {
        int y = father[x];
        if(dis[pre[y]] < len)
        {
            q1[y].push_back({id, min(dis[x], len) - dis[pre[y]], l - 1});
            q2[y].push_back({id, min(dis[x], len) - dis[pre[y]], l + len});
        }
        x = pre[y];
    }
}
int w[maxn];
ll ww[maxn];
void update(int x)
{
    int p = x;
    while(x < maxn)
    {
        w[x] += 1;
        ww[x] += p;
        x += x & (-x);
    }
}
void resume(int x)
{
    while(x < maxn)
    {
        w[x] = ww[x] = 0;
        x += x & (-x);
    }
}
int getnum(int x)
{
    int p = 0;
    while(x)
    {
        p += w[x];
        x -= x & (-x);
    }
    return p;
}
ll getsum(int x)
{
    ll p = 0;
    while(x)
    {
        p += ww[x];
        x -= x & (-x);
    }
    return p;
}
bool cmp1(point a, point b)
{
    return a.no < b.no;
}
bool cmp2(point a, point b)
{
    return a.pos + a.len < b.pos + b.len;
}
ll ans[maxn];
void solve(vector<point> &p, vector <query> &q1, vector <query> &q2)
{
    if(sz(p) == 0)
    {
        return;
    }
    if(sz(q1))
    {
        sort(p.begin(), p.end(), cmp1);
        sort(q1.begin(), q1.end());
        auto j = p.begin();
        int all = 0;
        for(auto i  = q1.begin(); i != q1.end(); ++i)
        {
            for(;j != p.end() && j -> no <= i -> bound; ++j)
            {
                ++all;
                update(j -> len);
            }
            int s = getnum(i -> len);
            ll t = getsum(i -> len);
            ans[i -> id] -= 1LL * (all - s) * i -> len + t;
        }
        for(auto j = p.begin(); j != p.end(); ++j)
        {
            resume(j -> len);
        }
    }
    if(sz(q2))
    {
        sort(p.begin(), p.end(), cmp2);
        sort(q2.begin(), q2.end());
        auto j = p.begin();
        int all = 0;
        for(auto i  = q2.begin(); i != q2.end(); ++i)
        {
            for(; j != p.end() && j -> pos + j -> len <= i -> bound + 1; ++j)
            {
                ++all;
                update(j -> len);
            }
            int s = getnum(i -> len);
            ll t = getsum(i -> len);
            ans[i -> id] += 1LL * (all - s) * i -> len + t;
        }
        for(auto j = p.begin(); j != p.end(); ++j)
        {
            resume(j -> len);
        }
        reverse(p.begin(), p.end());
        reverse(q2.begin(), q2.end());
        j = p.begin();
        for(auto i = q2.begin(); i != q2.end(); i++)
        {
            for(; j != p.end() && j -> pos + j -> len > i -> bound + 1; ++j)
            {
                update(j -> pos);
            }
            int s = getnum(i -> bound);
            ll t = getsum(i -> bound);
            if(i -> bound - i -> len + 1 <= 0)
            {
                ans[i -> id] += 1LL * (i -> bound + 1) * s - t;
            }
            else
            {
                int s1 = getnum(i -> bound - i -> len + 1);
                ll t1 = getsum(i -> bound - i -> len + 1);
                ans[i -> id] += 1LL * s1 * i -> len + 1LL * (i -> bound + 1) * (s - s1) - (t - t1);
            }
        }
        for(auto j = p.begin(); j != p.end(); ++j)
        {
            resume(j -> pos);
        }
    }
}
void solve()
{
    for(int i = 1; i <= tot; i++)
    {
        solve(p[i], q1[i], q2[i]);
    }
}
signed main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	build_sa();
	build_tree();
	for(int i = 1; i <= n; i++)
    {
        make_vertex(i);
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        int len = y - x + 1;
        make_query(x, len, i);
    }
    solve();
    for(int i = 1; i <= q; i++)
    {
        cout << ans[i] << "\n";
    }
	return 0;
}