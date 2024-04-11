#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll k;
ll a[Maxn];
int best = 0;
int res;

int main()
{
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
    sort(a, a + n);
    int l = 0;
    ll taken = 0;
    for (int i = 0; i < n; i++) {
        if (i) taken += ll(i - l) * ll(a[i] - a[i - 1]);
        while (taken > k) { taken -= a[i] - a[l]; l++; }
        if (i - l + 1 > best) {
            best = i - l + 1;
            res = a[i];
        }
    }
    printf("%d %d\n", best, res);
    return 0;
}