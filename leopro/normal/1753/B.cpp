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
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &y: a) cin >> y;
    map<int, int> cnt;
    for (int y: a) cnt[y]++;
    for (int i = 1; i < x; ++i) {
        if (cnt.count(i) == 0) continue;
        if (cnt[i] % (i + 1) == 0) cnt[i + 1] += cnt[i] / (i + 1); else answer("No");
    }
    answer("Yes")
}