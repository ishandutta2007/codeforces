#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 200010, MOD = 998244353;
int n;
char s[N];
int main(){
    scanf("%d%s", &n, s + 1);
    int l = 1, r = n;
    while(s[l] == s[l + 1]) l++;
    while(s[r] == s[r - 1]) r--;
    if(l == n && r == 1) printf("%lld\n", ((LL)(1 + n) * n / 2) % MOD); 
    else if(s[l] == s[r]) printf("%lld\n", ((LL)(l + 1) * (n - r + 2)) % MOD);
    else printf("%d\n", (l + (n - r + 1) + 1) % MOD);
    return 0;
}