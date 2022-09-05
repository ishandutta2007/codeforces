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

const int N = 5205;

mt19937 rng(time(0));
ll mp[N][N];
int x[N], y[N], _x[N], _y[N], id[N];
int n;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

inline ll s(ll x, ll y) { return 4000005ll * x + y; }

bool check2(int i, ll tmp) {
    int pos = lower_bound(mp[i] + 1, mp[i] + 2 * n, tmp) - mp[i];
    if (pos <= 2 * n - 1 && mp[i][pos] == tmp && (pos == 2 * n - 1 || mp[i][pos] != mp[i][pos + 1])) return 1;
    return 0;
}

pii seq[N];
void check(int ansx, int ansy) {
    for (int i = 1; i <= n * 2; i++) {
        int d = max(1, gcd(abs(x[i] - ansx), abs(y[i] - ansy)));
        int _x = (x[i] - ansx) / d, _y = (y[i] - ansy) / d;
        if (_x < 0 || (_x == 0 && _y < 0)) _x = -_x, _y = -_y;
        ll tmp = s(_x, _y);
        if (!check2(i, tmp)) return;
    }
    puts("Yes");
    print(ansx, ' '); print(ansy, '\n');
    exit(0);
}

#define ld long double
#define eps 1e-6

ll INF = 1e18;

void solve(int i1, int i2, int i3, int i4) {
    ll u = 1ll * (x[i1] - x[i3]) * (y[i4] - y[i3]) - 1ll * (y[i1] - y[i3]) * (x[i4] - x[i3]);
    ll v = 1ll * (x[i4] - x[i3]) * (y[i2] - y[i3]) - 1ll * (y[i4] - y[i3]) * (x[i2] - x[i3]);
    if (u + v == 0) return;
    ll xx = x[i1] * v + x[i2] * u;
    ll yy = y[i1] * v + y[i2] * u;
    if (xx % (u + v) || yy % (u + v)) return;
    xx /= (u + v); yy /= (u + v);
    if (max(abs(xx), abs(yy)) <= 1000000) check(xx, yy);
}

int main() {
    read(n);
    for (int i = 1; i <= n * 2; i++) read(_x[i]), read(_y[i]), id[i] = i;
    shuffle(id + 1, id + n * 2 + 1, rng);
    for (int i = 1; i <= n * 2; i++) x[i] = _x[id[i]], y[i] = _y[id[i]];
    for (int i = 1; i <= n * 2; i++) {
        for (int j = i + 1; j <= n * 2; j++) {
            int d = max(1, gcd(abs(x[i] - x[j]), abs(y[i] - y[j])));
            int _x = (x[i] - x[j]) / d, _y = (y[i] - y[j]) / d;
            if (_x < 0 || (_x == 0 && _y < 0)) _x = -_x, _y = -_y;
            ll tmp = s(_x, _y); mp[i][j - (j > i)] = tmp; mp[j][i - (i > j)] = tmp;
        }
    }
    for (int i = 1; i <= n * 2; i++) sort(mp[i] + 1, mp[i] + n * 2);
    for (int i = 3; i <= n * 2; i++) {
        for (int j = 3; j <= n * 2; j++) {
            if (i != j) solve(1, i, 2, j);
            if (n <= 1000 && i < j) solve(1, 2, i, j);
        }
    }
    puts("No");
    return 0;
}