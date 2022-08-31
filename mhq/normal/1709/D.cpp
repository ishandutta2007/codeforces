#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
const int maxN = 2e5 + 10;
int a[maxN];
const int LOG = 20;
int mx[LOG][maxN];
int lg[maxN];
int get_mx(int l, int r) {
    int k = lg[r - l + 1];
    return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 2; i <= m; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        mx[0][i] = a[i];
    }
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i + (1 << (k + 1)) - 1 <= m; i++) {
            mx[k + 1][i] = max(mx[k][i], mx[k][i + (1 << k)]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        int d1 = abs(xf - xs);
        int d2 = abs(yf - ys);
        if (d1 % k != 0 || d2 % k != 0) {
            cout << "NO\n";
        }
        else {
            //xs + a * k <= n
            int lim = (n - xs) / k;
            xs += lim * k;
            if (get_mx(min(ys, yf), max(ys, yf)) >= xs) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }
    return 0;
}