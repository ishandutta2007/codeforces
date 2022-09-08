#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 55;

ll f[N][N * 2][2], pw[N];
ll s, ans;

int main() {
    read(s);
    pw[0] = f[0][0][0] = 1;
    for(register int i = 1; i <= 50; i++) pw[i] = pw[i - 1] + pw[i - 1];
    for(register int a = 0; a <= 49; a++) {
        for(register int b = 0; b <= 49; b++) {
            if(!a && !b) { ++ans; continue; }
            ll x = (s - pw[b] + 1) / (pw[a + 1] + pw[b + 1] - 3);
            if(x <= 0) break;
            if(!a && b == 1) { ans += (s == x * 3 + 1); continue; }
            if(!b && a == 1) { ans += (s == x * 3); continue; }
            if(a == 1 && b == 1) { ans += (s == 5 * x + 1); continue; }
            // fprintf(stderr, "a = %d, b = %d, %I64d, %I64d\n", a, b, s - pw[b + 1] + 1, pw[a + 1] + pw[b + 1] - 3);
            ll last = s - (pw[a + 1] + pw[b + 1] - 3) * x - pw[b] + 1;
            if(!last) { ++ans; continue; }
            for(register int i = 0; i <= a + b - (a != 0) - (b != 0); i++) {
                ll now = last + i;
                if(now & 1) continue;
                int lim = max(a - 1, b - 1) + 1;
                if(now >= (1ll << (lim + 1))) continue;
                for(register int j = 1; j <= lim; j++) {
                    int zt = (now >> j) & 1;
                    memset(f[j], 0, sizeof(f[j]));
                    for(register int k = 0; k <= i; k++) {
                        for(register int t = 0; t <= 1; t++) {
                            if(f[j - 1][k][t]) {
                                for(register int x = 0; x <= 1; x++) {
                                    for(register int y = 0; y <= 1; y++) {
                                        if(x && j >= a) continue;
                                        if(y && j >= b) continue;
                                        if(((t + x + y) & 1) ^ zt) continue;
                                        f[j][k + x + y][(t + x + y) >> 1] += f[j - 1][k][t];
                                    }
                                }
                            }
                        }
                    }
                }
                ans += f[lim][i][0];
                // if(f[lim][i][0]) fprintf(stderr, "i = %d, a = %d, b = %d, val = %I64d, x = %I64d, now = %I64d\n", i, a, b, f[lim][i][0], x, now);
            }
            // fprintf(stderr, "a = %d, b = %d, ans = %I64d\n", a, b, ans);
        }
    }
    print(ans, '\n');
    return 0;
}