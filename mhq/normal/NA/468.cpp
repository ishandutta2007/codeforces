#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int n, a, d;
int v[maxN], t[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> d;
    ld mx_t = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> v[i];
        ld tl = 0;
        ld tr = (ld)1e9;
        for (int iter = 0; iter < 60; iter++) {
            ld tm = (tl + tr) / 2;
            ld f1 = (ld)(v[i]) / a;
            ld S;
            if (f1 > tm) {
                S = (a * tm * tm) / 2;
            }
            else {
                S = (a * f1 * f1) / 2 + v[i] * (tm - f1);
            }
            if (S < d) tl = tm;
            else tr = tm;
        }
        //cout << fixed << setprecision(5) << v[i] * tl + (a * tl * tl) / 2 << " gg" << endl;
        mx_t = max(mx_t, t[i] + (tl + tr) / 2);
        cout << fixed << setprecision(10) << mx_t << '\n';
    }
    return 0;
}