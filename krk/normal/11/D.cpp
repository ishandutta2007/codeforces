#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 19;

int n, m;
vector <int> neigh[Maxn];
ll ways[1 << Maxn][Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        neigh[a].push_back(b); neigh[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        fill((ll*)ways, (ll*)ways + (1 << n) * Maxn, 0); ways[1 << i][i] = 1;
        for (int mask = 1; mask < 1 << n; mask++)
            for (int j = 0; j < n; j++) if (ways[mask][j]) {
                int bits = 0;
                for (int l = 0; l < n; l++) if (mask & 1 << l) bits++;
                for (int l = 0; l < neigh[j].size(); l++) {
                    int u = neigh[j][l];
                    if (u == i && bits > 2) res += ways[mask][j];
                    if (u > i && !(mask & 1 << u)) ways[mask | 1 << u][u] += ways[mask][j];
                }
            }
    }
    printf("%I64d\n", res / 2LL);
    return 0;
}