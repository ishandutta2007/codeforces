#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int dp[maxn][3][3],n, m , ct[maxn];

int main(){
    /**
    Note that [x , x + 1 , x + 2] * 3 == [x, x ,x] + [x + 1 ,x + 1, x + 1], [x + 2, x+ 2 , x + 2]
    So there is no more than 2 [x , x + 1 , x + 2]

    */
    scanf("%d%d",&n,&m);
    for(int i = 1 ;i<= n ; i++){
        int x;
        scanf("%d" ,&x);
        ct[x] ++;
    }
    memset(dp, -1 , sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 1 ;i <= m ; i++){
        for(int x = 0; x < 3 ; x++){
            for(int  y = 0 ; y < 3 ; y++)
            for(int z  = 0 ; z < 3 ; z++){
                /// y of i - 2 ,(i - 1) , i  and z of (i - 1), i, i + 1
                /// overall we used i = y + z + x and add y when it's going to be kicked out
                /// at last step , we guarantee that each number successfully added
                if(dp[i-1][y][z] >= 0 && x + y + z <= ct[i]){
                    dp[i][z][x] = max(dp[i][z][x], dp[i-1][y][z] + (ct[i] - x - y - z) / 3 + y);
                    /// z of (i -1) , i , i + 1 and x of i , i + 1 , i + 2
                }
            }
        }
    }
    printf("%d\n",dp[m][0][0]);
}