#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        bool ok = true;
        for (int i = 0; i < m - 1; i++) {
            if (a[n - i - 1] != b[m - i - 1]) {
                ok = false;
            }
        }
        bool has = false;
        for (int t = 0; t <= n - m; t++) {
            if (a[t] == b[0]) has = true;
        }
        if (!has) ok = false;
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}