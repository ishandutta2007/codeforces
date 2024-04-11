#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;
typedef long long LL;
const int N = 200010;
int n;
LL a[N], b[N >> 1];
int main(){
    scanf("%d", &n);
    a[n + 1] = 9223372036854775807ll;
    for(int i = 1; i <= (n >> 1); i++) {
        scanf("%lld", b + i);
        a[i] = max(a[i - 1], b[i] - a[n - i + 1 + 1]);
        a[n - i + 1] = b[i] - a[i];
    }
    for(int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
    return 0;
}