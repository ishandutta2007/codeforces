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
    int n, z;
    cin >>n >> z;
    vector<int> a(n);
    for (int &x: a) cin >> x, x |= z;
    cout << *max_element(a.begin(), a.end()) << '\n';
}