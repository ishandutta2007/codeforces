#include <bits/stdc++.h>
using namespace std;
const int maxN = 5005;
bool zero[maxN][maxN];
int f[maxN][maxN];
int val[maxN];
int ans[maxN];
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            val[i] = 0;
            continue;
        }
        int p = abs(x);
        for (int j = 2; j * j <= p; j++) {
            if ((p % (j * j)) == 0) {
                int t = j * j;
                while ((p % t) == 0) {
                    p /= t;
                    x /= t;
                }
            }
        }
        val[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        int q = val[i];
        f[i][i] = 1;
        zero[i][i] = (q == 0);
        bool ok = true;
        for (int j = i - 1; j >= 1; j--) {
            if (q == val[j]) {
                ok = false;
            }
            zero[j][i] = (zero[j][i - 1]) & (q == 0);
            if (ok) {
                if (zero[j][i - 1]) f[j][i] = 1;
                else {
                    f[j][i] = f[j][i - 1] + 1 - (q == 0);
                }
            }
            else {
                f[j][i] = f[j][i - 1];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans[f[i][j]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}