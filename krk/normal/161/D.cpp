#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;

const int Maxn = 50005;
const int Maxk = 505;

int n, k;
vector <int> neigh[Maxn];
ll ways[Maxn][Maxk];
ll res;

void Search(int v, int p)
{
    ways[v][0] = 1LL;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Search(u, v);
        for (int j = 0; j <= k; j++) res += ways[u][j] * ways[v][k - j];
        for (int j = 0; j <= k; j++) ways[v][j] += ways[u][j];
    }
    for (int j = k; j > 0; j--) ways[v][j] = ways[v][j - 1];
    ways[v][0] = 0;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b); neigh[b].push_back(a);
    }
    Search(1, 0);
    printf("%I64d\n", res);
    return 0;
}