#include <bits/stdc++.h>
#define N 505
#define K 22
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int inf = 1000000000;
int n, m, k;
int f[N][N][K];
int a[N][N];
int b[N][N];
int cal(int x, int y, int t) {
    if(x < 1 || x > n || y < 1 || y > m) return inf;
    if(t == 0) {
        return 0;
    }
    if(f[x][y][t] != inf) return f[x][y][t];
    int ret = inf;
    int tx, ty, val;
    tx = x, ty = y - 1;
    val = a[tx][ty];
    ret = min(ret, cal(tx, ty, t - 1) + val);

    tx = x, ty = y + 1;
    val = a[x][y];
    ret = min(ret, cal(tx, ty, t - 1) + val);

    tx = x - 1, ty = y;
    val = b[tx][ty];
    ret = min(ret, cal(tx, ty, t - 1) + val);

    tx = x + 1, ty = y;
    val = b[x][y];
    ret = min(ret, cal(tx, ty, t - 1) + val);

    f[x][y][t] = ret;
    return ret;
}
int main() {
    //freopen("line1.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m - 1; j += 1) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n - 1; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            for (int t = 0; t <= k; t += 1)
            f[i][j][t] = inf;
        }
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            if(k & 1) cout << -1 << ' ';
            else cout << 2 * cal(i, j, k / 2) << ' ';
        }
        cout << '\n';
    }

}