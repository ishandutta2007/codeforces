#include <bits/stdc++.h>
using namespace std;
int n, r;
long double x[1005];
long double y[1005];
const long double eps = 1e-9;
long double inter(int i, int j) {
    if (abs(x[i] - x[j]) > 2 * r) return r;
    long double t = 4 * r * r - (x[i] - x[j]) * (x[i] - x[j]);
    long double p = sqrt(t) + 1.0 * y[j];
    return p;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    long double mi = r;
    for (int i = 1; i <= n; i++) {
        mi = r;
        for (int j = 1; j < i; j++) {
            long double p = inter(i, j);
            //if (i == 5) cout << p << '\n';
            mi = max(p, mi);
        }
        y[i] = mi;
    }
    for (int i = 1; i <= n; i++) cout << fixed << setprecision(9) << y[i] << " ";
    return 0;
}