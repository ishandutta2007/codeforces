#include <bits/stdc++.h>
using namespace std;
const int maxN = 5 * (int)1e5 + 10;
int n;
long long pref[maxN];
long long a[maxN];
long double opt;
int sz = 0;
long double f(int ind) {
    if (ind >= sz) {
        return (long double)1e18;
    }
    return (1.0 * a[sz] + pref[ind]) / (1.0 * (ind + 1));
}
void solve(long long x) {
    a[sz] = x;
    pref[sz] = pref[sz - 1] + a[sz];
    int l = 0;
    int r = sz - 1;
    while (r - l > 2) {
        int mid1 = (r + l) / 2;
        int mid2 = mid1 + 1;
        if (f(mid1) >= f(mid2)) l = mid1;
        else r = mid2;
    }
    opt = max(opt, x - f(l));
    opt = max(opt, x - f(l + 1));
    opt = max(opt, x - f(l + 2));
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        long long x;
        cin >> type;
        if (type == 2) cout << fixed << setprecision(15) << opt << '\n';
        else {
            cin >> x;
            sz++;
            solve(x);
        }
    }
    return 0;
}