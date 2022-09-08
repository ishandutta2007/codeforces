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
 
const int INF = 0x7fffffff;
 
int T, n, x, y, _x, _y;
 
int main() {
    read(T);
    while(T--) {
        read(n);
        x = y = -INF; _x = _y = INF;
        for(register int i = 1; i <= n; i++) {
            int a, b, c, d, e, f;
            read(a); read(b); read(c); read(d); read(e); read(f);
            if(!c) x = max(x, a);
            if(!f) y = max(y, b);
            if(!e) _x = min(_x, a);
            if(!d) _y = min(_y, b);
        }
        if(x <= _x && y <= _y) {
            int ansx, ansy;
            if(x == -INF) {
                if(_x == INF) ansx = 0;
                else ansx = _x;
            } else ansx = x;
            if(y == -INF) {
                if(_y == INF) ansy = 0;
                else ansy = _y;
            } else ansy = y;
            print(1, ' '), print(ansx, ' '), print(ansy, '\n');
        } else print(0, '\n');
    }
    return 0;
}