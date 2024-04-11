#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int n;
int a[maxN];
const int LIM = 100;
int pref[maxN][101];
const int SHIFT = maxN;
int lst[maxN + SHIFT];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= LIM; j++) {
            pref[i][j] = pref[i - 1][j];
            if (a[i] == j) pref[i][j]++;
        }
    }
    int f = 1;
    for (int c = 1; c <= 100; c++) {
        if (pref[n][c] > pref[n][f]) f = c;
    }
    int best = 0;
    for (int other = 1; other <= 100; other++) {
        if (other == f) continue;
        memset(lst, -1, sizeof lst);
        lst[SHIFT] = 0;
        for (int j = 1; j <= n; j++) {
            int cur_val = pref[j][f] - pref[j][other];
            if (lst[SHIFT + cur_val] != -1) {
                best = max(best, j - lst[SHIFT + cur_val]);
            }
            else {
                lst[SHIFT + cur_val] = j;
            }
        }
    }
    cout << best;
    return 0;
}