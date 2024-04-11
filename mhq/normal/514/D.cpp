#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
const int LOG = 20;
int p[5][LOG][maxN];
int n, m, k;
int a[maxN][5];
int lg[maxN];
int getMax(int c, int l, int r) {
    int k = lg[r - l + 1];
    return max(p[c][k][l], p[c][k][r - (1 << k) + 1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    lg[1] = 0;
    for (int i = 2; i < maxN; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            p[j][0][i] = a[i][j];
        }
    }
    for (int c = 0; c < m; c++) {
        for (int j = 0; j + 1 < LOG; j++) {
            for (int i = 1; i + (1 << (j + 1)) - 1 <= n; i++) {
                p[c][j + 1][i] = max(p[c][j][i], p[c][j][i + (1 << j)]);
            }
        }
    }
    auto calc =[&](int l, int r) {
        int t = 0;
        for (int i = 0; i < m; i++) {
            t += getMax(i, l, r);
        }
        return t;
    };
    int r = 0;
    int best = 0;
    int l1 = 1;
    int r1 = 0;
    for (int l = 1; l <= n; l++) {
        r = max(r, l - 1);
        while (r + 1 <= n && calc(l, r + 1) <= k) r++;
        if (r - l + 1 > r1 - l1 + 1) {
            r1 = r;
            l1 = l;
        }
    }
    if (l1 > r1) {
        for (int i = 0; i < m; i++) cout << 0 << " ";
    }
    else {
        for (int i = 0; i < m; i++) cout << getMax(i, l1, r1) << " ";
    }
    return 0;
}