#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1 << 20;
const double pi = acos(-1.0);

struct cp {
    double x, y;
    cp (double xx = 0, double yy = 0) : x(xx), y(yy) {}
} a[N], b[N];

cp operator + (const cp a, const cp b) { return cp(a.x + b.x, a.y + b.y); }
cp operator - (const cp a, const cp b) { return cp(a.x - b.x, a.y - b.y); }
cp operator * (const cp a, const cp b) { return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }

int s[N], cnt[N], rev[N];
int n, x, nbase; ll ans;

void fft(cp *a, int opt) {
    for(register int i = 1; i < (1 << nbase); i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(register int mid = 1; mid < (1 << nbase); mid <<= 1) {
        cp wn = cp(cos(pi / mid), sin(pi / mid) * opt);
        for(register int i = 0; i < (1 << nbase); i += (mid << 1)) {
            cp w = cp(1.0, 0.0);
            for(register int j = 0; j < mid; j++, w = w * wn) {
                cp x = a[i + j], y = a[i + j + mid] * w;
                a[i + j] = x + y; a[i + j + mid] = x - y;
            }
        }
    }
}

int main() {
    read(n); read(x); cnt[0]++;
    for(register int i = 1; i <= n; i++) {
        int v; read(v);
        s[i] = s[i - 1] + (v < x);
        ++cnt[s[i]];
    }
    while((1 << nbase) < s[n] + s[n] + 1) ++nbase;
    for(register int i = 0; i <= s[n]; i++) a[i].x = cnt[i], b[i].x = cnt[s[n] - i], ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
    for(register int i = 1; i < (1 << nbase); i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
    fft(a, 1); fft(b, 1); for(register int i = 0; i < (1 << nbase); i++) a[i] = a[i] * b[i]; fft(a, -1);
    print(ans, ' '); for(register int i = s[n] + 1; i <= s[n] + s[n]; i++) print((ll)(a[i].x / (1 << nbase) + 0.5), ' ');
    for(register int i = 1; i <= n - s[n]; i++) { print(0, ' '); } putchar('\n');
    return 0;
}