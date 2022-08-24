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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        int c = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (i > 0 && v[i] != v[i - 1]) c++;
        }
        if (k == 1) {
            if (c != 0) cout << -1 << '\n';
            else cout << 1 << '\n';
        }
        else {
            cout << max(1, ((c + k - 2) / (k - 1))) << '\n';
        }
    }
    return 0;
}