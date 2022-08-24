#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 5005;
string s;
void solve() {
    cin >> n;
    cin >> s;
    string best = s;
    int k = 1;
    for (int i = 2; i <= n; i++) {
        string f;
        for (int j = i; j <= n; j++) {
            f += s[j - 1];
        }
        string g = s.substr(0, i - 1);
        if ((n - i) % 2 == 0) reverse(g.begin(), g.end());
        f += g;
        if (f < best) {
            k = i;
            best = f;
        }
    }
    cout << best << "\n" << k << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}