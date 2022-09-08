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

vector <pii> dp[N], res;
int f[N], s[N], a[N];
int n, ans;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
    for(register int l = 1; l <= n; l++) {
        for(register int r = l; r <= n; r++) {
            int now = s[r] - s[l - 1];
            f[r] = 1;
            dp[r].clear(); dp[r].push_back(make_pair(l, r));
            for(register int i = r + 1; i <= n; i++) {
                f[i] = f[i - 1]; dp[i] = dp[i - 1];
                for(register int j = r + 1; j <= i; j++) {
                    if(s[i] - s[j - 1] == now) {
                        if(f[j - 1] + 1 > f[i]) {
                            f[i] = f[j - 1] + 1;
                            dp[i] = dp[j - 1];
                            dp[i].push_back(make_pair(j, i));
                        }
                    }
                }
            }
            if(f[n] > ans) {
                ans = f[n];
                res = dp[n];
            }
        }
    }
    cout << ans << endl;
    for(register int i = 0; i < ans; i++) {
        print(res[i].first, ' ');
        print(res[i].second, '\n');
    }
    return 0;
}