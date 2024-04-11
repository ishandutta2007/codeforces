#include <cstdio>
#include <iostream>
using namespace std;
const int N = 105;
int n, m, K, a[N][N];
int sum = 0, ans = 0;
int main(){
    scanf("%d%d%d", &n, &m, &K);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
    for(int  j = 1; j <= m; j++){
        int tot = 0, maxS = 0, nowC = 0;
        for(int i = 1; i <= n; i++){
            if(!a[i][j]) continue;
            int r = i, tmp = 1;
            while(r < n && r - i + 1 < K) r++, tmp += a[r][j];
            if(tmp > maxS){
                maxS = tmp;
                nowC = tot;
            }
            tot ++;
        }
        sum += maxS, ans += nowC;
    }
    printf("%d %d\n", sum, ans);
    return 0;
}