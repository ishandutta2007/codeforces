#include <cstdio>
#include <iostream>
#include <cmath>
 
using namespace std;
typedef long long LL;
const int N = 300010;
//s
int n, a[2][N];
LL pre[2][N], s[2][N], suf[2][N], sum[N], prex[2][N], sufx[2][N], ans = -1;
 
 
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[0][i]);
    for(int i = 1; i <= n; i++) scanf("%d", &a[1][i]);
    int S = n >> 1, tot = 0;
    for(int i = 1; i <= S * 2; i+=2){
        s[0][i] = (LL)a[0][i] * (tot++); s[1][i] = (LL)a[1][i] * (tot++);
        s[1][i + 1] = (LL)a[1][i + 1] * (tot++); s[0][i + 1] = (LL)a[0][i + 1] * (tot++); 
    }

   
    for(int i = 0; i < 2; i++)
        for(int j = 1; j <= n; j++){
            pre[i][j] = pre[i][j - 1] + a[i][j];
            prex[i][j] = prex[i][j - 1] + pre[i][j];     
        }
    
    for(int j = 0; j < 2; j++)
        for(int i = n; i >= 1; i--){
            suf[j][i] = suf[j][i + 1] + a[j][i]; 
            sufx[j][i] = sufx[j][i + 1] + suf[j][i]; 
        }
 
    for(int i = 0; i <= n; i++){
        LL tot = sum[i] = sum[i - 1] + s[0][i] + s[1][i];
        //
        if(i % 2){
            tot += (n + i - 1) * suf[0][i + 1] + (prex[0][n] - prex[0][i] - (n - i) * pre[0][i]);
            tot += (i * 2 - 1) * suf[1][i + 1]  + (sufx[1][i + 1]);
        }else{
            //
            tot += (i * 2 - 1) * suf[0][i + 1] + (sufx[0][i + 1]);
            tot += (n + i - 1) * suf[1][i + 1] + (prex[1][n] - prex[1][i] - (n - i) * pre[1][i]);
        }
        ans = max(ans, tot);
    }

    printf("%lld", ans);
    return 0;
}