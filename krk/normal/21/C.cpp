#include <cstdio>
using namespace std;

const int Maxn = 100001;

typedef long long ll;

int n, sums[Maxn], part;
ll was, ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sums[i]);
        if (i) sums[i] += sums[i-1];
    }
    if (sums[n-1] % 3) { printf("0\n"); return 0; }
    part = sums[n-1] / 3;
    for (int i = 0; i < n-1; i++) {
        if (sums[i] == 2 * part) ans += was;
        if (sums[i] == part) was++;
    }
    printf("%I64d\n", ans);
    return 0;
}