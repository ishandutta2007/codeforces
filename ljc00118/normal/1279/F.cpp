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

const int N = 1e6 + 5;

struct ele {
    int f, g;
    ele (int a = 0, int b = 0) : f(a), g(b) {}
    bool operator < (const ele A) const {
        if (f != A.f) return f < A.f;
        return g > A.g;
    }
};

ele operator + (const ele a, const ele b) { return ele(a.f + b.f, a.g + b.g); }

ele f[N];
char c[N];
int s[N];
int n, k, l;

ele dp(int mid) {
    for (int i = 0; i < l; i++) f[i] = ele(0, 0);
    for (int i = l; i <= n; i++) f[i] = max(f[i - 1], f[i - l] + ele(s[i] - s[i - l] - mid, 1));
    return f[n];
}

int solve(int opt) {
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + ((c[i] >= 'a' && c[i] <= 'z') == opt);
    int l = 0, r = n - 1, ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (dp(mid).g <= k) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return s[n] - (dp(ans).f + ans * k);
}

int main() {
    read(n); read(k); read(l); scanf("%s", c + 1);
    if (1ll * k * l > n) {
        print(0, '\n');
        return 0;
    }
    print(min(solve(0), solve(1)), '\n');
    return 0;
}