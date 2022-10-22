#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
ll k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %I64d", &n, &k);
        ll lv = -k;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            lv += a[i];
        }
        if (lv <= 0) { printf("0\n"); continue; }
        sort(a, a + n);
        ll res = lv;
        for (int i = 1; i < n; i++) {
            lv -= (a[n - i] - a[0]);
            ll tk;
            if (lv <= 0) tk = 0;
            else tk = (lv - 1) / (i + 1) + 1;
            res = min(res, ll(i) + tk);
        }
        printf("%I64d\n", res);
    }
    return 0;
}