#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (1 << 16) + 10;
int k;
int a[maxN], b[maxN];
void solve() {
    cin >> n >> k;
    if (k < (n - 1)) {
        for (int i = 0; i < n / 2; i++) {
            a[i] = i;
            b[i] = n - 1 - i;
        }
        if (k != 0) {
            for (int i = 1; i < n / 2; i++) {
                if (a[i] == k || b[i] == k) {
                    b[0] = n - 1 - k;
                    a[i] = n - 1;
                    b[i] = k;
                    break;
                }
            }
        }
    }
    else {
        if (n == 4) {
            cout << -1 << '\n';
            return;
        }
        else {
            int sz = 0;
            for (int i = 3; i < n  / 2; i++) {
                a[sz] = i;
                b[sz] = n - 1 - i;
                sz++;
            }
            a[sz] = 0;
            b[sz] = 2;
            sz++;
            a[sz] = 1;
            b[sz] = n - 3;
            sz++;
            a[sz] = n - 2;
            b[sz] = n - 1;
            sz++;
        }
    }
    int ss = 0;
    for (int i = 0; i < n / 2; i++) {
        ss += (a[i] & b[i]);
    }
    assert(ss == k);
    for (int i = 0; i < n / 2; i++) {
        cout << a[i] << " " << b[i] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}