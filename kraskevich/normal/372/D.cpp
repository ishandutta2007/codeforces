#include <bits/stdc++.h>

using namespace std;

#define cerr cout

const int INF = (int)1e9;
const int N = (int)4e5;

vector<int> g[N];
set<int> tins;
int par[N][20];
int tat[N];
int vat[N];
int tin[N];
int h[N];
int tout[N];
int timer = 0;
bool u[N];
int n, k;
int ans;
int tree[10 * N];

void build(int i, int l, int r)
{
    if (l == r)
    {
        tree[i] = tat[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int get(int i, int l, int r, int tl, int tr)
{
    if (l == tl && r == tr)
        return tree[i];
    int m = (tl + tr) / 2;
    int sl = -1;
    int sr = -1;
    if (l <= m)
        sl = get(2 * i + 1, l, min(r, m), tl, m);
    if (r > m)
        sr = get(2 * i + 2, max(m + 1, l), r, m + 1, tr);
    return max(sl, sr);
}

int lca2(int, int);

void add(int v)
{
    int t = tin[v];
    auto up = tins.upper_bound(t);
    auto down = up;
    down--;
    /*cerr << *down << " ";
    if (up != tins.end())
        cerr << *up << endl;
    else
        cerr << endl;*/
    if (up != tins.end() && down != tins.begin())
    {
        int a = vat[*up];
        int b = vat[*down];
        int l = lca2(a, b);
        ans -= h[a] - h[l];
    }
    if (up != tins.end())
    {
        int a = vat[*up];
        int b = v;
        int l = lca2(a, b);
        ans += h[a] - h[l];
    }
    if (down != tins.begin())
    {
        int a = v;
        int b = vat[*down];
        int l = lca2(a, b);
        //cerr << "v1 v2 lca: " << a + 1 << " " << b + 1 << " " << l + 1 << endl;
        ans += h[a] - h[l];
    }
    tins.insert(t);
}

void del(int v)
{
    int t = tin[v];
    auto it = tins.find(t);
    auto up = it;
    auto down = it;
    down--;
    up++;
    if (up != tins.end() && down != tins.begin())
    {
        int a = vat[*up];
        int b = vat[*down];
        int l = lca2(a, b);
        ans += h[a] - h[l];
    }
    if (up != tins.end())
    {
        int a = vat[*up];
        int b = v;
        int l = lca2(a, b);
        ans -= h[a] - h[l];
    }
    if (down != tins.begin())
    {
        int a = v;
        int b = vat[*down];
        int l = lca2(a, b);
        ans -= h[a] - h[l];
    }
    tins.erase(t);
}

void dfs(int v, int hh, int pp)
{
    u[v] = true;
    h[v] = hh;
    tin[v] = timer++;
    par[v][0] = pp;
    for (int i = 1; i < 20; i++)
        par[v][i] = par[par[v][i - 1]][i - 1];
    for (int to : g[v])
        if (!u[to])
            dfs(to, hh + 1, v);
    tout[v] = timer++;
}

int lca(const set<int> &);

bool good(int a, int b)
{
    return tin[a] <= tin[b] && tin[b] <= tout[a];
}

int lca2(int a, int b)
{
    if (good(a, b))
        return a;
    if (good(b, a))
        return b;
    for (int i = 19; i >= 0; i--)
        if (!good(par[a][i], b))
            a = par[a][i];
    return par[a][0];
}

int lca(const set<int> &t)
{
    /*cerr << "Vertices:" << endl;
    for (int x : t)
        if (x >= 0)
            cerr << vat[x] + 1 << " ";
    cerr << endl;*/

    auto it1 = t.begin();
    it1++;
    int l = *it1;
    auto it = t.end();
    it--;
    int r = *it;
    //cerr << l << " " << r << endl;
    int low = 0;
    int high = l;
    while (low < high)
    {
        int m = (low + high + 1) / 2;
        if (get(0, m, l, 0, 2 * n - 1) >= r)
            low = m;
        else
            high = m - 1;
    }
    assert(vat[low] != -1);
    return vat[low];
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill(u, u + n, 0);
    dfs(0, 0, 0);
    fill(vat, vat + 2 * n, -1);
    fill(tat, tat + 2 * n, -1);
    for (int i = 0; i < n; i++)
    {
        vat[tin[i]] = i;
        tat[tin[i]] = tout[i];
    }
    build(0, 0, 2 * n - 1);
    int res = 1;
    ans = 0;
    tins.insert(-1);
    for (int l = 0, r = 0; l < n; l++)
    {
        assert(tins.size());
        if (tins.size() == 1)
            add(l);
        if (r <= l)
            r = l + 1;
        while (r < n)
        {
            add(r);
            int cur = ans;
            //cerr << cur << endl;
            int v = lca(tins);
            auto it = tins.begin();
            it++;
            int f = vat[*it];
            cur += h[f] - h[v] + 1;
            //cerr << l + 1 << " " << r + 1 << " " << v + 1 << " " << cur << endl;
            if (cur > k)
            {
                del(r);
                break;
            }
            else
            {
                r++;
            }
        }
        /*if (r == n)
            break;*/
        res = max(res, (int)tins.size() - 1);
        del(l);
    }
    cout << res << "\n";

    return 0;
}