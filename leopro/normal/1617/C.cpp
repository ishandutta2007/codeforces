#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
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
    vector<int> rest;
    vector<bool> seen(n + 1);
    for (int x: a) {
        if (x > n || seen[x]) {
            rest.push_back(x);
        } else {
            seen[x] = true;
        }
    }
    sort(rest.begin(), rest.end());
    for (int i = 0, j = 1; i < rest.size(); ++i, ++j) {
        while (seen[j]) j++;
        if (rest[i] <= 2 * j) {
            cout << "-1\n";
            return;
        }
    }
    cout << rest.size() << '\n';
}