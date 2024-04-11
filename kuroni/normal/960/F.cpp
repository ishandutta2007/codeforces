#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 100005;

int n, m, ans = 0;
vector<int> ve[N];

struct SEdge
{
    int u, v, w;
} a[M];

struct SBIT
{
    int sz;
    vector<int> bit;

    SBIT(int _sz = 0)
    {
        sz = _sz;
        bit = vector<int>(sz + 1, 0);
    }
    
    void update(int u, int v)
    {
        for (; u <= sz; u += u & -u)
            bit[u] = max(bit[u], v);
    }

    int query(int u)
    {
        int ret = 0;
        for (; u > 0; u -= u & -u)
            ret = max(ret, bit[u]);
        return ret;
    }
} bit[N];

int get(int pos, int u)
{
    return distance(ve[pos].begin(), lower_bound(ve[pos].begin(), ve[pos].end(), u)) + 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        ve[a[i].v].push_back(a[i].w);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(ve[i].begin(), ve[i].end());
        ve[i].erase(unique(ve[i].begin(), ve[i].end()), ve[i].end());
        bit[i] = SBIT(ve[i].size());
    }
    for (int i = 1; i <= m; i++)
    {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        int pos = get(u, w);
        int ret = bit[u].query(pos - 1) + 1;
        ans = max(ans, ret);
        bit[v].update(get(v, w), ret);
    }
    cout << ans;
}