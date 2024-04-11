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

const int N = 2e5 + 5;

char c[N];
unsigned a[32][N / 32 + 5], b[32][N / 32 + 5];
int n, T;

int main() {
    scanf("%s", c);
    n = strlen(c);
    for(register int j = 0; j < 32; j++) {
        for(register int i = 0; i + j < n; i++) {
            a[j][i >> 5] |= (c[i + j] == '1') * (1 << (i & 31));
        }
    }
    scanf("%s", c);
    n = strlen(c);
    for(register int j = 0; j < 32; j++) {
        for(register int i = 0; i + j < n; i++) {
            b[j][i >> 5] |= (c[i + j] == '1') * (1 << (i & 31));
        }
    }
    read(T); while(T--) {
        int x, y, len, ans = 0;
        read(x); read(y); read(len);
        register int i, j;
        for(i = (x >> 5), j = (y >> 5); len > 31; i++, j++, len -= 32) ans += __builtin_popcount(a[x & 31][i] ^ b[y & 31][j]);
        print(ans + __builtin_popcount((a[x & 31][i] ^ b[y & 31][j]) & ((1 << len) - 1)), '\n');
    }
    return 0;
}