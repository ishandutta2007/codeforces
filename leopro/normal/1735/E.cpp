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
    vector<int> d1(n), d2(n);
    for (int &x: d1) cin >> x;
    for (int &x: d2) cin >> x;
    map<int, int> c1, c2;
    for (int x: d1) c1[x]++;
    for (int x: d2) c2[x]++;
    auto ok = [&](int d) -> bool {
        vector<int> p;
        auto b1 = c1, b2 = c2;
        while (!b1.empty()) {
            auto[x, cnt] = *--b1.end();
            b1.erase(--b1.end());
            int u = b2[x + d];
            if (u > cnt) return false;
            b2[x + d] -= u;
            if (b2[abs(x - d)] < cnt - u) return false;
            for (int i = 0; i < u; ++i) p.push_back(x + d);
            b2[abs(x - d)] -= cnt - u;
            for (int i = 0; i < cnt - u; ++i) p.push_back(d - x);
        }
        int mn = min(0, *min_element(p.begin(), p.end()));
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) cout << p[i] - mn << ' ';
        cout << '\n';
        cout << d - mn << ' ' << -mn << '\n';
        return true;
    };
    for (int x: d1) {
        if (ok(abs(x - d2[0]))) return;
    }
    for (int x: d1) {
        if (ok(x + d2[0])) return;
    }
    cout << "NO\n";
}