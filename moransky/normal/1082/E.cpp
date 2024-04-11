#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 500010;
int n, c, a[N], ans[N], sum[N], minn[N];
int main(){
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++){
        minn[a[i]] = min(minn[a[i]], sum[a[i]] - sum[c]);
        sum[a[i]]++;
        ans[i] = max(ans[i], sum[a[i]] - sum[c] - minn[a[i]]);
    }
    int res = sum[c];
    for(int i = 1; i <= n; i++)
        res = max(res, sum[c] + ans[i]);
    printf("%d", res);
    return 0;
}