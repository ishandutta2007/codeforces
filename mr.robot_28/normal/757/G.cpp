#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 4e5 + 100;
const int mod = 1e9 + 7;
int A[N];
int n, q;
vector <pair <int, int> > g[N];
int it;
void binarizing(int v, int p = -1)
{
    vector <pair <int, int>> vec;
    for(auto to : g[v])
    {
        if(to.X == p)
        {
            continue;
        }
        binarizing(to.X, v);
        vec.push_back({to.X, to.Y});
    }
    while(sz(vec) > 1)
    {
        int a = vec.back().X;
        int w1 = vec.back().Y;
        vec.pop_back();
        int b = vec.back().X;
        int w2 = vec.back().Y;
        vec.pop_back();
        g[it].push_back({a, w1});
        g[a].push_back({it, w1});
        g[it].push_back({b, w2});
        g[b].push_back({it, w2});
        vec.push_back({it, 0});
        it++;
    }
    g[v].clear();
    if(sz(vec) == 0)
    {
        return;
    }
    g[v].push_back({vec.back().X, vec.back().Y});
    g[vec.back().X].push_back({v, vec.back().Y});
}
int timer = 0;
int tin[N], tout[N];
int h[N];
const int T = 20;
int euler[T][N * 2];
int Log2[N * 2];
int h1[N];
void dfs(int v, int p = -1)
{
    tin[v] = timer;
    euler[0][timer++] = v;
    for(auto to : g[v])
    {
        if(to.X == p)
        {
            continue;
        }
        h[to.X] = h[v] + to.Y;
        h1[to.X] = h1[v] + 1;
        dfs(to.X, v);
        euler[0][timer++] = v;
    }
    tout[v] = timer - 1;
}
bool pred(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int min_v(int a, int b)
{
    return (h1[a] <= h1[b]) ? a : b;
}
int lca(int a, int b)
{
     a = tin[a];
     b = tin[b];
     //cout << a << " " << b << "\n";
     if(a > b)
     {
        swap(a, b);
     }
     int t = Log2[b - a + 1];
     return min_v(euler[t][a], euler[t][b - (1 << t) + 1]);
}
int iter = 0;
struct node{
    node* child[4];
    ll sum, cnt, psum;
    int v;
    node* p;
    node(){
        sum = cnt = psum = v = 0;
        p = NULL;
        child[0] = child[1] = child[2] = child[3] = 0;
    }
};
int _sz[N];
int used[N];
void dfs_sz(int v, int p = -1)
{
    _sz[v] = 1;
    for(auto to : g[v])
    {
        if(to.X == p || used[to.X])
        {
            continue;
        }
        dfs_sz(to.X, v);
        _sz[v] += _sz[to.X];
    }
}
int centroid(int v, int sz1, int p = -1)
{
    for(auto to : g[v])
    {
        if(to. X != p && !used[to.X] && _sz[to.X] * 2 > sz1)
        {
            return centroid(to.X, sz1, v);
        }
    }
    return v;
}
void build(node* t, int v)
{
    dfs_sz(v);
    v = centroid(v, _sz[v]);
    t -> v = v;
    used[v] = 1;
    t -> sum = t -> cnt = t -> psum = 0;
    int z = 0;
    for(auto to : g[v])
    {
        if(used[to.X])
        {
            continue;
        }
        t -> child[z] = new node();
        build(t -> child[z], to.X);
        t -> child[z] -> p = t;
        z++;
    }
    t -> child[z] = NULL;
}
bool is_on_path(int x, int a, int b)
{
    int t = lca(a, b);
    if(pred(t, x) && (pred(x, a) || pred(x, b)))
    {
        return 1;
    }
    return 0;
}
int dist(int a, int b)
{
    int c = lca(a, b);
   // cout << a << " " << b << " " << c << "\n";
    return h[a] + h[b] - 2 * h[c];
}
void go_to(node* _new, node* last, int v)
{
    _new -> v = last -> v;
    _new -> p = last -> p;
    for(int i = 0; i < 4; i++)
    {
        _new -> child[i] = last -> child[i];
    }
    _new -> sum = last -> sum;
    _new -> psum = last -> psum;
    _new -> cnt = last -> cnt;

    _new -> sum += dist(_new -> v, v);
    _new -> cnt++;
    if(last -> v == v)
    {
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(!_new -> child[i])
        {
            return;
        }
        if(!is_on_path(_new -> v, _new -> child[i] -> v, v))
        {
            _new -> child[i] = new node();
            go_to(_new -> child[i], last -> child[i], v);
            _new -> child[i] -> psum += dist(_new -> v, v);
        }
    }
}
node* vec[N];
ll funct(node *x, int v)
{
 //   cout << "A " << x -> v << " " << x -> sum << " " << x -> cnt << "\n";
    if(x -> v == v)
    {
        return x -> sum - x -> psum + dist(v, x -> v) * x -> cnt;
    }
    for(int i = 0; i < 4; i++)
    {
        if(!x -> child[i])
        {
            continue;
        }
        if(!is_on_path(x -> v, x -> child[i] -> v, v))
        {
            return x -> sum - x -> psum + funct(x -> child[i], v) + (x -> cnt - x -> child[i] -> cnt) * dist(v, x -> v);
        }
    }
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    Log2[1] = 0;
    for(int i = 2; i < N * 2; i++)
    {
        Log2[i] = Log2[i / 2] + 1;
    }
    it = n;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        A[i]--;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    binarizing(0);
    dfs(0);
    for(int i = 1; i < T; i++)
    {
        for(int j = 0; j + (1 << i)<= timer; j++)
        {   
             euler[i][j] = min_v(euler[i - 1][j], euler[i - 1][j + (1 << (i - 1))]);
//             cout << euler[i][j] << " ";
        }
  //      cout << "\n";
    }
    node* start = new node();
    build(start, 0);
    vec[0] = start;
    for(int i = 1; i <= n; i++)
    {
        vec[i] = new node();
        go_to(vec[i], vec[i -1], A[i - 1]);
    }
    int pred = 0;
    ll pred1 = 0;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l, r, v;
            cin >> l>> r >> v;
            l = (pred & ((1 << 30) - 1)) ^ l;
            r = (pred & ((1 << 30) - 1)) ^ r;
            v = (pred & ((1 << 30) - 1)) ^ v;
            v--;
     //       cout << l << " " << r << " " << v << "\n";
            pred1 = (funct(vec[r], v) - funct(vec[l - 1], v));
            cout << pred1 << "\n";
            pred1 &= ((1 << 30) - 1);
            pred = (int)pred1;
        }
        else
        {
            int x;
            cin >> x;
            x = (pred & ((1 << 30) - 1)) ^ x;
            swap(A[x - 1], A[x]);
            go_to(vec[x], vec[x - 1], A[x - 1]);
        }
    }
   //     cout << "A";
    return 0;
}