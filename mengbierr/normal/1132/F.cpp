#include <bits/stdc++.h>
#define N 505
#define inf 0x3f3f3f3f
using namespace std;
char s[N];
int f[N][N];
int len;
int main() {
    scanf("%d%s", &len, s);
    for (int i = 0; i < len; i ++) f[i][i] = 1;
    for (int i = 1; i < len; i ++) 
        for (int j = 0; j < i; j ++) {
            f[j][i] = inf;
            for (int k = j; k < i; k ++) 
                f[j][i] = min(f[j][i], f[j][k] + f[k + 1][i - 1] + 1 - (int)(s[k] == s[i]));
        }
    printf("%d\n",f[0][len - 1]);
    return 0;
}