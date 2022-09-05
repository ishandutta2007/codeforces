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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int md = 998244353, inv2 = (md + 1) / 2;

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

const int N = 1e6 + 5;

struct qwq {
    unordered_map <int, int> s[N];
    int cnt[N][2];
    int ans, cnt0;

    void del(int x, int y) {
        if (!s[x].count(y)) return;
        int tem = (cnt[x][0] > 0) + (cnt[x][1] > 0);
        if (tem == 2) --cnt0;
        int col = s[x][y] ^ (y & 1);
        s[x].erase(y);
        --cnt[x][col];
        tem = (cnt[x][0] > 0) + (cnt[x][1] > 0);
        if (tem == 2) ++cnt0;
        else if (tem == 0) ans = mul(ans, 2);
    }

    void ins(int x, int y, int col) {
        int tem = (cnt[x][0] > 0) + (cnt[x][1] > 0);
        if (tem == 0) ans = mul(ans, inv2);
        else if (tem == 2) --cnt0;
        s[x][y] = col;
        col ^= (y & 1);
        ++cnt[x][col];
        tem = (cnt[x][0] > 0) + (cnt[x][1] > 0);
        if (tem == 2) ++cnt0;
    }
} r, c;

unordered_map <int, int> s[N];
int cnt[2];
int n, m, k;

int main() {
    read(n); read(m); read(k); r.ans = fpow(2, n); c.ans = fpow(2, m);
    for (int i = 1; i <= k; i++) {
        int x, y, t;
        read(x); read(y); read(t);
        if (s[x].count(y)) --cnt[s[x][y] ^ (x & 1) ^ (y & 1)], s[x].erase(y);
        r.del(x, y); c.del(y, x);
        if (t != -1) {
            s[x][y] = t;
            r.ins(x, y, t); c.ins(y, x, t);
            ++cnt[s[x][y] ^ (x & 1) ^ (y & 1)];
        }
        int ans = 0;
        if (!r.cnt0) ans = add(ans, r.ans);
        if (!c.cnt0) ans = add(ans, c.ans);
        if (!cnt[0]) ans = sub(ans, 1);
        if (!cnt[1]) ans = sub(ans, 1);
        print(ans, '\n');
    }
    return 0;
}