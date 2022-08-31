#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxK = 14;
const int maxS = (1 << maxK) + 2;
const int maxN = 103;
const int INF = 1e9 + 10;
int dpMask[maxS][maxN];
int n, m;
int xMask[maxK], yMask[maxK];
int xPos[maxN], yPos[maxN], t[maxN];
int dpCur[maxN];
int nearest[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    assert(n <= 14 && m <= 100);
    for (int i = 0; i < n; i++) cin >> xMask[i] >> yMask[i];
    for (int i = 0; i < m; i++) {
        cin >> xPos[i] >> yPos[i] >> t[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (t[i] > t[j]) {
                swap(t[i], t[j]);
                swap(xPos[i], xPos[j]);
                swap(yPos[i], yPos[j]);
            }       
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int z = 0; z <= m + 1; z++) {
            dpMask[i][z] = INF + 10;
            if ((i == 0 || (!(i & (i - 1)))) && !z) dpMask[i][z] = 0;
        }
    }
    int best = -1e9;
    for (int i = 0; i < (1 << n); i++) {
        //mask -> pos
        memset(dpCur, 0, sizeof dpCur);
        if (!i) {
            for (int r = 0; r < m; r++) dpCur[r] = 1;
        }
        else {
            for (int r = 0; r < m; r++) dpCur[r] = -INF;
        }
        for (int z = m - 1; z >= 0; z--) {
               dpMask[i][z] = min(dpMask[i][z], dpMask[i][z + 1]);
        }
        for (int u = 0; u < m; u++) {
            nearest[u] = INF;
            for (int p = 0; p < n; p++) {
                if (i & (1 << p)) {
                    nearest[u] = min(nearest[u], abs(xPos[u] - xMask[p]) + abs(yPos[u] - yMask[p]));
                }
            }
        }
        for (int where = 0; where < m; where++) {
            int at_most = t[where] - nearest[where];
            int bad = upper_bound(dpMask[i], dpMask[i] + m + 1, at_most) - dpMask[i];
              //  for (int u = 0; u < bad; u++) assert(dpMask[i][j][u] <= at_most);
             //   for (int u = bad; u <= m; u++) assert(dpMask[i][j][u] > at_most);
           //    assert(dpMask[i][j][bad] > at_most);
            if (bad > 0) {
                dpCur[where] = max(dpCur[where], bad);
            }
        }
        //pos -> pos
        for (int a = 0; a < m; a++) {
            best = max(best, dpCur[a]);
            for (int b = a + 1; b < m; b++) {
                if (min(nearest[b], abs(xPos[b] - xPos[a]) + abs(yPos[b] - yPos[a])) <= t[b] - t[a]) {
                    dpCur[b] = max(dpCur[b], dpCur[a] + 1);
                }
            }
        }
        //pos -> mask
        for (int z = 0; z < m; z++) {
            if (dpCur[z] > 0) {
                dpMask[i][dpCur[z]] = min(dpMask[i][dpCur[z]], t[z]);
                for (int j = 0; j < n; j++) {
                    if (!(i & (1 << j))) {
                        dpMask[i | (1 << j)][dpCur[z]] = min(dpMask[i | (1 << j)][dpCur[z]], t[z] + abs(xMask[j] - xPos[z]) + abs(yMask[j] - yPos[z]));
                    }
                }
            }
        }
        //mask -> mask
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;
            for (int r = 0; r <= m; r++) {
                int d = dpMask[i][r];
                if (d >= t[m - 1]) continue;
                for (int nxt = 0; nxt < n; nxt++) {
                    if (i & (1 << nxt)) continue;
                    dpMask[i | (1 << nxt)][r] = min(dpMask[i | (1 << nxt)][r], d + abs(xMask[nxt] - xMask[j]) + abs(yMask[nxt] - yMask[j]));
                }
            }
        }
    }
    cout << best << endl;
    return 0;
}