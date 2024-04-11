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

const int N = 1e5 + 5;

int a[N], ans[N][2], st[N];
int n, q, pos, now, top, maxn;

int main() {
    read(n); read(q);
    for(register int i = 1; i <= n; i++) read(a[i]), maxn = max(maxn, a[i]);
    for(register int i = 1; i <= n; i++) {
        if(a[i] == maxn) {
            pos = i;
            break;
        }
    }
    now = a[1];
    for(register int i = pos + 1; i <= n; i++) st[++top] = a[i];
    for(register int i = 2; i <= pos; i++) {
        ans[i - 1][0] = now; ans[i - 1][1] = a[i];
        if(a[i] > now) {
            st[++top] = now;
            now = a[i];
        } else st[++top] = a[i];
    }
    for(register int i = 1; i <= q; i++) {
        ll x; read(x);
        if(x < pos) {
            print(ans[x][0], ' '); print(ans[x][1], '\n');
        } else {
            int id = (x - pos + 1) % (n - 1);
            if(id == 0) id = n - 1;
            print(a[pos], ' '); print(st[id], '\n');
        }
    }
    return 0;
} //