#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1000005, P = 998244353;
int n, fact[N], infact[N];
int inline power(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}
int inline Per(int n, int k) {
    return (LL)fact[n] * infact[n - k] % P;
}
int main() {
    scanf("%d", &n);

    fact[0] = infact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (LL)fact[i - 1] * i % P;
        infact[i] = (LL)infact[i - 1] * power(i, P - 2) % P;
    }
    int ans = fact[n];
    for (int i = 2; i < n; i++) {
        ans = (ans + (LL)(Per(n, n - i)) * (Per(i, i) - 1)) % P;
    }
    printf("%d\n", ans);
    return 0;
}