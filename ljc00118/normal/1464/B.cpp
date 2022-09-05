#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 1e5 + 5;

char c[N];
ll a[N], b[N], ans;
int cnt[2][N];
int n, x, y;

int main() {
    scanf("%s", c + 1); read(x); read(y); n = strlen(c + 1);
    if (x > y) {
        for (int i = 1; i <= n; i++) {
            if (c[i] == '0') c[i] = '1';
            else if (c[i] == '1') c[i] = '0';
        }
        swap(x, y);
    }
    ll tmp = 0;
    for (int i = 1; i <= n; i++) {
        cnt[0][i] = cnt[0][i - 1];
        cnt[1][i] = cnt[1][i - 1];
        if (c[i] == '0') tmp += 1ll * cnt[1][i] * y;
        if (c[i] == '1') tmp += 1ll * cnt[0][i] * x;
        if (c[i] == '0' || c[i] == '1') ++cnt[c[i] - '0'][i];
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] == '?') {
            ++tot;
            a[tot] = a[tot - 1] + 1ll * y * cnt[1][i] + 1ll * x * (cnt[1][n] - cnt[1][i]);
        }
    }
    tot = 0;
    for (int i = n; i >= 1; i--) {
        if (c[i] == '?') {
            ++tot;
            b[tot] = b[tot - 1] + 1ll * y * (cnt[0][n] - cnt[0][i]) + 1ll * x * cnt[0][i];
        }
    }
    ans = 1e18;
    for (int i = 0; i <= tot; i++) ans = min(ans, a[i] + b[tot - i] + 1ll * i * (tot - i) * x);
    print(ans + tmp, '\n');
    return 0;
}