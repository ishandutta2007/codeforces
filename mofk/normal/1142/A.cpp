#include <bits/stdc++.h>

using namespace std;

int n, k, a, b;
long long p;
long long mn, mx;

void work(int r1, int r2) {
    if (r1 > r2) swap(r1, r2);
    long long d = r2 - r1;
    for (int i = 0; i < n; ++i) {
        long long f = __gcd(d, p);
        mn = min(mn, f);
        mx = max(mx, f);
        d += k;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> a >> b;
    p = 1ll * n * k;
    mx = -1, mn = p + 1;
    work(a, b);
    work(k - a, b);
    work(a, k - b);
    work(k - a, k - b);
    cout << p / mx << ' ' << p / mn << endl;
    return 0;
}