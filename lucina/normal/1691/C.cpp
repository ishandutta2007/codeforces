#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
string s;

void solve() {
    cin >> n >> k >> s;

    int ans = 0;
    vector <int> where;
    for (int i = 1 ; i + 1 < n ; ++ i) {
        if (s[i] == '1') ans += 11, where.push_back(i);
    }
    if (s[0] == '1') ans += 10;
    if (s.back() == '1') ans += 1;

    if (where.empty()) {
        if (s[0] == '1' && s.back() == '0' && n - 1 <= k) ans = 1;
        cout << ans << '\n';
        return;
    }
    if (n - 1 - where.back() <= k && s.back() == '0') {
        k -= n - 1 - where.back();
        ans -= 11;
        ans += 1;
        where.pop_back();
    }
    if (where.empty()) {
        cout << ans << '\n';
        return;
    }
    if (where[0] <= k && s[0] == '0') {
        ans -= 1;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}