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

const int N = 2e7 + 5, M = 2e7;

ll dp[N];
int a[N], pri[N], isp[N], mn[N], go[N], s[N], cnt[N];
int n, len; ll ans;

int main() {
    for (int i = 2; i <= M; i++) {
        if (!isp[i]) {
            pri[++len] = i;
            mn[i] = i;
            go[i] = 1;
        }
        for (int j = 1; j <= len && i * pri[j] <= M; j++) {
            isp[i * pri[j]] = 1;
            mn[i * pri[j]] = pri[j];
            if (mn[i] == pri[j]) go[i * pri[j]] = go[i];
            else go[i * pri[j]] = i;
            if (i % pri[j] == 0) break;
        }
    }
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), ++cnt[a[i]];
    memcpy(s, cnt, sizeof(s));
    for (int i = 1; i <= len; i++) {
        for (int j = M / pri[i]; j >= 1; j--) {
            s[j] += s[j * pri[i]];
        }
    }
    for (int i = 1; i <= M; i++) {
        int now = i;
        while (now != 1) {
            int x = mn[now];
            dp[i] = max(dp[i], dp[i / x] + 1ll * (i / x) * (s[i / x] - s[i]));
            now = go[now];
        }
        ans = max(ans, dp[i] + 1ll * cnt[i] * i);
    }
    print(ans, '\n');
    return 0;
}