/**
 * @author Macesuted (macesuted@outlook.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define maxn 200005
#define mod 998244353

typedef pair<int, int> pii;

map<int, map<int, int> > recordR, recordC;

int x[maxn], y[maxn];

void work(void) {
    int n, m, k;
    cin >> n >> m >> k;
    recordR.clear(), recordC.clear();
    for (register int i = 1; i <= n; i++) cin >> x[i];
    for (register int i = 1; i <= m; i++) cin >> y[i];
    sort(x + 1, x + n + 1), sort(y + 1, y + m + 1);
    for (register int i = 1; i <= k; i++) {
        int tx, ty;
        cin >> tx >> ty;
        int dx = lower_bound(x + 1, x + n + 1, tx) - x, dy = lower_bound(y + 1, y + m + 1, ty) - y;
        if (x[dx] == tx && y[dy] == ty) continue;
        if (x[dx] == tx)
            recordR[dy][dx]++;
        else
            recordC[dx][dy]++;
    }
    int answer = 0;
    for (auto i : recordR) {
        int sum = 0;
        for (auto j : i.second) sum += j.second;
        for (auto j : i.second) sum -= j.second, answer += j.second * sum;
    }
    for (auto i : recordC) {
        int sum = 0;
        for (auto j : i.second) sum += j.second;
        for (auto j : i.second) sum -= j.second, answer += j.second * sum;
    }
    cout << answer << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    int _ = 1;
    cout << setprecision(11);
    cin >> _;
    while (_--) work();
    return 0;
}