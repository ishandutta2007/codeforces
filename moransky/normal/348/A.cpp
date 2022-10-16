#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100005;
int n, a[N], mx;
LL s = 0;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i), s += a[i], mx = max(mx, a[i]);
    
    printf("%d\n", max(mx, (int)(s % (n - 1) ? s / (n - 1) + 1 : s / (n - 1))));
    return 0;
}