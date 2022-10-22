#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MX = 2e5+10;
const int mod = 998244353;

int n, m;
int s[MX], t[MX];
int fact[MX];
int ifact[MX];
int cnt[MX];

int modpow(int x, int y) {
    if (y == 0) return 1;
    int z = modpow(x,y/2);
    z = z*z%mod;
    if (y&1) z = z*x%mod;
    return z;
}
int inv(int x) {
    return modpow(x, mod-2);
}

int ft[MX];
void addft(int i, int v) {
    for (i++; i<MX; i+=i&-i)
        ft[i] = (ft[i] + v) % mod;
}
int getft(int i) {
    int res = 0;
    for (i++; i>0; i-=i&-i)
        res += ft[i];
    return res % mod;
}

signed main() {
    fact[0] = 1;
    for (int i=1; i<MX; i++) fact[i] = fact[i-1] * i % mod;
    ifact[MX-1] = inv(fact[MX-1]);
    for (int i=MX-1; i>0; i--) ifact[i-1] = ifact[i] * i % mod;

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i<m; i++) cin >> t[i];

    for (int i=0; i<n; i++) cnt[s[i]]++;

    int curMult = 1;
    for (int i=0; i<MX; i++)
        curMult = curMult * ifact[cnt[i]] % mod;
    for (int i=0; i<MX; i++)
        addft(i, cnt[i]);
    
    int ans = 0;
    for (int i=0; i<m; i++) {
        if (i == n - 1) {
            // special case when s is a prefix of y
            if (i != m - 1 && cnt[t[i]])
                ans += 1;
        }

        ans += fact[n - i - 1] * curMult % mod * getft(t[i] - 1) % mod;

        // update
        if (cnt[t[i]] == 0) break;
        curMult = curMult * cnt[t[i]] % mod;
        cnt[t[i]]--;
        addft(t[i], -1);
    }

    ans %= mod;
    cout << ans << endl;
}