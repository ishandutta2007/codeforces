#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5005;
const int MAXM = 105;

int n, m, num[MAXM], cnt, imax, ans[MAXN][2], tot;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int c; cin >> c; num[c] ++;
    }
    for (int i=1; i<=m; i++) {
        imax = max(imax, num[i]);
        while (num[i] > 0) {ans[cnt++][0] = i; num[i]--;}
    }
    for (int i=0; i<n; i++) ans[(i+imax)%n][1] = ans[i][0];
    for (int i=0; i<n; i++) tot += bool(ans[i][0] != ans[i][1]);
    cout << tot << endl;
    for (int i=0; i<n; i++) cout << ans[i][0] << ' ' << ans[i][1] << endl;
    return 0;
}