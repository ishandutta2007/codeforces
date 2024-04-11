//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d, h;
    cin >> n >> d >> h;
    if (h * 2 < d || (d == 1 && n > 2)) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= h; ++i) {
        cout << i << ' ' << i + 1 << '\n';
    }
    int kek = d - h;
    if (kek) {
        cout << "1 " << h + 2 << '\n';
        for (int i = h + 2; kek > 1; --kek, ++i) {
            cout << i << ' ' << i + 1 << '\n';
        }
    }
    if (d == h) {
        for (int i = d + 2; i <= n; ++i) {
            cout << 2 << ' ' << i << '\n';
        }
    } else {
        for (int i = d + 2; i <= n; ++i) {
            cout << 1 << ' ' << i << '\n';
        }
    }
    return 0;
}