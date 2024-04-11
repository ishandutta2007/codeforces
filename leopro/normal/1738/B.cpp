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
    int n, k;
    cin >> n >> k;
    vector<ll> s(k);
    for (auto &x : s) cin >> x;
    vector<ll> deltas(k - 1);
    for (int i = 0; i + 1 < k; ++i) deltas[i] = s[i + 1] - s[i];
    for (int i = 0; i + 1 < deltas.size(); ++i) if (deltas[i + 1] < deltas[i]) answer("NO");
    if (k == 1) answer("YES");
    ll min = deltas[0];
    answer(min * (n - k + 1) >= s[0] ? "YES" : "NO");
}