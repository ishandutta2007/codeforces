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

struct ele {
    ll l, r; mutable int val;
    ele (ll a = 0, ll b = 0, int c = 0) : l(a), r(b), val(c) {}
    bool operator < (const ele A) const { return l < A.l; }
};

set <ele> rt;
typedef set <ele> :: iterator IT;
int h, q; ll ans;

void split(ll pos) {
    if(pos >= (1ll << h)) return;
    IT it = rt.lower_bound(ele(pos));
    if(it != rt.end() && it -> l == pos) return;
    --it;
    ll L = it -> l, R = it -> r; int v = it -> val;
    rt.erase(ele(L, R, v));
    rt.insert(ele(L, pos - 1, v));
    rt.insert(ele(pos, R, 0));
}

int main() {
    read(h); read(q);
    rt.insert(ele(1, (1ll << h) - 1, 0));
    for(register int i = 1; i <= q; i++) {
        int d, ans;
        ll l, r;
        read(d); read(l); read(r); read(ans);
        while(d < h) {
            l <<= 1;
            r <<= 1; ++r;
            ++d;
        }
        // fprintf(stderr, "l = %I64d, r = %I64d\n", l, r);
        if(ans) {
            split(l); split(r + 1);
            IT left = rt.lower_bound(ele(l));
            IT right = rt.upper_bound(ele(r));
            left -> val += 1;
            if(right != rt.end()) right -> val -= 1;
        } else {
            split(l); split(r + 1);
            IT left = rt.lower_bound(ele(l));
            IT right = rt.upper_bound(ele(r));
            rt.begin() -> val += 1; left -> val -= 1;
            right -> val += 1;
        }
    }
    split(1ll << (h - 1));
    IT now = rt.lower_bound(ele(1ll << (h - 1)));
    now -> val += 1;
    int sum = 0;
    for(IT it = rt.begin(); it != rt.end(); ++it) {
        sum += it -> val;
        // cout << it -> l << " " << it -> r << " " << sum << endl;
        if(sum == q + 1) {
            if(it -> r - it -> l + 1 > 1 || ans) {
                cout << "Data not sufficient!" << endl;
                return 0;
            }
            ans = it -> l;
        }
    }
    if(ans) cout << ans << endl;
    else cout << "Game cheated!" << endl;
    return 0;
}