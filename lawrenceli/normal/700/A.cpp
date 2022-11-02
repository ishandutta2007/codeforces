#include <bits/stdc++.h>

using namespace std;

typedef double ld;

const ld eps = 1e-7;

int n, l, v1, v2, k;

bool check(ld mt) {
    ld b = (ld(l) / v1 - mt) / (ld(1) / v1 - ld(1) / v2);
    ld tb = b / v2;
    ld d = 0, t = 0;
    for (int i = 0; i < n; i++) {
        d += b, t += tb;
        if (d > l) return 0;
        ld d1 = t * v1;
        d = d1 + ld(v1) / (v1 + v2) * (d - d1);
        t = d / v1;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> l >> v1 >> v2 >> k;
    n = (n - 1) / k + 1;

    ld lo = 0, hi = 1e9;
    while (hi - lo > eps) {
        ld mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + eps;
    }

    cout << fixed << setprecision(15) << (lo + hi) / 2 << '\n';
}