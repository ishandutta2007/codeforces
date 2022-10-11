#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    const ld PI = acosl(-1);
    vector<ld> x(n), y(n);
    for (int i = 0; i < n; i++) {
        ld alpha = 2 * PI * i / n;
        x[i] = cosl(alpha);
        y[i] = sinl(alpha);
    }

    vector<int> coprime;
    for (int i = 1; i <= n; i++) {
        if (gcd(n, i) == 1) coprime.push_back(i);
    }
    
    shuffle(all(coprime), mt19937(chrono::steady_clock::now().time_since_epoch().count()));
    for (auto m : coprime) {
        if (ld(clock()) / CLOCKS_PER_SEC > 0.8) break;
        ld sum_x = 0, sum_y = 0;
        for (int i = 0; i < n; i++) {
            sum_x += (s[i] - '0') * x[1ll * i * m % n];
            sum_y += (s[i] - '0') * y[1ll * i * m % n];
        }
        if (fabs(sum_x) > 1e-6 || fabs(sum_y) > 1e-6) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}