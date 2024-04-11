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

const int N = 2e5 + 5;

vector <int> sum[N];
multiset <int> val[N];
int a[N], seq[N], isp[N];
int T, n, q, len;

void solve() {
    ll ans = 0;
    for (int j = 1; j <= len; j++) {
        ans = max(ans, 1ll * (*--val[j].end()) * seq[j]);
    }
    print(ans, '\n');
}

int main() {
    for (int i = 2; i <= 200000; i++) {
        if (!isp[i]) {
            for (int j = i * 2; j <= 200000; j += i) isp[j] = 1;
        }
    }
    read(T);
    while (T--) {
        read(n); read(q);
        for (int i = 1; i <= n; i++) read(a[i]);
        len = 0;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0 && !isp[i]) {
                seq[++len] = n / i;
                sum[len].clear();
                sum[len].resize(n / i);
                val[len].clear();
                for (int j = 1; j <= n; j++) {
                    sum[len][j % seq[len]] += a[j];
                }
                for (int j = 0; j < n / i; j++) val[len].insert(sum[len][j]);
            }
        }
        solve();
        for (int i = 1; i <= q; i++) {
            int x, y;
            read(x); read(y);
            for (int j = 1; j <= len; j++) {
                val[j].erase(val[j].find(sum[j][x % seq[j]]));
                sum[j][x % seq[j]] += (y - a[x]);
                val[j].insert(sum[j][x % seq[j]]);
            }
            a[x] = y;
            solve();
        }
    }
    return 0;
}