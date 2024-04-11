#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 510, mod = 998244353;
typedef long long LL;
int n, k, f[2][N][N], cnt[N];
void update(int &a, int b){ a = (a + b) % mod; }
int main(){
    scanf("%d%d", &n, &k);
    f[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        int pre = i & 1, now = pre ^ 1;
        memset(f[now], 0, sizeof f[now]);
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                update(f[now][j + 1][max(j + 1, k)], f[pre][j][k]);
                update(f[now][1][max(1, k)], f[pre][j][k]);
            }
        }  
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            update(cnt[i], f[n & 1][j][i]);
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i * j < k)
                ans = (ans + (LL)cnt[i] * cnt[j]) % mod;
        }
    }
    printf("%lld", (ans * (LL)((mod + 1) / 2)) % mod);
    return 0;
}