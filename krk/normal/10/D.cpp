#include <cstdio>
using namespace std;

const int Maxn = 505;

int n, m;
int a[Maxn], b[Maxn];
int best[Maxn], p[Maxn][Maxn];

void Print(int ind, int k)
{
    if (p[ind][k] != -1) { Print(p[ind][k], k - 1); printf(" "); }
    printf("%d", b[ind]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) {
        int val = 0, ind = -1;
        for (int j = 0; j < m; j++)
            if (a[i] == b[j] && val + 1 > best[j]) {
                best[j] = val + 1; p[j][best[j]] = ind;
            } else if (b[j] < a[i] && best[j] > val) {
                val = best[j]; ind = j;
            }
    }
    int bi = 0;
    for (int i = 1; i < m; i++) if (best[i] > best[bi]) bi = i;
    printf("%d\n", best[bi]);
    if (best[bi]) Print(bi, best[bi]);
    printf("\n");
    return 0;
}