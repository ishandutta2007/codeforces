#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll k;
int a[Maxn];
int r1, r2;

int main()
{
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    r1 = a[(k - 1LL) / ll(n)];
    int l = lower_bound(a, a + n, r1) - a;
    k -= ll(l) * ll(n);
    int r = upper_bound(a, a + n, r1) - a;
    r2 = a[(k - 1LL) / ll(r - l)];
    printf("%d %d\n", r1, r2);
    return 0;
}