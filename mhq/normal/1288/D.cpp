#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)3e5 + 10;
const int maxM = 9;
int a[maxN][maxM];
int mask[maxN];
bool hs[(1 << maxM)];
int who[(1 << maxM)];
int I, J;
bool check(int x) {
    memset(hs, 0, sizeof hs);
    for (int i = 0; i < n; i++) {
        mask[i] = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= x) mask[i] |= (1 << j);
        }
        hs[mask[i]] = true;
        who[mask[i]] = i;
    }
    for (int i = 0; i < (1 << m); i++) {
        if (!hs[i]) continue;
        for (int j = 0; j < (1 << m); j++) {
            if (!hs[j]) continue;
            if ((i | j) == (1 << m) - 1) {
                I = who[i];
                J = who[j];
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    int l = 0;
    int r = 1e9 + 10;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    check(l);
    cout << I + 1 << " " << J + 1;
    return 0;
}