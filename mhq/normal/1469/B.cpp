#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n;
        vector<int> r(n);
        for (int& c : r) cin >> c;
        cin >> m;
        vector<int> b(m);
        for (int& c : b) cin >> c;
        int mx = 0;
        vector<int> prefa(n + 1), prefb(m + 1);
        for (int i = 1; i <= n; i++) prefa[i] = prefa[i - 1] + r[i - 1];
        for (int i = 1; i <= m; i++) prefb[i] = prefb[i - 1] + b[i - 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                mx = max(mx, prefa[i] + prefb[j]);
            }
        }
        cout << mx << '\n';
    }
    return 0;
}