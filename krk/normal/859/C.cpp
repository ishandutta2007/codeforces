#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 52;

int n;
int a[Maxn], sum[Maxn], best[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); sum[i] = a[i] + sum[i - 1];
    }
    best[n + 1] = 0;
    for (int i = n; i > 0; i--)
        best[i] = max(a[i] + sum[n] - sum[i] - best[i + 1], best[i + 1]);
    printf("%d %d\n", sum[n] - best[1], best[1]);
    return 0;
}