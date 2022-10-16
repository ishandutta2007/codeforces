#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 200010, MOD = 998244353;
int n;
LL ans = 0, a[N], b[N];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%lld", a + i), a[i] *= (LL)(n - i + 1) * i;
    
    for(int i = 1; i <= n; i++)
        scanf("%lld", b + i);
    
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n, greater<int>() );

    for(int i = 1; i <= n; i++){
        a[i] %= MOD;
        (ans += (LL)a[i] * b[i]) %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}