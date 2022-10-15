#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << endl; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    auto query = [&](int l, int r) -> bool {
        cout <<"? "<< l + 1 << ' ' << r << endl;
        int fromInside = 0;
        for (int i = l; i < r; ++i) {
            int x;
            cin >> x;
            fromInside += l + 1 <= x && x <= r;
        }
        return fromInside & 1;
    };
    auto solve = [&](auto solve, int l, int r) -> void {
        if (l + 1 == r) {
            cout << "! ";
            answer(l + 1);
        }
        int m = (l + r) / 2;
        if (query(l, m)) solve(solve, l, m); else solve(solve, m, r);
    };
    solve(solve, 0, n);
}