#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll a[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    int h = 1;
    while (1 + h <= n) h *= 2;
    for (int i = 1; i < n; i++) {
        while (i + h > n) h /= 2;
        res += a[i]; a[i + h] += a[i];
        printf("%I64d\n", res);
    }
    return 0;
}