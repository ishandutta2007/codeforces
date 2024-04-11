#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 998244353, N = 1010;
typedef long long LL;
int n, k;
LL f[N][N << 1][4];
/* f[i][j][k] ij, type = k;
type = 0:
0
0
type = 1:
0
1
type = 2:
1
0
type = 3:
1
1
 */
int main(){
    cin >> n >> k;
    f[1][1][0] = f[1][2][1] = f[1][2][2] = f[1][1][3] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i * 2; j++){
            (f[i][j][0] += f[i - 1][j][0] + f[i - 1][j][1] + f[i - 1][j][2] + f[i - 1][j - 1][3]) %= mod;
            (f[i][j][1] += f[i - 1][j - 1][0] + f[i - 1][j][1] + (j >= 2 ? f[i - 1][j - 2][2] : 0) + f[i - 1][j - 1][3]) %= mod;
            (f[i][j][2] += f[i - 1][j - 1][0] + (j >= 2 ? f[i - 1][j - 2][1] : 0) + f[i - 1][j][2] + f[i - 1][j - 1][3]) %= mod;
            (f[i][j][3] += f[i - 1][j - 1][0] + f[i - 1][j][1] + f[i - 1][j][2] + f[i - 1][j][3]) %= mod;
        }
    }
    LL res = 0;
    for(int i = 0; i < 4; i++) (res += f[n][k][i]) %= mod;
    cout << res;
    return 0;
}