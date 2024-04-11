#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXK = 10;
const int INF = 1e9;

int blah[MAXK][4], maxn[MAXK][MAXK];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    int n, m, k, s;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for (int i=0; i<MAXK; i++) {
        blah[i][0] = blah[i][1] = -INF;
        blah[i][2] = blah[i][3] = INF;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x; scanf("%d", &x);
            blah[x][0] = max(blah[x][0], i + j);
            blah[x][1] = max(blah[x][1], i - j);
            blah[x][2] = min(blah[x][2], i + j);
            blah[x][3] = min(blah[x][3], i - j);
        }
    }
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=k; j++) {
            maxn[i][j] = max(abs(blah[i][0] - blah[j][2]), abs(blah[i][1] - blah[j][3]));
        }
    }
    int ans = 0, q1, q2;
    for (int i=0; i<s; i++) {
        scanf("%d", &q2);
        if (i > 0) ans = max(ans, maxn[q1][q2]);
        q1 = q2;
    }
    printf("%d\n", ans);
    return 0;
}