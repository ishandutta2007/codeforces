#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a, b;
    cin >> a >> b;
    if (a > b) {
        a = n + 1 - a;
        b = n + 1 - b;
    }
    vector<int> s(m);
    for (int& v : s) cin >> v;
    sort(s.begin(), s.end());
    int best = 0;
    int mx = 0;
    for (int i = 0; i < s.size(); i++) {
        mx = max(mx, s[i] - (i + 1));
        if (i + 3 + mx <= b && i + 1 <= b - a - 1) best = max(best, i + 1);
    }
    cout << best << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}