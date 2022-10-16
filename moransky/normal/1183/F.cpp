#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200010;
int n, a[N], res[3], pre[N];
int main(){
    int T;  scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", a + i), pre[i] = i - 1;
        sort(a + 1, a + 1 + n);
        int ans = 0, cur = 0;
        for(int i = 1; i <= n; i++){
            int sum = a[i], s = 1, x = i;
            while(s < 3 && x){
                if(a[i] % a[x]) s++, sum += a[x];
                while(pre[x] && a[i] % a[pre[x]] == 0) pre[x] = pre[pre[x]];
                x = pre[x];
            }
            ans = max(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}