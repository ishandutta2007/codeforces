#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n);
        ll cur = 0;
        ld res = -1e20l;
        for (int i = 0; i + 1 < n; i++) {
            cur += a[i];
            res = max(res, cur / ld(i + 1) + (sum - cur) / ld(n - i - 1));
        }
        cout << fixed << setprecision(10) << res << "\n";
    }
    return 0;
}