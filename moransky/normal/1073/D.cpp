#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 200010;
int n, a[N], cnt;
LL T, s = 2, ans = 0;
int main(){
    cin >> n >> T;
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    while(s){
        s = cnt = 0;
        for(int i = 1; i <= n; i++) 
            if(s + a[i] <= T) s += a[i], cnt++;
        if(s == 0) break;
        ans += (T / s) * cnt;
        T %= s;
    }
    printf("%lld", ans);
    return 0;
}