#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pll;
#define F first
#define S second
#define MP make_pair

struct bit
{
    vector<int> f;

    bit(int n)
    {
        f.assign(n, 0);
    }

    int get(int i)
    {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            res += f[i];
        return res;
    }

    void put(int i, int by)
    {
        for (; i < f.size(); i = (i | (i + 1)))
            f[i] += by;
    }
};

const int N = (int)3e5;
vector<int> g[N];
vector<int> times[N];
vector<int> vals[N];
vector<int> ids[N];
int a[N];
int ans[N];
bool need[N];
bool u[N];
int n, m;

void dfs(int v, bit &pos, bit &neg)
{
    u[v] = true;
    for (int i = 0; i < times[v].size(); i++)
    {
        int t = times[v][i];
        int add = vals[v][i];
        pos.put(t, add);
    }
    for (int id : ids[v])
    {
        int inc = pos.get(id);
        int dec = neg.get(id);
        ans[id] = a[v] + inc - dec;
    }
    for (int to : g[v])
        if (!u[to])
            dfs(to, neg, pos);
    for (int i = 0; i < times[v].size(); i++)
    {
        int t = times[v][i];
        int add = vals[v][i];
        pos.put(t, -add);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    fill(u, u + n, 0);
    fill(need, need + m, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int aa, b;
        cin >> aa >> b;
        --aa;
        --b;
        g[aa].push_back(b);
        g[b].push_back(aa);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, val;
            cin >> v >> val;
            --v;
            times[v].push_back(i);
            vals[v].push_back(val);
        }
        else
        {
            int v;
            cin >> v;
            --v;
            ids[v].push_back(i);
            need[i] = true;
        }
    }
    bit pos(m);
    bit neg(m);
    dfs(0, pos, neg);
    for (int i = 0; i < m; i++)
        if (need[i])
            cout << ans[i] << "\n";

    return 0;
}