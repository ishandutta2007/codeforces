#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, d, m;
long long a[100001], c[100001];

bool cmp(const long long &x, const long long &y) {
    return x > y;
}

int main() {
    scanf("%d%d%d", &n, &d, &m);
    ++d;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x <= m)
            a[++l] = x;
        else
            c[++r] = x;
    }
    sort(a + 1, a + l + 1, cmp);
    sort(c + 1, c + r + 1, cmp);
    for (int i = 1; i <= l; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= r; i++)
        c[i] += c[i - 1];
    long long ans = 0;
    for (int i = 0; i <= l; i++) {
        long long res = a[i];
        if (i != n) {
            int x = (n - i - 1) / d + 1;
            if (x <= r)
                res += c[x];
            else
                continue;
        }
        ans = max(ans, res);
    }
    printf("%lld\n", ans);
}