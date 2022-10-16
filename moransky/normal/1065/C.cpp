#include <cstdio>
#include <iostream>
#include <cmath>
#include <limits.h>
typedef long long LL;
using namespace std;
const int N = 200010;
int n, k, a[N], cnt[N], po[N], ans = 0, maxn = -1, minn = INT_MAX;
LL c[N];
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) 
        scanf("%d", a + i), po[a[i]]++, cnt[a[i]]++, maxn = max(maxn, a[i]), minn = min(minn, a[i]);
    for(int i = maxn; i >= 1; i--)
        cnt[i] += cnt[i + 1];

    int i = maxn - 1;
    c[maxn] = (LL)maxn * po[maxn];
    while(i >= minn){
        ans++;
        c[i] = c[i + 1] + (LL)i * po[i];
        while(i - 1 >= minn && c[i] - (LL)(i - 1) * cnt[i] <= k) 
            i--, c[i] = c[i + 1] + (LL)i * po[i];;
        c[i] += (LL)i * (cnt[i + 1]) - c[i + 1];
        i--;
    }
    printf("%d\n", ans);
    return 0;
}