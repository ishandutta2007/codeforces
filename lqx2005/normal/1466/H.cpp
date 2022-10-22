#include <bits/stdc++.h>
#define par pair<int, int>
#define mp make_pair
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int P = 1e9 + 7;
const int N = 50;
struct mint {
    int x;
    mint() {x = 0; }
    mint(int _x) {x = _x; }
    friend mint operator + (const mint a, const mint b) {return (a.x + b.x) % P; }
    friend mint operator - (const mint a, const mint b) {return (a.x - b.x + P) % P; }
    friend mint operator * (const mint a, const mint b) {return 1ll * a.x * b.x % P; }
    friend mint operator ^ (mint a, int b) {
        mint c(1);
        for(; b; b >>= 1, a = a * a) if(b & 1) c = c * a;
        return c;
    }
    friend mint operator / (mint a, mint b) {return a * (b ^ (P - 2)); }
    friend mint &operator += (mint &a, const mint b) {return a = a + b; }
    friend mint &operator -= (mint &a, const mint b) {return a = a - b; }
    friend mint &operator *= (mint &a, const mint b) {return a = a * b; }
    friend mint &operator /= (mint &a, const mint b) {return a = a / b; }
    friend mint operator -(const mint a) {return 0 - a;}
} fac[N], ifac[N], inv[N];
void initmath(int n) {
    inv[1] = fac[0] = ifac[0] = 1;
    for(int i = 2; i <= n; i++) inv[i] = inv[P % i] * (P - P / i);
    for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * inv[i];
    return;
}
mint binom(int n, int m) {return n < m || m < 0 ? 0 : fac[n] * ifac[m] * ifac[n - m]; }
int n, b[N], vis[N], siz[N];
mint coef[N][N];
map<vector<int>, mint> dp;
mint DP(vector<int> cnt);
mint brute(vector<int> cnt, int x, int s, int t);
mint brute(vector<int> cnt, int x, int s, int t) {
    if(x == n + 1) {
        if(s > 0) return coef[s][t] * DP(cnt);
        else return 0;
    }
    mint res = 0;
    for(int i = cnt[x]; i >= 0; i--) {
        vector<int> nxt = cnt;
        nxt[x] -= i;
        res = -res, res += brute(nxt, x + 1, s + i * x, t + (cnt[x] - i) * x) * binom(cnt[x], i);
    }
    return res;
}
mint DP(vector<int> cnt) {
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += cnt[i];
    if(sum == 0) return 1;
    if(dp.count(cnt)) return dp[cnt];
    dp[cnt] = -brute(cnt, 1, 0, 0);
    return dp[cnt];
}
int main() {
    cin >> n;
    initmath(n);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            mint cnt = 0;
            for(int k = 0; k <= j; k++) {
                cnt += binom(j, k) * fac[k] * fac[n - 1 - k];
            }
            coef[i][j] = 1;
            for(int k = 1; k <= i; k++) coef[i][j] *= cnt;
        }
    }
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        int cnt = 0;
        for(int x = i; !vis[x]; vis[x] = 1, cnt++, x = b[x]);
        a[cnt]++;
    }
    cout << DP(a).x << endl;
    return 0;
}