#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int m;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); a[i] += a[i - 1];
    }
    scanf("%d", &m);
    while (m--) {
        int q; scanf("%d", &q);
        int ind = lower_bound(a + 1, a + n + 1, q) - a;
        printf("%d\n", ind);
    }
    return 0;
}