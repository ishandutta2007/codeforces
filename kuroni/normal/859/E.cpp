#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int i, n, u, v, r[200005], t[200005];
long long ans = 1;
bool self[200005];
vector <pair <int, int>> e;

int trace(int u)
{
    return r[u] < 0 ? u : r[u] = trace(r[u]);
}

void unity(int u, int v)
{
    if ((u = trace(u)) == (v = trace(v)))
        return;
    if (r[u] > r[v])
        swap(u, v);
    r[u] += r[v];
    r[v] = u;
}

int main()
{
    memset(r, -1, sizeof(r));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        unity(u, v);
        e.push_back(make_pair(u, v));
    }
    for (i = 0; i < n; i++)
    {
        if (e[i].first == e[i].second)
            self[trace(e[i].first)] = true;
        t[trace(e[i].first)]++;
    }
    for (i = 1; i <= 2 * n; i++)
        if (r[i] < 0)
        {
            if (t[i] < -r[i])
                ans *= -r[i];
            else if (t[i] == -r[i]) ans *= (2 - self[i]);
            else ans = 0;
            ans %= 1000000007;
        }
    printf("%I64d", ans);
}