#include <cstdio>
#include <iostream>
using namespace std;
const int N = 105;
int n, m, H, a[N], b[N], h[N][N];
int st[N];
int main(){
    scanf("%d%d%d", &n, &m, &H);
    for(int i = 1; i <= m; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            scanf("%d", &h[i][j]);
    }
    for(int j = 1; j <= m; j++){
        int t = -1;
        for(int i = 1; i <= n; i++){
            if(h[i][j] && a[j] <= b[i])
                { t = i; break; }
        }
        h[t][j] = a[j]; st[t] = true;
    }
    for(int i = 1; i <= n; i++){
        int t = -1;
        for(int j = 1; j <= m; j++){
            if(h[i][j] && b[i] <= a[j])
                { t = j; break; }
        }
        h[i][t] = b[i]; st[t] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ", h[i][j]);
        }
        puts("");
    }
    return 0;
}