#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 200010, M = N << 1;
int n, f[N][2], size[N][2];
LL ans = 0;
int inline find(int x, int c){
    return f[x][c] == x ? x : f[x][c] = find(f[x][c], c);
}
void merge(int a, int b, int c){
    a = find(a, c), b = find(b, c);
    if(a != b) f[a][c] = b, size[b][c] += size[a][c];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        f[i][0] = f[i][1] = i;
        size[i][0] = size[i][1] = 1;
    }
    for(int i = 1, u, v, w; i < n; i++){
        scanf("%d%d%d", &u, &v, &w);
        merge(u, v, w);
    }

    for(int i = 1; i <= n; i++){
        if(f[i][0] == i)
            ans += (LL)size[i][0] * (size[i][0] - 1);
        if(f[i][1] == i)
            ans += (LL)size[i][1] * (size[i][1] - 1);
        int p = find(i, 0), q = find(i, 1);
        ans +=  (LL)(size[p][0] - 1) * (size[q][1] - 1);
    }
    printf("%lld\n", ans);
    return 0;
}