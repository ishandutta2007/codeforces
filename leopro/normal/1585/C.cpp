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

void solve() {
    int n, k;
    cin >> n>>k;
    vector<int> x(n);
    for (int &x: x) cin >> x;
    vector<int> p{0}, m{0};
    for (int x : x) if (x > 0) p.push_back(x); else m.push_back(-x);
    int mn = max(*max_element(p.begin(), p.end()), *max_element(m.begin(), m.end()));
    sort(p.begin(), p.end());
    sort(m.begin(), m.end());
    ll s = 0;
    for (int i = m.size() - 1; i >= 0; i -= k) {
        s += 2 * m[i];
    }
    for (int i = p.size() - 1; i >= 0; i -= k) {
        s += 2 * p[i];
    }
    cout << s - mn << '\n';
}