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

const int N = 1e5 + 5;

int f[N];
int n, q, l, r, rev;

inline int lowbit(int x) { return x & -x; }

void add(int x, int y) {
    for(register int i = x; i <= n; i += lowbit(i))
        f[i] += y;
}

int query(int x) {
    int ans = 0;
    for(register int i = x; i; i -= lowbit(i))
        ans += f[i];
    return ans;
}

int main() {
    read(n); read(q);
    for(register int i = 1; i <= n; i++) add(i, 1);
    l = 1, r = n;
    while(q--) {
        int opt; read(opt);
        if(opt == 1) {
            int len; read(len);
            if(len * 2 > (r - l + 1)) {
                rev ^= 1;
                len = r - l + 1 - len;
            }
            if(rev) {
                for(register int i = r, j = r - len * 2 + 1; i >= r - len + 1; i--, j++) {
                    int val = query(i) - query(i - 1);
                    add(j, val); add(i, -val);
                }
                r -= len;
            } else {
                for(register int i = l, j = l + len * 2 - 1; i <= l + len - 1; i++, j--) {
                    int val = query(i) - query(i - 1);
                    add(j, val); add(i, -val);
                }
                l += len;
            }
        }
        if(opt == 2) {
            int L, R;
            read(L); read(R); ++L;
            // fprintf(stderr, "l = %d, r = %d, L = %d, R = %d, rev = %d\n", l, r, L, R, rev);
            if(rev) print(query(r - L + 1) - query(r - R), '\n');
            else print(query(R + l - 1) - query(L - 1 + l - 1), '\n');
        }
    }
    return 0;
}