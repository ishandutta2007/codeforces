#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q;
const int maxval = 105;
int f[1 << 12][maxval];
int w[15];
int a[1 << 12];
int val[1 << 12];
vector < int > all[maxval];
int ans[1 << 12][maxval];
// 16 mb
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') mask += 1 << i;
        }
        a[mask]++;
    }
    int big = (1 << n) - 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0) val[mask] += w[j];
        }
        if (val[mask] >= maxval) continue;
        for (int mask2 = 0; mask2 < (1 << n); mask2++) {
            ans[mask2][val[mask]] += a[(mask2 ^ mask)];
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int we = 1; we < maxval; we++) {
            ans[mask][we] += ans[mask][we - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < n; i++) if (s[i] == '1') mask += 1 << i;
        int k;
        cin >> k;
        cout << ans[mask][k] << '\n';
    }
}