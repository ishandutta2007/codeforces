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

const int N = 1e5 + 5;

struct node_t {
    int l, r;
    mutable ll v;

    node_t () {}

    node_t (int L, int R, ll V) : l(L), r(R), v(V) {}

    bool operator < (const node_t A) const { return l < A.l; }
};

set <node_t> rt;
#define IT set <node_t> :: iterator
int a[N];
int n, m, seed, vmax;

inline int rnd() {
    int ans = seed;
    seed = ((ll)seed * 7 + 13) % 1000000007;
    return ans;
}

IT split(int pos) {
    IT it = rt.lower_bound(node_t(pos, pos, 0));
    if(it != rt.end() && it -> l == pos) return it;
    --it; int l = it -> l, r = it -> r; ll v = it -> v;
    rt.erase(it); rt.insert(node_t(l, pos - 1, v));
    return rt.insert(node_t(pos, r, v)).first;
}

void assign(int l, int r, int v) {
    split(l); IT itr = split(r + 1), itl = split(l);
    rt.erase(itl, itr);
    rt.insert(node_t(l, r, v));
}

void add(int l, int r, int v) {
    split(l); IT itr = split(r + 1), itl = split(l);
    for(; itl != itr; ++itl) itl -> v += v;
}

vector < pair <ll, int> > wxw;
ll rnk(int l, int r, int k) {
    wxw.clear();
    split(l); IT itr = split(r + 1), itl = split(l);
    for(; itl != itr; ++itl) wxw.push_back(make_pair(itl -> v, itl -> r - itl -> l + 1));
    sort(wxw.begin(), wxw.end());
    for(register unsigned i = 0; i < wxw.size(); i++) {
        k -= wxw[i].second;
        if(k <= 0) return wxw[i].first;
    }
    throw "k > r - l + 1";
}

inline int fpow(int x, int y, int md) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = (ll)ans * x % md;
        y >>= 1; x = (ll)x * x % md;
    }
    return ans;
}

ll sum(int l, int r, int k, int md) {
    split(l); IT itr = split(r + 1), itl = split(l);
    int ans = 0;
    for(; itl != itr; ++itl) {
        ans += (ll)fpow(itl -> v % md, k, md) * (itl -> r - itl -> l + 1) % md;
        if(ans >= md) ans -= md;
    }
    return ans;
}

int main() {
    cin >> n >> m >> seed >> vmax;
    for(register int i = 1; i <= n; i++) a[i] = rnd() % vmax + 1, rt.insert(node_t(i, i, a[i]));
    rt.insert(node_t(n + 1, n + 1, 0));
    while(m--) {
        int opt = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
        if(l > r) swap(l, r);
        if(opt == 1) {
            int x = rnd() % vmax + 1;
            add(l, r, x);
        }
        if(opt == 2) {
            int x = rnd() % vmax + 1;
            assign(l, r, x);
        }
        if(opt == 3) {
            int k = rnd() % (r - l + 1) + 1;
            print(rnk(l, r, k), '\n');
        }
        if(opt == 4) {
            int x = rnd() % vmax + 1, y = rnd() % vmax + 1;
            print(sum(l, r, x, y), '\n');
        }
    }
    return 0;
}