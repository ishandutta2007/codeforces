#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout <<  (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

int n;

int query(int x) {
    cout << "+ " << x << ' ' << flush;
    int y;
    cin >> y;
    return y;
}

void solve() {
    cin >> n;
    int l = 1, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int add = n - m % n;
        l += add, r += add, m += add;
        if (query(add) == l / n) r = m; else l = m;
    }
    cout << "! " << l << '\n';
}