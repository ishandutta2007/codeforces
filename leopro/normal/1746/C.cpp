#ifdef LOCAL
  #define _GLIBCXX_DEBUG
#endif
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
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<int> deltas(n - 1);
    for (int i = 1; i < n; ++i) deltas[i - 1] = a[i] - a[i - 1];
    vector<int> ind(n - 1);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j) { return deltas[i] > deltas[j]; });
    cout << 1;
    for (int x: ind) cout << ' ' << x + 2;
    cout << '\n';
}