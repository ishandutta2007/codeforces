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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    ll sum = accumulate(all(a), 0ll);
    vector<ll> fib{1};
    sum--;
    if (sum) {
        fib.push_back(1);
        sum--;
    }
    while (sum > 0) {
        fib.push_back(fib.end()[-2] + fib.end()[-1]);
        sum -= fib.back();
    }
    if (sum) {
        cout << "No\n";
        return;
    }

    reverse(all(fib));
    int last = -1;
    for (auto x : fib) {
        int best = -1;
        for (int i = 0; i < n; i++) {
            if (i == last) continue;
            if (best == -1 || a[best] < a[i]) best = i;
        }
        if (best == -1 || a[best] < x) {
            cout << "No\n";
            return;
        }

        a[best] -= x;
        last = best;
    }
    cout << "Yes\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}