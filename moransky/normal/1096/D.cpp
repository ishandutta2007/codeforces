#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
typedef long long LL;
char s[N];
int n, a[N];
LL f[N][4];
//f[i][j] i "hard" -> j  
int main(){
    memset(f, 0x3f, sizeof f);
    for(int i = 0; i < 4; i++) f[0][i] = 0;
    scanf("%d%s", &n, s + 1);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++) f[i][j] = f[i - 1][j];
        if(s[i] == 'h') f[i][0] = f[i - 1][0] + a[i];
        if(s[i] == 'a') f[i][1] = min(f[i - 1][0], f[i - 1][1] + a[i]); 
        if(s[i] == 'r') f[i][2] = min(f[i - 1][1], f[i - 1][2] + a[i]); 
        if(s[i] == 'd') f[i][3] = min(f[i - 1][2], f[i - 1][3] + a[i]); 
    }
    printf("%lld\n", f[n][3]);
    return 0;
}