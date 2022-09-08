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

const double eps = 1e-10;
const int N = 3e5 + 5;

ll s[N], sum, maxn;
int a[N], q[N];
int n, top;

inline double slope1(int a, int b) { return (double)(s[b - 1] - s[a - 1]) / (b - a); }
inline ll calc1(int a, int b) { return s[b - 1] - s[a - 1] - 1ll * ::a[b] * (b - a); }
inline double slope2(int a, int b) { return (double)(s[b] - s[a]) / (b - a); }
inline ll calc2(int a, int b) { return s[a] - s[b] + 1ll * ::a[a] * (b - a); }

int main() {
//    freopen("cute.in", "r", stdin);
//    freopen("cute.out", "w", stdout);
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), sum += 1ll * a[i] * i, s[i] = s[i - 1] + a[i];
    maxn = sum;
    for(register int i = 1; i <= n; i++) {
        if(i > 1) {
            int l = 2, r = top, ans = 1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(slope1(q[mid - 1], q[mid]) <= a[i]) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            maxn = max(maxn, sum + calc1(q[ans], i));
        }
        while(top >= 2 && slope1(q[top - 1], q[top]) >= slope1(q[top], i) - eps) --top;
        q[++top] = i;
    }
    top = 0;
    for(register int i = n; i >= 1; i--) {
        if(i < n) {
            int l = 2, r = top, ans = 1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(slope2(q[mid - 1], q[mid]) >= a[i]) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            maxn = max(maxn, sum + calc2(i, q[ans]));
        }
        while(top >= 2 && slope2(q[top - 1], q[top]) <= slope2(q[top], i) + eps) --top;
        q[++top] = i;
    }
    print(maxn, '\n');
    return 0;
}