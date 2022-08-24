#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 4 * (int)1e5 + 100;
int a[maxN];
const int LG = 20;
int up[maxN][LG];
int lg[maxN];
int getMx(int l, int r) {
    int k = lg[r - l + 1];
    return max(up[l][k], up[r - (1 << k) + 1][k]);
}
int val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int i = 2; i < maxN; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
        a[2 * n + i] = a[i];
    }
    int tot = n * 3;
    for (int i = 1; i <= tot; i++) {
        up[i][0] = a[i];
    }
    for (int j = 0; j + 1 < LG; j++) {
        for (int i = 1; i + (1 << (j + 1)) - 1 <= tot; i++) {
            up[i][j + 1] = max(up[i][j], up[i + (1 << j)][j]);
        }
    }
    for (int i = 1; i <= 3 * n; i++) {
        int l = 0;
        int r = i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (getMx(mid, i) <= 2 * a[i]) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        val[i] = r;
    }
    for (int i = 1; i <= tot; i++) {
        up[i][0] = val[i];
        //cout << i << " " << val[i] << endl;
    }

    for (int j = 0; j + 1 < LG; j++) {
        for (int i = 1; i + (1 << (j + 1)) - 1 <= tot; i++) {
            up[i][j + 1] = max(up[i][j], up[i + (1 << j)][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (getMx(i, 3 * n) <= i) cout << -1 << " ";
        else {
            int l = i;
            int r = 3 * n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (getMx(i, mid) <= i) l = mid;
                else r = mid;
            }
            cout << l - i + 1 << " ";
        }
    }
    return 0;
}