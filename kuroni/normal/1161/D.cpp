#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2005, MOD = 998244353;

int n, dsu[N], col[N];
long long ans = 0;
char s[N];
vector<int> adj[N];

int trace(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

void connect(int u, int v)
{
    if ((u = trace(u)) == (v = trace(v)))
        return;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

void add_edge(int u, int v)
{
    u = trace(u); v = trace(v);
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool DFS(int u, int cur = 0)
{
    col[u] = cur;
    for (int &v : adj[u])
        if (col[v] == -1 && !DFS(v, cur ^ 1))
            return false;
        else if (col[v] == col[u])
            return false;
    return true;
}

long long solve(int u)
{
    // node 1: zero
    // node 2: one
    // node 3 -> n + 2: b[i]
    // node n + 3 -> n + u + 2: a[i]
    long long ans = 499122177;
    for (int i = 1; i <= n + u + 2; i++)
    {
        dsu[i] = -1;
        col[i] = -1;
        adj[i].clear();
    }
    connect(3, 2); connect(n + 3, 2);
    for (int i = 1; i <= n; i++)
        connect(i + 2, n + 3 - i);
    for (int i = 1; i <= u; i++)
        connect(n + 2 + i, n + u + 3 - i);
    for (int i = 1; i <= n; i++)
        if (s[i] != '?')
        {
            if (i <= n - u)
                connect(i + 2, s[i] - '0' + 1);
            else if (s[i] == '0')
                connect(i + 2, i + u + 2);
        }
    add_edge(1, 2);
    for (int i = n - u + 1; i <= n; i++)
        if (s[i] == '1')
            add_edge(i + 2, i + u + 2);
    for (int i = 1; i <= n + u + 2; i++)
        if (dsu[i] < 0 && col[i] == -1)
        {
            if (DFS(i))
                (ans *= 2) %= MOD;
            else
                return 0;
        }
    return ans;
}

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i < n; i++)
        (ans += solve(i)) %= MOD;
    printf("%lld\n", ans);
}