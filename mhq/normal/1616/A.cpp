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
        map<int,int> mp;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mp[abs(x)]++;
        }
        int ans = 0;
        for (auto& it : mp) {
            if (it.first == 0) ans += 1;
            else ans += min(2, it.second);
        }
        cout << ans << '\n';
    }
    return 0;
}