#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int maxN = 1e6 + 10;
int fenw[maxN];
void upd(int v, int by) {
    while (v < maxN) {
        fenw[v] += by;
        v = (v | (v - 1)) + 1;
    }
}
int lower_bound(int lim) {
    int lg = 21;
    int res = 0;
    for (int k = lg; k >= 0; k--) {
        int p = (res + (1 << k));
        if (p < maxN && fenw[p] < lim) {
            lim -= fenw[p];
            res += (1 << k);
        }
    }
    return res + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        upd(x, +1);
    }
    while (q--) {
        int k;
        cin >> k;
        if (k > 0) {
            upd(k, +1);
            n++;
        }
        else {
            int c = lower_bound(-k);
            upd(c, -1);
            n--;
        }
    }
    if (!n) {
        cout << 0 << '\n';
    }
    else {
        cout << lower_bound(1) << '\n';
    }
    return 0;
}