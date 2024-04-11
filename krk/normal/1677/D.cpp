#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 1000006;

int T;
int n, k;
int a[Maxn];
int lef[Maxn], rig[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            lef[i] = 0;
            rig[i] = i;
        }
        int res = 1;
        for (int i = 0; i < n; i++)
            if (a[i] == 0) {
                if (i + k < n)
                    rig[i + k] = min(rig[i + k], k);
            } else if (a[i] > 0)
                if (i + k >= n) res = 0;
                else {
                    lef[i + k] = max(lef[i + k], a[i] + k);
                    rig[i + k] = min(rig[i + k], a[i] + k);
                }
        for (int i = 0; i < n; i++)
            if (lef[i] > rig[i]) res = 0;
            else res = ll(res) * (rig[i] - lef[i] + 1) % mod;
        printf("%d\n", res);
    }
    return 0;
}