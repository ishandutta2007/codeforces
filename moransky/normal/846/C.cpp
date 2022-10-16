#include <cstdio>
#include <iostream>
#include <vector>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int N = 5005;
int n, a[N], f[N][4];
PII g[N][4];
int c[4] = {1, -1, 1, -1};
//f[i][j] i
//g[i][j] (loc)
void print(int l, int p){

    if(l == 0){
        for(int i = 0; i < p; i++)
            printf("0 ");
        return;
    }
    PII nxt = g[l][p];
    print(nxt.first, nxt.second);
    for(int i = 1; i <= p - nxt.second - 1; i++)
        printf("%lld ", nxt.first);
    printf("%lld ", l);
}
signed main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for(int i = 0; i < 4; i++) 
        g[0][i] = make_pair(0, i);
    for(int i = 1; i <= n; i++){
        f[i][0] = f[i - 1][0] + a[i];
        //
        for(int j = 1; j < 4; j++){
            int t = f[i - 1][j] + c[j] * a[i] , l, p;
            for(int k = 0; k < j; k++){
                t = max(t, f[i - 1][k] + c[j] * a[i]);
            }
 
            for(int k = 0; k < j; k++){
                if(t == f[i - 1][k] + c[j] * a[i]){
                    l = i - 1, p = k;
                }
            }
            if(t == f[i - 1][j] + c[j] * a[i]) 
                l = g[i - 1][j].first, p = g[i - 1][j].second;
            f[i][j] = t, g[i][j] = make_pair(l, p);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < 4; j++) printf("(%d, (%d, %d)) ", f[i][j], g[i][j].first, g[i][j].second);
    //     puts("");
    // }
    int ans = -9e18, l, p;
    for(int i = 0; i < 4; i++) {
        if(f[n][i] > ans){
            ans = f[n][i], l = n, p = i;
        }
    }
    
    print(g[l][p].first, g[l][p].second);
    for(int i = p + 1; i < 4; i++) printf("%lld ", n);
    return 0;
}