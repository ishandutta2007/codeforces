#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1100000;
int n;
ll h[N];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &h[i]);
    ll sum  = 0;
    for(int i = 1; i <= n; i++) sum += h[i];
    sum -= 1ll * n * (n - 1) / 2;
    for(int i = 1; i <= n; i++) printf("%lld ", i - 1 + (sum / n) + (i <= sum % n));
    printf("\n");
    return 0;
}