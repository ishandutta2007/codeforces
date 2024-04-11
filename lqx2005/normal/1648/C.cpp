#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, V =  2e5, P = 998244353;
struct getsum {
    int s[N];
    void add(int x, int v) {
        v = (v + P) % P;
        for(; x <= V; x += x & (-x)) (s[x] += v) %= P;
    }
    int sum(int x) {
        int res = 0;
        for(; x > 0; x -= x & (-x)) (res += s[x]) %= P;
        return res;
    }
}ds;
int n, m, s[N], t[N], fac[N], ifac[N];
void solveone() {
    cin >> n >> m;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        s[x]++;
    }
    int prod = 1;
    for(int i = 1; i <= V; i++) {
        prod = 1ll * prod * ifac[s[i]] % P;
        ds.add(i, s[i]);
    }
    for(int i = 1; i <= m; i++) cin >> t[i];
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if(i > n) {
            (ans += 1) %= P;
            break;
        } else (ans += 1ll * ds.sum(t[i] - 1) * prod % P * fac[n - i] % P) %= P;
        if(s[t[i]] > 0) {
            ds.add(t[i], -1);
            prod = 1ll * prod * s[t[i]] % P;
            s[t[i]]--;
        } else break;
    }
    cout << ans << endl;
    return;
}
int power(int a, int b, int c = 1) {
    for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) c = 1ll * c * a % P;
    return c;
}
void initmath(int n) {
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = (ll)fac[i - 1] * i % P;
    ifac[n] = power(fac[n], P - 2);
    for(int i = n - 1; i >= 0; i--) ifac[i] = (ll)ifac[i + 1] * (i + 1) % P;
    return;
}
int main() {
    initmath(V);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solveone();
    return 0;
}