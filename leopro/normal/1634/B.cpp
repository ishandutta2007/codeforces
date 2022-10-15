#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

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
    int n, x;ll y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int s = accumulate(a.begin(), a.end(), 0, [](int x, int y) { return (x + y) % 2; });
    if ((x + y) % 2 == s) answer("Alice");
    answer("Bob");
}