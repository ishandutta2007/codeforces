#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef double db;
const int N = 1e6 + 10, P = 998244353;
int vis[N], pr[N], phi[N], tot = 0;
int fac[N], ifac[N];
int power(int a, int b, int c = 1) {
    for(; b; b >>= 1, a = (ll)a * a % P) if(b & 1) c = (ll)c * a % P;
    return c;
}
void initmath(int n) {
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = (ll)fac[i - 1] * i % P;
    ifac[n] = power(fac[n], P - 2);
    for(int i = n - 1; i >= 0; i--) ifac[i] = (ll)ifac[i + 1] * (i + 1) % P;
    return;
}
void sieve(int n) {
    vis[1] = phi[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) pr[++tot] = i, phi[i] = i - 1;
        for(int j = 1; j <= tot && i * pr[j] <= n; j++) {
            vis[i * pr[j]] = 1;
            if(i % pr[j] == 0) {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * (pr[j] - 1);
        }
    }
    return;
}
int n, a[N], cnt[N], buc[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        if(cnt[a[i]]) {
            buc[++tot] = cnt[a[i]];
            cnt[a[i]] = 0;
        }
    }
    int g = 0;
    for(int i = 1; i <= tot; i++) g = __gcd(g, buc[i]);
    int cnt = 0, sum = 0;
    for(int i = 1; i <= g; i++) {
        if(g % i) continue;
        int prod = 1, suma = 0, sum2 = 0;
        for(int j = 1; j <= tot; j++) {
            prod = (ll)prod * ifac[buc[j] / i] % P;
            (suma += buc[j] / i) %= P;
            (sum2 += (ll)buc[j] / i * buc[j] / i % P) %= P;
        }
        (cnt += (ll)prod * fac[n / i] % P * phi[i] % P) %= P;
        int v = ((ll)suma * suma % P - sum2 + P) % P;
        v = (ll)v * n % P;
        if(tot == 1) (sum += phi[i]) %= P;
        else (sum += (ll)prod * fac[n / i - 2] % P * v % P * phi[i] % P) %= P; 
    }
    // cout << cnt << endl;
    sum = (ll)sum * power(cnt, P - 2) % P;
    cout << sum << endl;
    for(int i = 1; i <= n; i++) ::cnt[a[i]] = 0;
    return;
}
int main() {
    sieve(N - 10);
    initmath(N - 10);
    int t;
    for(cin >> t; t--; ) {
        solve();
    }
    return 0;
}