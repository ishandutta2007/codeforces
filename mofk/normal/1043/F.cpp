#include <bits/stdc++.h>

using namespace std;

int n;
int p[300005];
long long a[300005];
int b[300005];
long long c[300005];

int _norm(int x) {
    int r = 1;
    while (x > 1) {
        int d = p[x];
        r *= d;
        while (x % d == 0) x /= d;
    }
    return r;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 300000; ++i) p[i] = i;
    for (int i = 2; i <= 300000; ++i) if (p[i] == i) for (int j = i * 2; j <= 300000; j += i) p[j] = i;
    cin >> n;
    long long d = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = _norm(a[i]);
        d = __gcd(d, a[i]);
    }
    if (d > 1) return cout << -1 << endl, 0;
    for (int i = 1; i <= n; ++i) b[a[i]] = 1;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= 300000; ++i) for (int j = i; j <= 300000; j += i) a[i] += b[j];
    int ans = 1;
    while (!b[1]) {
        ++ans;
        memset(c, 0, sizeof c);
        for (int i = 1; i <= 300000; ++i) for (int j = i; j <= 300000; j += i) c[i] += b[j];
        for (int i = 1; i <= 300000; ++i) c[i] *= a[i];
        for (int i = 2; i <= 300000; ++i) if (p[i] == i) for (int j = i; j <= 300000; j += i) c[j / i] -= c[j];
        for (int i = 1; i <= 300000; ++i) b[i] = !!c[i];
    }
    cout << ans << endl;
    return 0;
}