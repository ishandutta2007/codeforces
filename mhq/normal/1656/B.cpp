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
        map<int,int> mp;
        bool ok = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (mp.count(x - k) || mp.count(x + k)) {
                ok = true;
            }
            mp[x] = 1;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}