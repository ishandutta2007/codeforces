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

const int md = 1e9 + 7, mod = 998244353;

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

int norm(int x) { return x >= mod ? x - mod : x; }
int reduce(int x) { return x < 0 ? x + mod : x; }

const int N = 1e6 + 5;

vector <int> rk[10];
int all[10], kr[N];
ll n, pw = 1;
int ans;

int tot;
void dfs1(int now) {
    if (now > n) return;
    if (now) kr[now] = ++tot;
    for (int i = (now == 0); i <= 9; i++) dfs1(now * 10 + i);
}

void dfs2(int u, int now, int len) {
    if (u != 1) {
        ++tot;
        rk[u - 1].push_back(reduce(tot - now));
    }
    if (u == len + 1) return;
    for (int i = 0; i <= 9; i++) dfs2(u + 1, now * 10 + i, len);
}

void ini(int len) {
    if (!len) return;
    tot = 0;
    for (int i = 1; i <= len; i++) rk[i].clear(), all[i] = 0;
    dfs2(1, 0, len);
    for (int i = 1; i <= len; i++) {
        sort(rk[i].begin(), rk[i].end());
        for (int j = 0; j < (int)rk[i].size(); j++) all[i] = add(all[i], rk[i][j]);
    }
}

int sum;
void dfs4(ll now) {
    if (now > n) return;
    if (now != n / pw / 10) {
        sum = norm(sum + 1);
        ans = add(ans, reduce(sum - now % mod));
    }
    for (int i = 0; i <= 9; i++) dfs4(now * 10 + i);
}

int len;
void dfs3(int u, int now) {
    if (now) {
        sum = norm(sum + 1);
        ans = add(ans, reduce(sum - now));
    }
    if (u == 7) {
        if (now == n / pw / 10) {
            dfs4(now);
            --len; ini(len);
        } else {
            int pw = 1, nsum = sum;
            for (int i = 1; i <= len; i++) {
                pw *= 10;
                int tem = reduce(sum - 1ll * now * pw % mod);
                int pos = lower_bound(rk[i].begin(), rk[i].end(), mod - tem) - rk[i].begin();
                int cnt = (int)rk[i].size() - pos;
                ans = add(ans, all[i]);
                ans = add(ans, mul((int)rk[i].size(), tem));
                ans = sub(ans, mul(mod, cnt));
                nsum = norm(nsum + (int)rk[i].size());
            }
            sum = nsum;
        }
        return;
    }
    for (int i = (now == 0); i <= 9; i++) dfs3(u + 1, now * 10 + i);
}

int main() {
    read(n);
    if (n < 1000000) {
        dfs1(0);
        for (int i = 1; i <= n; i++) {
            if (kr[i] < i) ans = add(ans, kr[i] - i + mod);
            else ans = add(ans, kr[i] - i);
        }
        print(ans, '\n');
        return 0;
    }
    while (n >= pw * 10) pw *= 10;
    pw /= 1000000;
    {
        len = 1;
        int tmp = pw;
        while (tmp != 1) {
            ++len;
            tmp /= 10;
        }
    }
    ini(len);
    dfs3(1, 0);
    print(ans, '\n');
    return 0;
}