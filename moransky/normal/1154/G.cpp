#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 10000001;
int n, vis[N], l, r;
LL ans = 1e18;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if(vis[x] && ans > x) ans = x, l = vis[x], r = i;
        vis[x] = i;
    }
    for(int i = 1; i < N; i++){
        if(i >= ans) break;
        int s = 0;
        for(int j = i; j < N; j += i){
            if(j >= ans || (LL)s * j / i >= ans) break;
            if(!vis[j]) continue;
            if(!s) s = j;
            else{
                if(ans > (LL)s * j / i){
                    ans = (LL) s * j / i, l = vis[s], r = vis[j];
                }
                break;
            }
        }
    }
    if(l > r) swap(l, r);
    printf("%d %d\n", l, r);
    return 0;
}