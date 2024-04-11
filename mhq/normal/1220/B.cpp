#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1005;
ll a[maxN][maxN];
int sqr(ll x) {
    int p = sqrt(x);
    while (1LL * p * p < x) p++;
    while (1LL * p * p > x) p--;
    return p;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 2) {
            cout << sqr((a[1][i] * a[2][i]) / a[1][2]) << " ";
        }
        else if (i == 2) {
            cout << sqr((a[1][2] * a[2][3]) / (a[1][3])) << " ";
        }
        else {
            cout << sqr((a[1][2] * a[1][3]) / a[2][3]) << " ";
        }
    }
    return 0;
}