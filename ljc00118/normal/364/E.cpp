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

const int N = 2505;

int s[N][N], mx[N], mn[N];
char c[N][N];
int n, m, k;
ll ans;

inline int calc(int x, int y, int _x, int _y) {
    if(x > _x || y > _y) return 0;
    return s[_x][_y] - s[_x][y - 1] - s[x - 1][_y] + s[x - 1][y - 1];
}

void solve(int x, int y, int _x, int _y) {
    if(x == _x || y == _y) return;
    if(_x - x == 1 && _y - y == 1) {
        if(calc(x + 1, y + 1, _x, _y) == k) ++ans;
        return;
    }
    if(_x - x >= _y - y) {
        int mid = (x + _x) >> 1;
        solve(x, y, mid, _y); solve(mid, y, _x, _y);
        for(register int i = y + 1; i <= _y; i++) {
            mn[0] = mx[0] = mid;
            for(register int j = 1; j <= k + 1; j++) mn[j] = x, mx[j] = _x;
            for(register int j = i; j <= _y; j++) {
                for(register int t = 1; t <= k + 1; t++) {
                    while(calc(mn[t] + 1, i, mid, j) >= t) ++mn[t];
                    while(calc(mid + 1, i, mx[t], j) >= t) --mx[t];
                }
                for(register int t = 0; t <= k; t++) {
                    ans += (mn[t] - mn[t + 1]) * (mx[k - t + 1] - mx[k - t]);
                }
            }
        }
    } else {
        int mid = (y + _y) >> 1;
        solve(x, y, _x, mid); solve(x, mid, _x, _y);
        for(register int i = x + 1; i <= _x; i++) {
            mn[0] = mx[0] = mid;
            for(register int j = 1; j <= k + 1; j++) mn[j] = y, mx[j] = _y;
            for(register int j = i; j <= _x; j++) {
                for(register int t = 1; t <= k + 1; t++) {
                    while(calc(i, mn[t] + 1, j, mid) >= t) ++mn[t];
                    while(calc(i, mid + 1, j, mx[t]) >= t) --mx[t];
                }
                for(register int t = 0; t <= k; t++) {
                    ans += (mn[t] - mn[t + 1]) * (mx[k - t + 1] - mx[k - t]);
                }
            }
        }
    }
}

int main() {
    read(n); read(m); read(k);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c[i] + 1);
        for(register int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + c[i][j] - '0';
        }
    }
    solve(0, 0, n, m);
    print(ans, '\n');
    return 0;
}