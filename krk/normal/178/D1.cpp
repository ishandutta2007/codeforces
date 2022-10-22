#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int Maxn = 9;

int n;
int a[Maxn];
int sum;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) { scanf("%d", &a[i]); sum += a[i]; }
    sum /= n;
    sort(a, a + n * n);
    do {
        int i, j;
        for (i = 0; i < n; i++) {
            int cand = 0;
            for (j = 0; j < n; j++) cand += a[i + j * n];
            if (cand != sum) break;
        }
        if (i < n) continue;
        for (i = 0; i < n; i++) {
            int cand = 0;
            for (j = 0; j < n; j++) cand += a[n * i + j];
            if (cand != sum) break;
        }
        if (i < n) continue;
        int cand = 0;
        for (i = 0; i < n * n; i += n + 1) cand += a[i];
        if (cand != sum) continue;
        cand = 0;
        for (i = 1; i <= n; i++) cand += a[i * (n - 1)];
        if (cand != sum) continue;
        break;
    } while (next_permutation(a, a + n * n));
    printf("%d\n", sum);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) printf("%d%c", a[n * i + j], (j + 1 < n)? ' ': '\n');
    return 0;
}