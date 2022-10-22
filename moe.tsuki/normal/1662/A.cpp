#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        map<int, int> m;
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x,y;cin >> x >> y;
            m[y] = max(m[y], x);
        }
        if (m.size() < 10) {
            cout << "MOREPROBLEMS\n";
        } else {
            int64_t s = 0;
            for (auto [_, x] : m) s += x;
            cout << s << '\n';
        }
    }
    return 0;
}