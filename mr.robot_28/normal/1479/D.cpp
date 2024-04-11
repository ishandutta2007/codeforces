#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (1 << 20);
const int L = 20;
const int NMAX = 3e7;
struct node{
    int l, r, h;
}trees[NMAX];
int ptr = 2;
int pw[N];
int clone(int v)
{
    trees[ptr] = trees[v];
    return ptr++;
}
int update(int v, int l, int r, int pos)
{
    v = clone(v);
    if(l == r)
    {
        trees[v].h ^= 1;
        return v;
    }
    if(pos <= (r + l) / 2)
    {
        trees[v].l = update(trees[v].l, l, (r + l) / 2, pos);
    }
    else
    {
        trees[v].r = update(trees[v].r, (r + l) / 2 + 1, r, pos);
    }
    int it_l = trees[v].l;
    int it_r = trees[v].r;
    trees[v].h = (trees[it_r].h + pw[r - (r + l) / 2] * trees[it_l].h);
    return v;
}
int ask(int v, int l, int r, int pos)
{
    if(!v || r == l)
    {
        return trees[v].h;
    }
    if(pos <= (r + l) / 2)
    {
        return ask(trees[v].l, l, (r + l) / 2, pos);
    }
    return ask(trees[v].r, (r + l) / 2 + 1, r, pos);
}
int compare1(int v, int u, int l, int r)
{
    if(trees[v].h == trees[u].h)
    {
        return N;
    }
    if(l == r)
    {
        return l;
    }
    int t = compare1(trees[v].l, trees[u].l, l, (r + l) / 2);
    if(t == N)
    {
        return compare1(trees[v].r, trees[u].r, (r + l) / 2 + 1, r);
    }
    return t;
}
int compare(int v, int u, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return compare1(v, u, l, r);
    }
    if(ar < l || al > r)
    {
        return N;
    }
    int midd = (r + l) / 2;
    int t = compare(trees[v].l, trees[u].l, l, midd, al, ar);
    if(t == N)
    {
        return compare(trees[v].r, trees[u].r, midd + 1, r, al, ar);
    }
    return t;
}
int tree_uk[N];
int tin[N];
int tout[N];
int lg[N];
vector <int> g[N];
int A[N];
int mass[L][N];
int timer = 0;
void dfs(int v, int p = -1)
{
    tin[v] = timer;
    mass[0][timer++] = v;
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        tree_uk[to] = update(tree_uk[v], 0, N, A[to]);
        dfs(to, v);
        mass[0][timer++] = v;
    }
    tout[v] = timer;
}
int minf(int a, int b)
{
    return tin[a] < tin[b] ? a : b;
}
int lca(int a, int b)
{
    a = tin[a];
    b = tin[b];
    if(a > b)
    {
        swap(a, b);
    }
    int t = lg[b - a + 1];
    return minf(mass[t][a], mass[t][b - (1 << t) + 1]);
}
int solve(int u, int v, int l, int r)
{
    int w = lca(u, v);
    //cout << u << " " << v << " " << w << "\n";
    int res;
    if(A[w] >= l && A[w] <= r)
    {
        res = compare(tree_uk[u], tree_uk[v], 0, N, l, A[w]);
        if(res == N)
        {
            return A[w];
        }
        if(res == A[w])
        {
            res = compare(tree_uk[u], tree_uk[v], 0, N, A[w] + 1, r);
        }
    }
    else
    {
        res = compare(tree_uk[u], tree_uk[v], 0, N, l, r);
    }
    if(res == N)
    {
        return -1;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    pw[0] = 1;
    for(int i = 1; i < N; i++)
    {
        pw[i] = pw[i - 1] * 3 ;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    trees[0].l = trees[0].r = trees[0].h = 0;
    lg[1] = 0;
    for(int i = 2; i < N; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    tree_uk[0] = update(tree_uk[0], 0, N, A[0]);
    dfs(0);
    for(int i = 1; i < L; i++)
    {
        for(int j = 0; j + (1 << i) <= N; j++)
        {
            mass[i][j] = minf(mass[i - 1][j], mass[i - 1][(1 << (i - 1)) + j]);
        }
    }
    while(q--)
    {
        int v, u, l, r;
        cin >> v >> u >> l >> r;
        v--;
        u--;
        cout << solve(v, u, l, r) << "\n";
    }
    return 0;
}