#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll a[Maxn];
ll bl[Maxn], br[Maxn], fl[Maxn], fr[Maxn];
ll mx;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) scanf("%I64d", &a[i]);
    for (int i = 1; i < n; i++)
        if (a[i - 1] >= 2) bl[i] = bl[i - 1] + a[i - 1] / 2LL * 2LL;
    for (int i = n - 2; i >= 0; i--)
        if (a[i] >= 2) br[i] = br[i + 1] + a[i] / 2LL * 2LL;
    for (int i = 1; i < n; i++) {
        fl[i] = a[i - 1];
        if (a[i - 1] >= 1) fl[i] = max(fl[i], fl[i - 1] + (a[i - 1] - 1LL) / 2LL * 2LL + 1LL);
        if (a[i - 1] >= 1) fl[i] = max(fl[i], bl[i - 1] + a[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        fr[i] = a[i];
        if (a[i] >= 1) fr[i] = max(fr[i], fr[i + 1] + (a[i] - 1LL) / 2LL * 2LL + 1LL);
        if (a[i] >= 1) fr[i] = max(fr[i], br[i + 1] + a[i]);
    }
    for (int i = 0; i < n; i++)
        mx = max(mx, max(bl[i] + fr[i], br[i] + fl[i]));
    printf("%I64d\n", mx);
    return 0;
}