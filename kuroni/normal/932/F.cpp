#include <bits/stdc++.h>
using namespace std;

const int N = 100005, LG = 17;
const long long INF = 1E18 + 7;

int n, u, v, a[N], b[N];
long long f[N];
vector<int> adj[N];

struct SLine
{
    int a;
    long long b;

    SLine(int _a = 0, long long _b = 0)
    {
        a = _a; b = _b;
    }

    double intersect(const SLine &oth)
    {
        return 1.0 * (oth.b - b) / (a - oth.a);
    }

    long long at(int pos)
    {
        return 1LL * a * pos + b;
    }
};

struct SCHT
{
    vector<SLine> ve;

    SCHT()
    {
        ve.clear();
    }

    void push(SLine u)
    {
        if (!ve.empty() && ve.back().a == u.a)
        {
            u.b = min(u.b, ve.back().b);
            ve.pop_back();
        }
        while (ve.size() >= 2 && u.intersect(ve[ve.size() - 2]) >= u.intersect(ve[ve.size() - 1]))
            ve.pop_back();
        ve.push_back(u);
    }

    long long minima(int pos)
    {
        int le = 1, ri = ve.size() - 1;
        while (le <= ri)
        {
            int mi = (le + ri) / 2;
            if (ve[mi].intersect(ve[mi - 1]) <= pos)
                le = mi + 1;
            else
                ri = mi - 1;            
        }
        return ve[ri].at(pos);
    }
} cht[N][LG];

SCHT merge(const SCHT &a, const SCHT &b)
{
    SCHT ans = SCHT();
    int l = 0, r = 0;
    while (l < a.ve.size() || r < b.ve.size())
    {
        if (r == b.ve.size())
            ans.push(a.ve[l++]);
        else if (l == a.ve.size())
            ans.push(b.ve[r++]);
        else if (a.ve[l].a > b.ve[r].a)
            ans.push(a.ve[l++]);
        else
            ans.push(b.ve[r++]);
    }
    return ans;
}

void DFS(int u, int p = 0)
{
    bool ch = false;
    for (int &v : adj[u])
        if (v != p)
        {
            ch = true;
            DFS(v, u);
            for (int i = 0; i < LG; i++)
                if (!cht[v][i].ve.empty())
                {
                    SCHT cur = cht[v][i];
                    cht[v][i].ve.clear();
                    for (int j = i; j < LG; j++)
                        if (cht[u][j].ve.empty())
                        {
                            cht[u][j] = cur;
                            break;
                        }
                        else
                        {
                            cur = merge(cur, cht[u][j]);
                            cht[u][j].ve.clear();
                        }
                }
        }
    f[u] = (ch ? INF : 0);
    for (int i = 0; i < LG; i++)
        if (!cht[u][i].ve.empty())
            f[u] = min(f[u], cht[u][i].minima(a[u]));
    SCHT cur = SCHT();
    cur.push(SLine(b[u], f[u]));
    for (int i = 0; i < LG; i++)
        if (cht[u][i].ve.empty())
        {
            cht[u][i] = cur;
            break;
        }
        else
        {
            cur = merge(cur, cht[u][i]);
            cht[u][i].ve.clear();
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
}