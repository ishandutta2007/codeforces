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

const int N = 50005;

queue < pair <bitset <163>, int> > q;
bitset <163> f[N];
ll dp[20][N], s[20][N][10];
int nxt[N][10], sum[N];

struct qwq { bitset <163> x; } tmp;

bool cmp(bitset <163> a, bitset <163> b) {
    if (a == b) return 0;
    int pos = (a ^ b)._Find_first();
    return a[pos] < b[pos];
}

bool operator < (const qwq a, const qwq b) { return cmp(a.x, b.x); }

struct atom {
    ll l, r; int id;
    atom (ll a = 0, ll b = 0, int c = 0) : l(a), r(b), id(c) {}
};

vector <atom> qq[10];
set <qwq> all;
ll ans[N];
int b[20];
int n, len;

ll calc(ll x) {
    int m = 0;
    while (x) {
        b[++m] = x % 10;
        x /= 10;
    }
    ll ans = 0;
    int now = 1;
    for (int i = m; i >= 1; i--) {
        if (b[i]) ans += s[i][now][b[i] - 1];
        now = nxt[now][b[i]];
    }
    return ans + dp[0][now];
}

int main() {
    f[0][0] = 1; q.push(make_pair(f[0], 0)); tmp.x = f[0]; all.insert(tmp);
    while (!q.empty()) {
        bitset <163> u = q.front().first; int sum = q.front().second; q.pop();
        for (int i = 1; i <= min(9, 162 - sum); i++) {
            bitset <163> v = u | (u << i);
            tmp.x = v;
            if (all.find(tmp) != all.end()) continue;
            q.push(make_pair(v, sum + i));
            all.insert(tmp);
        }
    }
    for (auto i : all) f[++len] = i.x;
    for (int i = 1; i <= len; i++) {
        for (int j = 162; j >= 0; j--) {
            if (f[i][j]) {
                sum[i] = j;
                break;
            }
        }
        nxt[i][0] = i;
        for (int j = 1; j <= min(9, 162 - sum[i]); j++) {
            bitset <163> v = f[i] | (f[i] << j);
            nxt[i][j] = lower_bound(f + 1, f + len + 1, v, cmp) - f;
        }
    }
    read(n);
    for (int i = 1; i <= n; i++) {
        ll l, r; int k;
        read(l); read(r); read(k);
        qq[k].push_back(atom(l, r, i));
    }
    for (int _ = 0; _ <= 9; _++) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; i++) {
            int cando = 0;
            for (int j = sum[i] / 2; j >= 0; j--) {
                if (sum[i] - 2 * j > _) break;
                if (f[i][j]) {
                    cando = 1;
                    break;
                }
            }
            dp[0][i] = cando;
        }
        for (int i = 1; i <= 19; i++) {
            for (int j = 1; j <= len; j++) {
                for (int k = 0; k <= 9; k++) {
                    ll val = dp[i - 1][nxt[j][k]];
                    s[i][j][k] = val + (k == 0 ? 0 : s[i][j][k - 1]);
                    // if (_ == 0 && i == 1 && j == 1) fprintf(stderr, "k = %d, val = %lld, %lld\n", k, val, s[i][j][k]);
                }
                dp[i][j] = s[i][j][9];
                // if (_ == 0 && i == 1 && j == 1) fprintf(stderr, "dp[%d][%d] = %lld\n", i, j, dp[i][j]);
            }
        }
        for (auto i : qq[_]) ans[i.id] = calc(i.r) - calc(i.l - 1);
    }
    for (int i = 1; i <= n; i++) print(ans[i], '\n');
    return 0;
}