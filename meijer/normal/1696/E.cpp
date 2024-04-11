#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int n, m, a[N], b[N];
string s;

int fact[N];
int ifact[N];

int modpow(int x, int y) {
    if (y == 0) return 1;
    int res = modpow(x, y/2);
    res = res*res%mod;
    if (y&1) res = res*x%mod;
    return res;
}

int inv(int x) {
    return modpow(x,mod-2);
}

int binom(int x, int y) {
    if (y <= 0 || y > x) return 0;
    return fact[x] * ifact[y] % mod * ifact[x-y] % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (int i=1; i<N; i++) fact[i] = fact[i-1] * i % mod;
    ifact[N-1] = inv(fact[N-1]);
    for (int i=N-2; i>=0; i--) ifact[i] = ifact[i+1] * (i+1) % mod;

    cin >> n;
    for (int i=0; i<n+1; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    int len = n+1;
    for (int i=1; i<N; i++) {
        while (len > 0 && a[len-1] < i) len--;
        if (len == 0) break;
        ans = (ans + binom(len + i - 1, i)) % mod;
    }
    cout << ans << endl;
}