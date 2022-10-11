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
    if (n == 4) {
        cout << "2 1 3 4\n";
        return;
    }

    auto solve = [&](int x) {
        ll sum = x;
        while (sum < n) {
            if (2 * sum + 1 < n) {
                sum = 2 * sum + 1;
            } else {
                sum += n;
                break;
            }
        }
        return sum;
    };

    int best = 1;
    for (int i = 1; i <= n; i++) {
        if (solve(best) < solve(i)) best = i;
    }

    vector<int> perm;
    vector<bool> used(n + 1);
    int sum = best;
    used[best] = true;
    perm.push_back(best);
    while (sum < n) {
        if (2 * sum + 1 < n) {
            used[sum + 1] = true;
            perm.push_back(sum + 1);
            sum = 2 * sum + 1;
        } else {
            used[n] = true;
            perm.push_back(n);
            sum += n;
            break;
        }
    }

    dbg(best, solve(best));

    vector<int> left;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) left.push_back(i);
    }
    reverse(all(left));
    if (len(left) % 2) {
        assert(len(left) > 1);
        swap(left[0], left[1]);
    }

    for (auto x : left) cout << x << ' ';
    for (auto x : perm) cout << x << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}