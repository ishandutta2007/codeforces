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

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 55;

vector <int> vec;
pii seg[N];
int x[N], y[N], cnt[N];
int n, t, ans;

struct atom {
    int pos, l, r, opt;
    atom (int a = 0, int b = 0, int c = 0, int d = 0) : pos(a), l(b), r(c), opt(d) {}
} e[N * 2];

bool operator < (const atom a, const atom b) { return a.pos < b.pos; }

int f(int t) {
    memset(cnt, 0, sizeof(cnt));
    int len = 0;
    for (int i = 1; i <= n; i++) {
        e[++len] = atom(x[i] - t, y[i] - t, y[i] + t, 1);
        e[++len] = atom(x[i] + t + 1, y[i] - t, y[i] + t, -1);
        seg[i] = make_pair(y[i] - t, y[i] + t);
    }
    sort(e + 1, e + len + 1);
    sort(seg + 1, seg + n + 1);
    int ans = 0, las = 0;
    for (int i = 1; i <= len; i++) {
        int sum = 0, nowr = -2e9;
        for (int j = 1; j <= n; j++) {
            if (cnt[j]) {
                if (seg[j].first <= nowr) {
                    if (seg[j].second > nowr) {
                        sum += seg[j].second - nowr;
                        nowr = seg[j].second;
                    }
                } else {
                    sum += seg[j].second - seg[j].first + 1;
                    nowr = seg[j].second;
                }
            }
        }
        ans = add(ans, mul(e[i].pos - las, sum)); las = e[i].pos;
        int id = lower_bound(seg + 1, seg + n + 1, make_pair(e[i].l, e[i].r)) - seg;
        cnt[id] += e[i].opt;
    }
    return ans;
}

int _x[N], _y[N];
int lagrange(int n, int x) {
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int s1 = 1, s2 = 1;
        for (int j = 0; j <= n; j++) {
            if (i != j) {
                s1 = mul(s1, sub(x, _x[j]));
                s2 = mul(s2, sub(_x[i], _x[j]));
            }
        }
        ans = add(ans, mul(_y[i], mul(s1, fpow(s2, md - 2))));
    }
    return ans;
}

int main() {
    read(n); read(t);
    for (int i = 1; i <= n; i++) {
        read(x[i]); read(y[i]);
        x[i] += 5e8; y[i] += 5e8;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int len = max(abs(x[i] - x[j]), abs(y[i] - y[j]));
            vec.push_back(min(t, (len + 1) / 2));
        }
    }
    vec.push_back(0); vec.push_back(t);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < (int)vec.size() - 1; i++) {
        if (vec[i] == vec[i + 1]) continue;
        for (int j = 0; j <= 3; j++) {
            _x[j] = vec[i] + j;
            _y[j] = f(_x[j]);
            if (j) _y[j] = add(_y[j], _y[j - 1]);
        }
        ans = add(ans, lagrange(3, vec[i + 1] - 1));
    }
    ans = sub(mul(f(t), t), ans);
    print(ans, '\n');
    return 0;
}