#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
ll p[maxN];
int a, b, x, y;
ll k;
int n;
ll check(int pref) {
    int cntAB = pref / ((1LL * a * b) / (__gcd(a, b)));
    int cntA = pref  / a;
    int cntB = pref / b;
    cntA -= cntAB;
    cntB -= cntAB;
    ll sm = 0;
    for (int i = 1; i <= pref; i++) {
        if (cntAB > 0) {
            sm += (p[i] / 100) * (x + y);
            cntAB--;
        }
        else if (cntA > 0) {
            sm += (p[i] / 100) * x;
            cntA--;
        }
        else if (cntB > 0) {
            sm += (p[i] / 100) * y;
            cntB--;
        }
        else {

        }
    }
    return sm;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        cin >> x >> a >> y >> b;
        cin >> k;
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        sort(p + 1, p + n + 1);
        reverse(p + 1, p + n + 1);
        int r = n;
        int l = 0;
        if (check(r) < k) {
            cout << -1 << '\n';
            continue;
        }
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid) >= k) r = mid;
            else l = mid;
        }
        cout << r << '\n';
    }
    return 0;
}