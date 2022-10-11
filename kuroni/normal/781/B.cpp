#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

struct save
{
    string s1, s2;
    int i;
} a[1005];
string t1, t2;
int n, i, j = 0, s = 0, f, mf[3005][3005], cf[3005][3005], trace[3005], ans = 0, res[1005];
map <string, int> chk;
vector <int> adj[4005];
vector <string> t;

inline bool operator < (const save &a, const save &b)
{
    return (a.s1 < b.s1);
}

bool BFS()
{
    memset(trace, -1, sizeof(trace));
    queue <int> q;
    trace[s] = 0; q.push(s);
    int u, v, i;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (i = 0; i < adj[u].size(); i++)
        {
            v = adj[u][i];
            if (trace[v] == -1 && cf[u][v] < mf[u][v])
            {
                q.push(v);
                trace[v] = u;
                if (v == f)
                    return 1;
            }
        }
    }
    return 0;
}

int solve()
{
    int p = 1000005, v = f, u, i;
    while (v != s)
    {
        u = trace[v];
        p = min(p, mf[u][v] - cf[u][v]);
        v = u;
    }
    v = f;
    while (v != s)
    {
        u = trace[v];
        cf[u][v] += p;
        cf[v][u] -= p;
        v = u;
    }
    return p;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(); cout.tie();
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> t1 >> t2;
        a[i].s1 = t1.substr(0, 3);
        a[i].s2 = t1.substr(0, 2) + t2[0];
        adj[s].push_back(i); adj[i].push_back(s);
        mf[s][i] = 1;
        a[i].i = i;
    }
    sort(a + 1, a + n + 1);
    a[0].s1 = a[0].s2 = a[n + 1].s1 = a[n + 1].s2 = "000";
    for (i = 1; i <= n; i++)
    {
        if (a[i].s1 != a[i - 1].s1 && a[i].s1 != a[i + 1].s1 && !chk[a[i].s1])
        {
            t.push_back(a[i].s1);
            chk[a[i].s1] = true;
        }
        if (!chk[a[i].s2])
        {
            t.push_back(a[i].s2);
            chk[a[i].s2] = true;
        }
    }
    for (i = 1; i <= n; i++)
        for (j = 0; j < t.size(); j++)
        {
            if (a[i].s1 != a[i - 1].s1 && a[i].s1 != a[i + 1].s1 && a[i].s1 == t[j])
            {
                adj[i].push_back(j + 1 + n);
                adj[j + 1 + n].push_back(i);
                mf[i][j + 1 + n] = 1;
            }
            if (a[i].s2 == t[j])
            {
                adj[i].push_back(j + 1 + n);
                adj[j + 1 + n].push_back(i);
                mf[i][j + 1 + n] = 1;
            }
        }
    f = n + t.size() + 1;
    for (j = 0; j < t.size(); j++)
    {
        adj[n + j + 1].push_back(f);
        adj[f].push_back(n + j + 1);
        mf[n + j + 1][f] = 1;
    }
    while (BFS())
        ans += solve();
    if (ans < n)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (i = 1; i <= n; i++)
        for (j = 0; j < t.size(); j++)
            if (cf[i][j + n + 1] == 1)
            {
                res[a[i].i] = j;
                break;
            }
    for (i = 1; i <= n; i++)
        cout << t[res[i]] << '\n';
}