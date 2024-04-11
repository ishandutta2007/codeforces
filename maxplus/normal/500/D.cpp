#include <iostream>
#include <utility>
#include <vector>
#define N 100002
#define f first
#define s second

using namespace std;

struct edge{
    int f, s, t;
};

vector<edge> edg;
vector<pair<int, int>> nei[N];
int u[N], n, a, b, c, q, l;
int64_t vc[N];

void dfs(int a)
{
    u[a] = 1;
    for (auto i: nei[a]) if (!u[i.f])
    {
        dfs(i.f);
        vc[a] += vc[i.f];
    }
    vc[a]++;
}

int64_t sl()
{
    int64_t ans = 0;
    for (int i = 0; i < n; ++i)
        for (auto j: nei[i]) if (vc[i] > vc[j.f])
            ans += vc[j.f] * (n - vc[j.f]) * j.s;
    return ans;
}

int main()
{
    cin.tie(0), ios_base::sync_with_stdio(0), cout.precision(7), cout << fixed;
    cin >> n;
    edg.push_back({0,0,0});
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b >> c;
        nei[--a].push_back({--b, c});
        nei[b].push_back({a, c});
        edg.push_back({a, b, c});
    }
    cin >> q;
    dfs(0);
    int64_t ans = sl();
    while (q--)
    {
        cin >> a >> l;
        if (vc[edg[a].f] < vc[edg[a].s])
            c = edg[a].t, edg[a].t = l, b = edg[a].f, a = edg[a].s;
        else
            c = edg[a].t, edg[a].t = l, b = edg[a].s, a = edg[a].f;
        cout << (ans += vc[b] * (n - vc[b]) * (l - c)) * (long double)6 / n / (n - 1) << '\n';
    }
    return 0;
}