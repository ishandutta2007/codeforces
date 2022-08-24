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
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        vector<int> ans(n);
        ans[0] = a[0];
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] != ans[i - 1]) ans[i] = a[i];
            else ans[i] = b[i];
        }
        for (int x : {a[n - 1], b[n - 1], c[n - 1]}) {
            if (x != ans[0] && x != ans[n - 2]) {
                ans[n - 1] = x;
                break;
            }
        }
        for (int& c : ans) cout << c << " ";
        cout << '\n';
    }
    return 0;
}