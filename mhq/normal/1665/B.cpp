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
            mp[x]++;
        }
        int mx = 0;
        for (auto& it : mp) {
            mx = max(mx, it.second);
        }
        int need = (n - mx);
        int sz = mx;
        while (sz < n) {
            need++;
            sz *= 2;
        }
        cout << need << '\n';
    }
    return 0;
}