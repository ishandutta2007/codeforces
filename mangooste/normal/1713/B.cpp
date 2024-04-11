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

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int pref = 0;
    while (pref < n - 1 && a[pref + 1] >= a[pref]) pref++;
    int suf = n - 1;
    while (suf > 0 && a[suf - 1] >= a[suf]) suf--;
    cout << (pref >= suf ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}