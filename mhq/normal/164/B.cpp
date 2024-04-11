#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e6 + 10;
const int LOG = 22;
int nxt[maxN][LOG];
int la, lb;
int posB[maxN];
int val[maxN];
const int INF = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> la >> lb;
    for (int i = 0; i < la; i++) {
        cin >> val[i];
    }
    memset(posB, -1, sizeof posB);
    for (int i = 0; i < lb; i++) {
        int y;
        cin >> y;
        posB[y] = i;
    }
    for (int i = 0; i < la; i++) {
        if (posB[val[i]] == -1 || posB[val[(i + 1) % la]] == -1) {
            nxt[i][0] = INF;
        }
        else {
            if (posB[val[i]] < posB[val[(i + 1) % la]]) {
                nxt[i][0] = posB[val[(i + 1) % la]] - posB[val[i]];
            }
            else {
                nxt[i][0] = lb + posB[val[(i + 1) % la]] - posB[val[i]];
            }
        }
    }
    for (int c = 1; c <= 20; c++) {
        for (int i = 0; i < la; i++) {
            nxt[i][c] = min(INF, nxt[i][c - 1] + nxt[(i + (1 << (c - 1))) % la][c - 1]);
        }
    }
    int best = 0;
    for (int i = 0; i < la; i++) {
        if (posB[val[i]] == -1) continue;
        int lft = lb - 1;
        int ans = 1;
        int ci = i;
        for (int k = 20; k >= 0; k--) {
            if (nxt[ci][k] <= lft) {
                ans += (1 << k);
                lft -= nxt[ci][k];
                ci = (ci + (1 << k)) % la;
            }
        }
        best = max(best, min(ans, la));
    }
    cout << best;
    return 0;
}