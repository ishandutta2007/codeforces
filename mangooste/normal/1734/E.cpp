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
    #define dprint(...)
#endif // LOCAL

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> diag(n);
    for (auto &x : diag) cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ((1ll * i * j + diag[i] - 1ll * i * i) % n + n) % n << " \n"[j == n - 1];
        }
    }
}