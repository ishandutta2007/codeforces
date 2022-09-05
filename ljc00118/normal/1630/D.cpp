#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5;

int a[N];
int T, n, m, all;

ll solve(vector <int> seq) {
    if (seq.size() == 1) return seq[0];
    ll dp[2] = {seq[0], -seq[0]};
    for (int i = 1; i < (int)seq.size() - 1; i++) {
        ll f[2];
        f[0] = max(dp[0] + seq[i], dp[1] - seq[i]);
        f[1] = max(dp[0] - seq[i], dp[1] + seq[i]);
        dp[0] = f[0]; dp[1] = f[1];
    }
    return max(dp[0] + seq[(int)seq.size() - 1], dp[1] - seq[(int)seq.size() - 1]);
}

ll solve() {
    ll ans = 0;
    for (int i = 1; i <= all; i++) {
        vector <int> seq;
        for (int j = i; j <= n; j += all) seq.push_back(a[j]);
        ans += solve(seq);
    }
    return ans;
}

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= n; i++) read(a[i]);
        read(all);
        for (int i = 1; i < m; i++) {
            int x; read(x);
            all = __gcd(all, x);
        }
        ll ans = solve();
        for (int i = 1; i <= all; i++) a[i] = -a[i];
        ans = max(ans, solve());
        print(ans, '\n');
    }
    return 0;
}