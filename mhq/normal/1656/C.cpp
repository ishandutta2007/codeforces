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
       vector<int> a(n);
       for (int& v : a) cin >> v;
       sort(a.begin(), a.end());
       bool has_1 = false;
       for (int& v : a) {
           if (v == 1) has_1 = true;
       }
       if (!has_1) {
           cout << "Yes\n";
       }
       else {
           bool ok = true;
           for (int i = 0; i + 1 < n; i++) {
               if (a[i] + 1 == a[i + 1]) {
                   ok = false;
               }
           }
           if (ok) cout << "Yes\n";
           else cout << "No\n";
       }
    }
    return 0;
}