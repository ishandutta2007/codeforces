#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int t;
int n, s;
ll a[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &s);
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            a[i] += a[i - 1];
        }
        int res = upper_bound(a, a + n + 1, ll(s)) - a - 1;
        int bi = 0;
        for (int i = 1; i <= n; i++) {
            int cand = upper_bound(a, a + n + 1, ll(s) + (a[i] - a[i - 1])) - a - 1;
            if (i <= cand && cand > res) {
                res = cand; bi = i;
            }
        }
        printf("%d\n", bi);
    }
    return 0;
}