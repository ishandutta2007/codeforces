#include <iostream>
#include <cstdio>
using namespace std;
const int N = 500010;
int n, m, f[N], size[N];
int inline find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
void inline merge(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return ;
    if(size[x] > size[y]) swap(x, y);
    f[x] = y; size[y] += size[x];
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        f[i] = i, size[i] = 1;
    }
    for(int i = 1; i <= m; i++){
        int k, x; scanf("%d", &k);
        if(!k) continue;
        scanf("%d", &x); 
        for(int j = 1, y; j < k; j++){
            scanf("%d", &y);
            merge(x, y);    
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", size[find(i)]);
    return 0;
}