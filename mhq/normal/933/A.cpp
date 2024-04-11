#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 2005;
int a[maxN];
int b[maxN];
int ans[maxN][maxN];
int cnt1[maxN];
int cnt2[maxN];
int cnt1b[maxN];
int cnt2b[maxN];
int solve(int i, int j) {
    if (i > j) return 0;
    if (ans[i][j] != -1) return ans[i][j];
    if (i == j) return 1;
    if (b[i] == 1) {
        ans[i][j] = solve(i + 1, j) + 1;
        return ans[i][j];
    }
    else {
        ans[i][j] = max(solve(i + 1, j), cnt2b[j] - cnt2b[i - 1]);
        return ans[i][j];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) ans[i][j] = -1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt1[i] = cnt1[i - 1];
        cnt2[i] = cnt2[i - 1];
        if (a[i] == 1) cnt1[i]++;
        if (a[i] == 2) cnt2[i]++;
        b[n + 1 - i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cnt2b[i] = cnt2b[i - 1];
        if (b[i] == 2) {
            cnt2b[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            solve(i, j);
        }
    }
    int mx = max(cnt1[n], cnt2[n]);
    for (int i = 1; i <= n; i++) {
        mx = max(mx, cnt1[i - 1] + cnt2[n] - cnt2[i - 1]);
    }
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            mx = max(mx, cnt1[l - 1] + ans[n + 1 - r][n + 1 - l] + cnt2[n] - cnt2[r]);
        }
    }
    cout << mx;
    return 0;
}