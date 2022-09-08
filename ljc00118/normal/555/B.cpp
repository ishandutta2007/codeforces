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

const int N = 2e5 + 5;

struct ele {
    ll l, r; int id;
    ele (ll L = 0, ll R = 0, int d = 0) : l(L), r(R), id(d) {}
    bool operator < (const ele A) const {
        if(r != A.r) return r < A.r;
        return l < A.l;
    }
} p[N];

set < pair <ll, int> > wxw;
set < pair <ll, int> > :: iterator it;
ll l[N], r[N];
int ans[N];
int n, m;

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) read(l[i]), read(r[i]);
    for(register int i = 1; i <= m; i++) {
        ll t; read(t);
        wxw.insert(make_pair(t, i));
    }
    for(register int i = 1; i < n; i++) p[i] = ele(l[i + 1] - r[i], r[i + 1] - l[i], i);
    sort(p + 1, p + n);
    for(register int i = 1; i < n; i++) {
        it = wxw.lower_bound(make_pair(p[i].l, 0));
        if(it == wxw.end() || it -> first > p[i].r) {
            cout << "No" << endl;
            return 0;
        }
        ans[p[i].id] = it -> second;
        wxw.erase(it);
    }
    cout << "Yes" << endl;
    for(register int i = 1; i < n; i++) print(ans[i], ' ');
    putchar('\n');
    return 0;
}