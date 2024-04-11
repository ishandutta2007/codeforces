#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 200005;
LL ans = 0;
int n, a[N];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i),  a[i] = abs(a[i]);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        int l = i + 1, r = n + 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(a[mid] - a[i] <= a[i]) l = mid + 1;
            else r = mid;
        }
        ans += r - i - 1;
    }
    printf("%lld\n", ans);
    return 0;
}