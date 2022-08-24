#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll n;
int k;
const int maxN = 105;
int a[maxN];
const int maxP = 6324554 + 100;
ll x[maxP];
int y[maxP];
ll nx[maxP];
int ny[maxP];
ll cx[maxP];
int cy[maxP];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            cout << 0;
            return 0;
        }
    }
    sort(a + 1, a + k + 1);
    reverse(a + 1, a + k + 1);
    int sz = 1;
    x[1] = n;
    y[1] = 1;
    for (int i = 1; i <= k; i++) {
        int new_sz = 0;
        for (int j = 1; j <= sz; j++) {
            if (x[j] < a[i]) continue;
            ll xx = x[j] / a[i];
            if (xx == nx[new_sz]) ny[new_sz] -= y[j];
            else {
                nx[++new_sz] = xx;
                ny[new_sz] -= y[j];
            }
        }
        int l1 = 1;
        int r1 = 1;
        int TOT_SZ = 0;
        while (l1 <= sz || r1 <= new_sz) {
            if (l1 > sz || (r1 <= new_sz && x[l1] > nx[r1])) {
                cx[++TOT_SZ] = nx[r1];
                cy[TOT_SZ] = ny[r1];
                r1++;
            }
            else if (r1 > new_sz || (l1 <= sz && x[l1] < nx[r1])) {
                cx[++TOT_SZ] = x[l1];
                cy[TOT_SZ] = y[l1];
                l1++;
            }
            else {
                cx[++TOT_SZ] = x[l1];
                cy[TOT_SZ] = (y[l1] + ny[r1]);
                l1++;
                r1++;
            }
        }
        for (int it = 1; it <= TOT_SZ; it++) {
            x[it] = cx[it];
            y[it] = cy[it];
            cx[it] = cy[it] = 0;
            nx[it] = ny[it] = 0;
        }
        sz = TOT_SZ;
    }
    ll ans = 0;
    for (int i = 1; i <= sz; i++) {
        ans += x[i] * y[i];
    }
    cout << ans;
    return 0;
}