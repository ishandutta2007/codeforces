#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int maxn = 2000100;
const int mod = 1e9 + 7;

int n, fact[maxn], invfact[maxn];

int exp(int b, int e) {
    if (!e) return 1;
    if (e&1) return ll(exp(b, e-1))*b%mod;
    int res = exp(b, e>>1);
    return ll(res)*res%mod;
}

int main() {
    cin >> n;
    fact[0] = 1;
    for (int i=1; i<maxn; i++) fact[i] = ll(fact[i-1])*i%mod;
    
    for (int i=0; i<maxn; i++) invfact[i] = exp(fact[i], mod-2);

    int ans = fact[2*n+2];
    ans = ll(ans)*invfact[n+1]%mod*invfact[n+1]%mod;
    ans = (ans+mod-1)%mod;
    cout << ans << '\n';
}