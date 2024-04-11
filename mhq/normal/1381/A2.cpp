#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
string a, b;
void solve() {
    cin >> n;
    cin >> a >> b;
    int cnt = 0;
    vector < int > ans;
    for (int i = n - 1; i >= 0; i--) {
        if (a[0] != b[i]) {
            ans.emplace_back(i + 1);
        }
        else {
            ans.emplace_back(1);
            ans.emplace_back(i + 1);
        }
        if (cnt % 2 == 0) {
            a[0] = ('0' + '1' - a[n - 1 - cnt / 2]);
        }
        else {
            a[0] = a[(cnt + 1) / 2];
        }
        cnt++;
    }
    cout << ans.size() << " ";
    for (int v : ans) cout << v << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while(tst--) {
        solve();
    }
    return 0;
}