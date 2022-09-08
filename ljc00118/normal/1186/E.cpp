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
 
const int N = 1005;
 
char c[N][N];
int s[N][N], a[N][N];
int n, m, q;
 
bool check(int x, int y) {
    if(x <= 2 && y <= 2) return (x + y) & 1;
    if(x > 2) {
        int now = 1;
        while((now << 1) < x) now <<= 1;
        return check(x - now, y) ^ 1;
    } else {
        int now = 1;
        while((now << 1) < y) now <<= 1;
        return check(x, y - now) ^ 1;
    }
}
 
inline ll solve(int x, int y) {
    // cout << x << " " << y << " ";
    int _x = x / n, _y = y / m;
    ll ans = 0;
    // cout << ans << endl;
    ans += 1ll * _x * _y / 2 * n * m;
    if((_x * _y) & 1) {
        if(check(_x, _y)) ans += n * m - s[n][m];
        else ans += s[n][m];
    }
    x = x - _x * n; y = y - _y * m;
    ans += 1ll * _x / 2 * n * y;
    if(_x & 1) {
        if(!check(_x, _y + 1)) ans += s[n][y];
        else ans += n * y - s[n][y];
    }
    ans += 1ll * _y / 2 * x * m;
    if(_y & 1) {
        if(!check(_x + 1, _y)) ans += s[x][m];
        else ans += x * m - s[x][m];
    }
    if(check(_x + 1, _y + 1)) ans += x * y - s[x][y];
    else ans += s[x][y];
    return ans;
}
 
int main() {
    read(n); read(m); read(q);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c[i] + 1);
        for(register int j = 1; j <= m; j++) {
            a[i][j] = c[i][j] - '0';
            s[i][j] = s[i][j - 1] + a[i][j];
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            s[i][j] += s[i - 1][j];
        }
    }
    while(q--) {
        int x, y, _x, _y;
        read(x); read(y); read(_x); read(_y);
        print(solve(_x, _y) - solve(_x, y - 1) - solve(x - 1, _y) + solve(x - 1, y - 1), '\n');
    }
    return 0;
}