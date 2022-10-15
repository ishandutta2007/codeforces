#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

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
    vector<int> a(n);
    for (int &x: a) cin >> x;
    while (a.size() && a.back() == 0) a.pop_back();
    reverse(a.begin(), a.end());
    while (a.size() && a.back() == 0) a.pop_back();
    if (a.empty()) cout << 0 << '\n';
    else if (find(a.begin(), a.end(), 0) == a.end()) cout << 1 << '\n'; else cout << 2 << '\n';
}