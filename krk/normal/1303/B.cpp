#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = 4000000000000000000ll;

int T;
int n, g, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &g, &b);
        ll lef = 0, rig = lim;
        while (lef <= rig) {
            ll mid = lef + rig >> 1ll;
            ll timsg = mid / (g + b) * g + min(ll(g), mid % (g + b));
            ll timsb = mid / (g + b) * b + max(0ll, mid % (g + b) - g);
            if (timsg + min(ll(n) / 2, timsb) >= n) rig = mid - 1;
            else lef = mid + 1;
        }
        printf("%I64d\n", rig + 1ll);
    }
    return 0;
}