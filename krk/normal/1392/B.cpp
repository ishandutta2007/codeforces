#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Inf = 2000000007;

int T;
int n;
ll k;
ll a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %I64d", &n, &k);
        ll mx = -Inf;
        for (int i = 0; i < n; i++) {
            scanf("%I64d", &a[i]);
            mx = max(mx, a[i]);
        }
        for (int i = 0; i < n; i++)
            a[i] = mx - a[i];
        k--;
        if (k % 2) {
            mx = -Inf;
            for (int i = 0; i < n; i++)
                mx = max(mx, a[i]);
            for (int i = 0; i < n; i++)
                a[i] = mx - a[i];
        }
        for (int i = 0; i < n; i++)
            printf("%I64d%c", a[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}