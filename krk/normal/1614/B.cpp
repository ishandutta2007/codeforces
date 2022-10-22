#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
ii a[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        res[0] = 0;
        int cur = -1;
        ll ans = 0;
        for (int i = n; i > 0; i--) {
            int ind = a[i].second;
            res[ind] = cur;
            ans += ll(a[i].first) * abs(cur);
            if (cur < 0) cur = -cur;
            else {
                cur = -cur;
                cur--;
            }
        }
        printf("%I64d\n", 2ll * ans);
        for (int i = 0; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}