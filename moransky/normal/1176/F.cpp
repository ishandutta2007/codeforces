#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200010;
int n, k;
LL f[N][10], ans = 0;
// 2 + 1, 1 + 1, 3, 1 + 1 + 1
//f[i][j]ij
//v
//f[i][(j + 1) % 10] = max{f[j] + max(maxC, maxA1, maxB) + (j + 1 >= 10) * max(maxC, maxA1, maxB)}
//
//f[i][(j + 2) % 10] = max{f[j] + maxA1 + max(maxB, maxA2) + (j + 2 >= 10) *  max(maxA1, maxB, maxA2))}
//
///f[i][(j + 3) % 10] = max(f[i][(j + 3) % 10], f[j] + max1 + max2 + max3 + (j + 3 >= 10) * max1)
void update(LL &x, LL y){
    if(x < y) x = y;
}
int main(){
    memset(f, 0xcf, sizeof f);
    f[0][0] = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int k, maxA[3] = {0, 0, 0}, maxB = 0, maxC = 0; 
        int numA = 0, numB = 0, numC = 0;
        scanf("%d", &k);
        for(int l = 1; l <= k; l++){
            int c, d; scanf("%d%d", &c, &d);
            //checkMax
            if(c == 1){
                for(int j = 0; j < 3; j++) {
                    if(!maxA[j]) { maxA[j] = d; break; }
                    else if(d > maxA[j]){
                        for(int k = 2; k >= j + 1; k--)
                            maxA[k] = maxA[k - 1];
                        maxA[j] = d;
                        break;
                    }
                }
            }else if(c == 2){
                if(d > maxB) maxB = d, numB = 1;
            }else if(c == 3){
                if(d > maxC) maxC = d, numC = 1;
            }
        }
        int maxV = max(maxA[0], max(maxB, maxC));
        numA = (maxA[0] > 0) + (maxA[1] > 0) + (maxA[2] > 0);
        
        
        for(int j = 0; j < 10; j++)
            f[i][j] = f[i - 1][j];
        
        for(int j = 0; j < 10; j++){
            if(maxV)
                update(f[i][(j + 1) % 10], f[i - 1][j] + maxV * ((j + 1 >= 10) + 1));
            
            if(numA + numB >= 2)
                update(f[i][(j + 2) % 10], f[i - 1][j] + maxA[0] + max(maxA[1], maxB) + (j + 2 >= 10) * max(maxA[0], max(maxA[1], maxB)));
            
            if(numA >= 3)
                update(f[i][(j + 3) % 10], f[i - 1][j] + maxA[0] + maxA[1] + maxA[2] + maxA[0] * (j + 3 >= 10));
            
        }
        
    }
    for(int i = 0; i <= 9; i++) ans = max(ans, f[n][i]);
    printf("%lld\n", ans);
    return 0;
}