#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007LL;
const int Maxn = 2005;

int n, m, k;
bool taken[Maxn];
int comp;

void DFS(int v)
{
    if (taken[v]) return;
    taken[v] = true;
    for (int i = 1; i <= k + 1; i++) if (0 <= v - i + 1 && v - i + k < n) {
        int u = v - 2 * i + k + 1;
        if (0 <= u && u < n) DFS(u);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) if (!taken[i]) {
        DFS(i);
        comp++;
    }
    int res = 1;
    while (comp--) res = ll(res) * ll(m) % ll(mod);
    printf("%d\n", res);
    return 0;
}