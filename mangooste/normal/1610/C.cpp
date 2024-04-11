#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
        cin >> right[i] >> left[i];

    auto check = [&](int value) {
        int take = 0;
        for (int i = 0; i < n && take < value; i++)
            if (left[i] >= take && value - take - 1 <= right[i])
                take++;

        return take == value;
    };

    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (check(mid) ? l : r) = mid;
    }

    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}