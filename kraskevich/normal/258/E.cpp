#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const int N = 111111;
vector<int> g[N];
vector<int> q[N];
int tin[N];
int tout[N];
bool u[N];
int t = 0;
vector<int> times;
int tr[10 * N];
int add[10 * N];
int cnt[10 * N];
int ans[N];
int n, m;

void build(int i, int l, int r)
{
    tr[i] = 0;
    add[i] = 0;
    cnt[i] = r - l + 1;
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
}

void upd(int i, int l, int r, int tl, int trrr, int delta)
{
    if (l == tl && r == trrr)
    {
        add[i] += delta;
        return;
    }
    int m = (tl + trrr) / 2;
    if (l <= m)
        upd(2 * i + 1, l, min(r, m), tl, m, delta);
    if (r > m)
        upd(2 * i + 2, max(m + 1, l), r, m + 1, trrr, delta);
    int ml = add[2 * i + 1] + tr[2 * i + 1];
    int cl = cnt[2 * i + 1];
    int mr = add[2 * i + 2] + tr[2 * i + 2];
    int cr = cnt[2 * i + 2];
    if (ml < mr)
    {
        tr[i] = ml;
        cnt[i] = cl;
    }
    if (mr < ml)
    {
        tr[i] = mr;
        cnt[i] = cr;
    }
    if (ml == mr)
    {
        tr[i] = ml;
        cnt[i] = cl + cr;
    }
}

int val(int i, int p, int tl, int trrr, int a)
{
    a += add[i];
    if (tl == p && trrr == p)
    {
        if (a + tr[i] > 0)
            return 1;
        else
            return 0;
    }
    int m = (tl + trrr) / 2;
    if (p <= m)
        return val(2 * i + 1, p, tl, m, a);
    else
        return val(2 * i + 2, p, m + 1, trrr, a);
}

void dfs1(int v)
{
    u[v] = true;
    tin[v] = t++;
    times.push_back(tin[v]);
    for (int to: g[v])
        if (!u[to])
            dfs1(to);
    tout[v] = t++;
}

void dfs2(int v)
{
    u[v] = true;
    for (int x: q[v])
    {
        int lo = lower_bound(times.begin(), times.end(), tin[x]) - times.begin();
        int hi = upper_bound(times.begin(), times.end(), tout[x]) - times.begin();
        hi--;
        upd(0, lo, hi, 0, n - 1, 1);
    }
    ans[v] = n - (tr[0] + add[0] == 0 ? cnt[0] : 0) - val(0, lower_bound(times.begin(), times.end(), tin[v])- times.begin(), 0, n - 1, 0);
    for (int x: g[v])
        if (!u[x])
            dfs2(x);
    for (int x: q[v])
    {
        int lo = lower_bound(times.begin(), times.end(), tin[x]) - times.begin();
        int hi = upper_bound(times.begin(), times.end(), tout[x]) - times.begin();
        hi--;
        upd(0, lo, hi, 0, n - 1, -1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        q[a].push_back(a);
        q[b].push_back(b);
        q[a].push_back(b);
        q[b].push_back(a);
    }
    fill(u, u + n, 0);
    dfs1(0);
    build(0, 0, n - 1);
    fill(u, u + n, 0);
    dfs2(0);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";


    return 0;
}