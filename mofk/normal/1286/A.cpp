#include <bits/stdc++.h>

using namespace std;

const int inf = 1000005;
int n;
int p[105];
int f[105][105][105][3];

int calc(int i, int od, int ev, int lst) {
    int &ans = f[i][od][ev][lst];
    if (~ans) return ans;
    if (i == 0) return ans = 0;
    if (p[i]) {
        return ans = calc(i - 1, od, ev, p[i] & 1) + ((p[i] & 1) != lst);
    }
    int x = od ? (calc(i - 1, od - 1, ev, 1) + (lst != 1)) : inf;
    int y = ev ? (calc(i - 1, od, ev - 1, 0) + (lst != 0)) : inf;
    return ans = min(x, y);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    int ev, od;
    ev = n / 2;
    od = n - ev;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] == 0) continue;
        if (p[i] & 1) --od;
        else --ev;
    }
    memset(f, -1, sizeof f);
    cout << calc(n, od, ev, 2) - 1 << endl;
    return 0;
}