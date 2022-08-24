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
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < 2 * n; i++) {
            int x;
            cin >> x;
            cnt += (x % 2);
        }
        if (cnt == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}