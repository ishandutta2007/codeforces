#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    cout << [&] {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (3 + 3 + 3 * m <= n) l = m; else r = m;
        }
        return l;
    }() << '\n';
}