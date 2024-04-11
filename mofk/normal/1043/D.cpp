#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[15][100005];
int p[15][100005];
int ptr[15];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j], p[i][a[i][j]] = j;
    long long ans = 0;
    int l = 1;
    for (int i = 1; i <= m; ++i) ptr[i] = p[i][a[1][1]];
    for (int i = 1; i <= n; ++i) {
        if (l < i) {
            l = i;
            for (int j = 1; j <= m; ++j) ptr[j] = p[j][a[1][l]];
        }
        while (true) {
            ++l;
            int flag = 1;
            for (int j = 1; j <= m; ++j) if (p[j][a[1][l]] != ptr[j] + 1) flag = 0;
            if (!flag) {
                --l;
                break;
            }
            for (int j = 1; j <= m; ++j) ptr[j]++;
        }
        ans += l - i + 1;
    }
    cout << ans << endl;
    return 0;
}