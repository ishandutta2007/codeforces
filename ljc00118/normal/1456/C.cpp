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

const int N = 5e5 + 5;

ll v1[N], v2[N], v3[N], s3[N], s2[N], sum[N], ans = -1e18;
int a[N], b[N];
int n, k, al, bl;

int main() {
    read(n); read(k);
    for (int i = 1; i <= n; i++) {
        int x; read(x);
        if (x >= 0) a[++al] = x;
        else b[++bl] = x;
    }
    sort(a + 1, a + al + 1);
    sort(b + 1, b + bl + 1);
    if (k == 0) {
        ll ans = 0;
        for (int i = 1; i <= bl; i++) ans += 1ll * b[i] * (i - 1);
        for (int i = 1; i <= al; i++) ans += 1ll * a[i] * (i + bl - 1);
        print(ans, '\n');
        return 0;
    }
    for (int i = 1; i <= bl; i++) {
        int now = (i - 1) / (k + 1);
        v1[i] = v1[i - 1] + 1ll * b[i] * now;
    }
    ll tmp = 0;
    for (int i = bl; i >= 1; i--) {
        v2[i] = v2[i + 1] + tmp;
        tmp += b[i];
        s2[i] = tmp;
    }
    for (int i = bl; i >= 1; i--) {
        v3[i] = v3[i + 1] + sum[i % k];
        s3[i] = s3[i + 1] + b[i];
        sum[i % k] += b[i];
    }
    tmp = 0;
    ll res = 0;
    for (int i = 1; i <= al; i++) res += 1ll * a[i] * (i - 1), tmp += a[i];
    for (int i = 0; i <= bl; i++) {
        int oth = bl - i, h = (oth + k - 1) / k;
        if (i < h) {
            ans = max(ans, v1[i * (k + 1)] + v3[i * (k + 1) + 1] + s3[i + (k + 1) + 1] * i + 1ll * tmp * i);
            // cout << i << " " << ans << endl;
        } else {
            ans = max(ans, v1[h + oth] + v2[h + oth + 1] + s2[h + oth + 1] * h + 1ll * tmp * i);
        }
    }
    print(ans + res, '\n');
    return 0;
}