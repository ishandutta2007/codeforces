#include <cstdio>
using namespace std;

const int Maxn = 55;

int n, a[Maxn];
int m, b[Maxn];
int mx = -1, cand = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (b[j] % a[i] == 0) {
                if (b[j] / a[i] > mx) { mx = b[j] / a[i]; cand = 0; }
                if (b[j] / a[i] == mx) cand++;
            }
    printf("%d\n", cand);
    return 0;
}