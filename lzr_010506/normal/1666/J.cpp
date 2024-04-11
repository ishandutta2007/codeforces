#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 209;
int n, g[N][N], rt[N][N];
int sum[N][N], f[N][N];
int fa[N];
void print(int l, int r, int pre) {
    if(l > r) return ;
    int rrr = rt[l][r];
    fa[rrr] = pre;
    print(l, rrr - 1, rrr);
    print(rrr + 1, r, rrr);
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> g[i][j];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) g[i][j] += g[i][j - 1];
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            for(int k = i; k <= j; k++) {
                sum[i][j] += g[k][i - 1] - g[k][j] + g[k][n];
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n + 1; i++) {
        f[i][i] = f[i][i - 1] = 0;
        rt[i][i] = i;
    }
    for(int len = 1; len <= n; len++) {
        for(int i = 1; i <= n; i++) {
            int j = i + len - 1;
            for(int k = i; k <= j; k++) {
                if(f[i][j] > f[i][k - 1] + f[k + 1][j] + sum[i][k - 1] + sum[k + 1][j]) {
                    f[i][j] = f[i][k - 1] + f[k + 1][j] + sum[i][k - 1] + sum[k + 1][j];
                    rt[i][j] = k;
                }
            }
        }
    }
//    cout << rt[1][1] << endl;
//    return 0;
    print(1, n, 0);
    for(int i = 1; i <= n; i++) {
        cout << fa[i] << " " ;
    }
    cout << endl;
    return 0;
}