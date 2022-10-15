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
    int n;cin>>n;vector<int> a(n);for (int &x : a) cin >> x;
    set<int> d;
    for (int &x : a) {
        if (d.find(x) != d.end()) d.insert(-x); else d.insert(x);
    }
    cout << d.size() << '\n';
}