// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
const int N = (int) 505 * 100 * 100, mod = (int) 0, inf = 1e9;
int in, out, parent[1010], d[1010], przeplyw, en, to[N], cost[N], cap[N];
vector <int> v[1010];
bool in_queue[1010];
#define ui int
#define pb push_back
void add_edge(int x, int y, int ile, int cena)
{
    cap[en] = ile;
    cost[en] = cena;
    to[en] = y;
    v[x].pb(en++);
    cost[en] = -cena;
    to[en] = x;
    v[y].pb(en++);
}
void SPFA(int vertex)
{
    queue <int> q;
    while (!q.empty()) q.pop();
    q.push(vertex);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        in_queue[x] = false;
        for (ui i=0; i<v[x].size(); ++i)
        {
            int e = v[x][i], u = to[e];
            if (cap[e] > 0 && d[x] + cost[e] < d[u])
            {
                d[u] = d[x] + cost[e];
                parent[u] = e;
                if (in_queue[u] == false)
                {
                    in_queue[u] = 1;
                    q.push(u);
                }
            }
        }
    }
}

int MaxFlowMinCost(int IN, int OUT)
{
    int wyn = 0;
    int N = OUT + 2;
    while (1)
    {
        for (int i=0; i<=N; ++i) d[i] = inf, parent[i] = -1, in_queue[i] = 0;
        d[IN] = parent[IN] = 0;
        SPFA(IN);
        if (d[OUT] == inf) return wyn;
        int bottle = inf, x = OUT;
        while (x != IN)
        {
            bottle = min(bottle, cap[parent[x]]);
            x = to[parent[x] ^ 1];
        }

        x = OUT;
        while (x != IN)
        {
            wyn += (cost[parent[x]] * bottle);
            cap[parent[x]] -= bottle;
            cap[parent[x] ^ 1] += bottle;
            x = to[parent[x] ^ 1];
        }
        przeplyw += bottle;
    }
    return 0;
}
string s, t[N];
int p[N], best[1010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin >> s;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> t[i] >> p[i];
    int x;
    cin >> x;
    in = n + 2;
    out = n;
    add_edge(in, 0, x, 0);
    for (int i = 0; i < n; ++i) {
        if (i + 1 != n) add_edge(i, i + 1, x, 0);
    }
    add_edge(n - 1, out, x, 0);
    for (int i = 0; i < n; ++i) {
        memset(best, 0, sizeof best);
        for (int j = 0; j < m; ++j)
            if (t[j].size() + i <= n) {
                int ok = 1;
                for (int k = i; k < i + t[j].size(); ++k)
                    ok &= (t[j][k - i] == s[k]);
                if (ok)
                    add_edge(i, i + t[j].size(), 1, -p[j]);
//                    best[i + t[j].size()] = max(best[i + t[j].size()], p[j]);
            }
//        for (int j = 0; j <= n; ++j)
  //          if (best[j])
    //            add_edge(i, j, 1, -best[j]);
    }
    cout << -MaxFlowMinCost(in, out);


}