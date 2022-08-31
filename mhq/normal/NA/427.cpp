#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a[105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, d;
        cin >> n >> d;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            while (d >= (i - 1) && a[i] > 0) {
                a[i]--;
                d -= (i - 1);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}