#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, a[Maxn];
int sum;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); sum += a[i];
    }
    sort(a, a + n);
    int cur = 0;
    while (2 * cur <= sum)
        cur += a[n - 1 - res++];
    printf("%d\n", res);
    return 0;
}