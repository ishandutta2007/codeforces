#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

char s1[2500], s2[2500], t[2500];
int ls, lt, f[2500][2500], g[2500][2500], from[2500], ml[2500], dp[2500], last[2500];

void print(int x){
    int y = last[x];
    if (y > 1) print(y - 1);
    if (from[y] <= ls){
        printf("%d %d\n", from[y], from[y] + x - y);
    }else{
        printf("%d %d\n", from[y] - ls, from[y] - x + y - ls);
    }
}

void work(){
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= lt; i++){
        for(int j = 1; j <= i; j++)
            if (ml[j] >= i - j + 1){
                if (dp[i] > dp[j - 1] + 1){
                    dp[i] = dp[j - 1] + 1;
                    last[i] = j;
                }
            }
        if (dp[i] > i){
            printf("-1");
            return;
        }
    }
    printf("%d\n", dp[lt]);
    print(lt);
}

int main(){
    scanf("%s", s1 + 1);
    scanf("%s", t + 1);
    ls = strlen(s1 + 1);
    lt = strlen(t + 1);
    for(int i = 1; i <= ls; i++)
        s2[i] = s1[ls - i + 1];
    
    for(int i = ls; i >= 1; i--)
        for(int j = lt; j >= 1; j--)
            f[i][j] = s1[i] == t[j] ? f[i + 1][j + 1] + 1 : 0;

    for(int i = ls; i >= 1; i--)
        for(int j = lt; j >= 1; j--)
            g[i][j] = s2[i] == t[j] ? g[i + 1][j + 1] + 1 : 0;
    for(int i = 1; i <= lt; i++)
        for(int j = 1; j <= ls; j++){
            if (f[j][i] > ml[i]){
                ml[i] = f[j][i];
                from[i] = j;
            }
            if (g[j][i] > ml[i]){
                ml[i] = g[j][i];
                from[i] = (ls - j + 1) + ls;
            }
        }
    work();
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/