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
        string a;
        cin >> a;
        string b = a;
        sort(b.begin(), b.end());
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}