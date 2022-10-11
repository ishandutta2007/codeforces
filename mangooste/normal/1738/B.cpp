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

void solve(int test_num) {
    int n, k;
    cin >> n >> k;
    vector<ll> p(n);
    const int start = n - k;
    for (int i = start; i < n; i++) cin >> p[i];

    cout << ([&]() -> bool {
        for (int i = start + 1; i + 1 < n; i++) {
            ll first = p[i] - p[i - 1];
            ll second = p[i + 1] - p[i];
            if (first > second) return false;
        }
        if (n == 1 || k == 1) return true;
        if (k == n) return p[0] <= p[1] - p[0];

        int left = n - k + 1;
        ll largest = p[start + 1] - p[start];
        ll sum = p[start];

        constexpr ll INF = 2e9;
        largest += INF;
        sum += INF * left;
        return (sum + left - 1) / left <= largest;
    }() ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}