#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;

int n;
vector <int> neigh[Maxn], rneigh[Maxn];
bool inloop[Maxn];
int dist[Maxn];
int tk[Maxn];
int res = 1;

void Traverse(int v, int p)
{
    if (tk[v] == 2) return;
    if (tk[v] == 1) {
        if (v != p) res = res * 2 % mod;
        inloop[v] = true; return;
    }
    tk[v] = 1;
    dist[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Traverse(u, v);
        inloop[v] |= inloop[u];
        dist[v] = max(dist[v], dist[u] + 1);
    }
    //printf("v = %d, l = %d, d = %d\n", v, inloop[v], dist[v]);
    tk[v] = 2;
}

int Solve(int v)
{
    int res = 1;
    for (int i = 0; i < rneigh[v].size(); i++)
        res += Solve(rneigh[v][i]);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        rneigh[b].push_back(a);
    }
    for (int i = 1; i <= 2 * n; i++)
        if (!tk[i]) Traverse(i, 0);
    for (int i = 1; i <= 2 * n; i++) if (!inloop[i] && neigh[i].size() == 0)
        res = ll(res) * Solve(i) % mod;
    printf("%d\n", res);
    return 0;
}