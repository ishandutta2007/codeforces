#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Inf = 1000000000;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;

int n, m;
vector <int> neigh[Maxn];
int k;
int a[Maxn];
int dist[Maxn];
ii ways[Maxn];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void Solve(int v)
{
    fill(dist, dist + n + 1, Inf); dist[v] = 0; ways[v] = ii(1, 1);
    vector <int> Q; Q.push_back(v);
    for (int i = 0; i < Q.size(); i++) {
        v = Q[i];
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1; ways[u] = ii(0, 0);
                Q.push_back(u);
            }
            if (dist[v] + 1 == dist[u]) {
                ways[u].first = (ways[u].first + ways[v].first) % mod1;
                ways[u].second = (ways[u].second + ways[v].second) % mod2;
            }
        }
    }
}

int main()
{
    mod1 = uniform_int_distribution<int>(500000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(500000000, 1000000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[b].push_back(a);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
        scanf("%d", &a[i]);
    Solve(a[k - 1]);
    int mn = 0, mx = 0;
    for (int i = 0; i + 1 < k; i++)
        if (dist[a[i]] != dist[a[i + 1]] + 1) { mn++; mx++; }
        else if (ways[a[i]] != ways[a[i + 1]]) mx++;
    printf("%d %d\n", mn, mx);
    return 0;
}