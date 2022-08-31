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
        int x, m;
        cin >> n >> x >> m;
        int l = x;
        int r = x;
        while (m--) {
            int l1, r1;
            cin >> l1 >> r1;
            if (max(l1, l) <= min(r, r1)) {
                l = min(l, l1);
                r = max(r, r1);
            }
        }
        cout << (r - l + 1) << '\n';
    }
    return 0;
}