#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
const int N = 1e5 + 10, P = 998244353;
int n, a[N];
int fac[N], ifac[N];
map<ll, int> c1, c2;
int power(int a, int b, int c = 1) {
    for(; b; b >>= 1, a = (ll)a * a % P) if(b & 1) c = (ll)c * a % P;
    return c;
}
void initc(int n) {
    fac[0] = 1;
    FOR(i, 1, n) fac[i] = (ll)fac[i - 1] * i % P;
    ifac[n] = power(fac[n], P - 2);
    ROF(i, n - 1, 0) ifac[i] = (ll)ifac[i + 1] * (i + 1) % P;
}
int bin(int n, int m) {return n < m || m < 0 ? 0 : (ll)fac[n] * ifac[m] % P * ifac[n - m] % P; }
void solve() {
    c1.clear(), c2.clear();
    cin >> n;
    ll sum = 0;
    FOR(i, 1, n) cin >> a[i], sum += a[i];
    ll now = 0;
    FOR(i, 1, n) {
        now += a[i];
        if(i < n) c1[now]++;
    }
    now = 0;
    ROF(i, n, 1) {
        now += a[i];
        if(i > 1) c2[now]++;
    }
    int ans = 1;
    for(auto [v, c] : c1) {
        if(v * 2 == sum) {
            ans = (ll)ans * power(2, c) % P;
        } else if(v * 2 < sum) {
            int cl = c, cr = c2[v];
            ans = (ll)ans * bin(cl + cr, cr) % P;
        }
    }
    cout << ans << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    initc(N - 10);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}