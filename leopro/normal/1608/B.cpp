#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define NO {cout << "-1\n"; return;}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    swap(a, b);
    set<int> ints;
    for (int i = 1; i <= n; ++i) ints.insert(i);
    auto min = [&]() {
        int x = *ints.begin();
        ints.erase(ints.begin());
        return x;
    };
    auto max = [&]() {
        int x = *--ints.end();
        ints.erase(--ints.end());
        return x;
    };
    if (a + b > n - 2) NO
    if (a + 1 == b) {
        for (int i = 0; i < b; ++i) {
            cout << min() << ' ' << max() << ' ';
        }
        while (ints.size()) cout << max() << ' ';
        cout << '\n';
    } else if (a == b) {
        for (int i = 0; i < a; ++i) {
            cout << min() << ' ' << max() << ' ';
        }
        cout << min() << ' ';
        while (ints.size()) cout << min() << ' ';
        cout << '\n';
    } else if (a == b + 1) {
        for (int i = 0; i < a; ++i) {
            cout << max() << ' ' << min() << ' ';
        }
        while (ints.size()) cout << min() << ' ';
        cout << '\n';
    } else NO
}