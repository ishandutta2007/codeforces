#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e6 + 5;

int n, a[N];

LL s, ans = 9e18;

LL inline calc(LL P) {
    LL v = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        v = (v + a[i]) % P;
        res += min(v, P - v);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), s += a[i];
    if (s == 1) {
        puts("-1");
        return 0;
    }
    for (LL i = 2; i * i <= s; i++) {
        if (s % i == 0) {
            ans = min(ans, calc(i));
            while (s % i == 0) s /= i;
        }
    }
    if (s > 1) ans = min(ans, calc(s));
    printf("%lld\n", ans);
    return 0;
}