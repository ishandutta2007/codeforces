#include <cstdio>
#include <iostream>
using namespace std;
const int N = 205, M = N;
int n, m, a[N][M], r[N], c[M], b[N][M];
//
bool inline check(){
    for(int i = 1; i <= m; i++)
        c[i] = a[1][i] ^ b[1][i];
    
    for(int i = 2; i <= n; i++){
        r[i] = a[i][1] ^ b[i][1] ^ c[1];
        for(int j = 2; j <= m; j++)
            if((r[i] ^ c[j]) != (a[i][j] ^ b[i][j])) return false;
    }
    return true;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
            b[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(check()){
                puts("YES");
                for(int i = 1; i <= n; i++)
                    printf("%d", r[i]);
                puts("");
                for(int i = 1; i <= m; i++)
                    printf("%d", c[i]);
                return 0;
            }
            b[i][j] = 0;
        }
    }
    puts("NO");
    return 0;
}