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
        vector < int > a(n);
        vector < bool > used(n);
        for (int& v : a) cin >> v;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            int ind = -1;
            int val = 0;
            for (int c = 0; c < n; c++) {
                if (used[c]) continue;
                if (ind == -1 || __gcd(a[c], cur) > val) {
                    ind = c;
                    val = __gcd(a[c], cur);
                }
            }
            cur = val;
            assert(ind != -1);
            used[ind] = true;
            cout << a[ind] << " ";
        }
        cout << '\n';
    }
    return 0;
}