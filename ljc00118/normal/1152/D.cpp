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

const int N = 2e3 + 5, md = 1e9 + 7;

inline void add(int &x, int y) {
    x += y;
    if(x >= md) x -= md;
}

int f[N][N], val[N][N];
int n, ans;

int main() {
    read(n);
    f[0][0] = 0;
    for(register int i = 0; i < n * 2; i++) {
        for(register int j = 0; j <= i; j++) {
            if(j) {
                if(val[i][j] == 0) {
                    if(val[i + 1][j - 1] == 0) val[i + 1][j - 1] = 1, add(f[i + 1][j - 1], f[i][j] + 1);
                    else add(f[i + 1][j - 1], f[i][j]);
                } else add(f[i + 1][j - 1], f[i][j]);
            }
            if(j < n) {
                if(val[i][j] == 0) {
                    if(val[i + 1][j + 1] == 0) val[i + 1][j + 1] = 1, add(f[i + 1][j + 1], f[i][j] + 1);
                    else add(f[i + 1][j + 1], f[i][j]);
                } else add(f[i + 1][j + 1], f[i][j]);
            }
        }
    }
    cout << f[n * 2][0] << endl;
    return 0;
}