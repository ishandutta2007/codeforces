// time-limit: 4000
// problem-url: https://codeforces.com/problemset/problem/903/G

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

template <class T, class U>
struct LazySegTree {
    typedef function<T(T, T)> F;
    typedef function<T(T, U)> G;
    typedef function<U(U, U)> H;
    public:
        LazySegTree() {}
        LazySegTree(int n, const T &e, const U &ue, const F &f, const G &fup, const H &flz): LazySegTree(vector<T>(n, e), e, ue, f, fup, flz) {}
        LazySegTree(vector<T> v, const T &e, const U &ue, const F &f, const G &fup, const H &flz): e(e), ue(ue), f(f), fup(fup), flz(flz) {
            _n = v.size();
            n = 1;
            lg = 0;
            while (n < _n) {
                n <<= 1;
                lg++;
            }
            seg = vector<T>(2 * n, e);
            lz = vector<U>(n, ue);
            REP (i, 0, _n) {
                seg[i + n] = v[i];
            }
            RREP (i, n - 1, 0) {
                pull(i);
            }
        }
        void upd(int i, const T &x) {
            assert(i >= 0 && i < _n);
            i += n;
            pushAll(i);
            seg[i] = x;
            pullAll(i);
        }
        void upd(int l, int r, const U &x) {
            if (l > r) {
                return;
            }
            mxto(l, 0); mnto(r, _n - 1);
            l += n; r += n;
            int tl = l, tr = r;
            pushAll(l); pushAll(r);
            while (l < r) {
                if (l & 1) {
                    put(l++, x);
                }
                if (r & 1 ^ 1) {
                    put(r--, x);
                }
                l >>= 1; r >>= 1;
            }
            if (l == r) {
                put(l, x);
            }
            while (tl & 1 ^ 1) {
                tl >>= 1;
            }
            while (tr & 1) {
                tr >>= 1;
            }
            pullAll(tl); pullAll(tr);
        }
        T qry(int l, int r) {
            if (l > r) {
                return e;
            }
            mxto(l, 0); mnto(r, _n - 1);
            l += n; r += n;
            pushAll(l); pushAll(r);
            T lans = e, rans = e;
            while (l < r) {
                if (l & 1) {
                    lans = f(lans, seg[l++]);
                }
                if (r & 1 ^ 1) {
                    rans = f(seg[r--], rans);
                }
                l >>= 1; r >>= 1;
            }
            if (l == r) {
                lans = f(lans, seg[l]);
            }
            return f(lans, rans);
        }
        T qryAll() {
            return seg[1];
        }
        // returns minimum x such that l <= x and 
        // cond(x) = true and cond(x - 1) = false
        template <class C>
        int findFirst(int l, const C &cond) {
            if (l >= _n) {
                return _n;
            } 
            l += n;
            pushAll(l);
            T cur = e;
            do {
                while (l & 1 ^ 1) {
                    l >>= 1;
                }
                if (cond(f(cur, seg[l]))) {
                    while (l < n) {
                        push(l);
                        l <<= 1;
                        if (!cond(f(cur, seg[l]))) {
                            cur = f(cur, seg[l]);
                            l++;
                        }
                    }
                    return l - n;
                }
                cur = f(cur, seg[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }
        // find maximum x such that x <= r and
        // cond(x) = true and cond(x + 1) = false
        template <class C>
        int findLast(int r, const C &cond) {
            if (r < 0) {
                return -1;
            }
            mnto(r, _n - 1);
            r += n;
            pushAll(r);
            T cur = e;
            while (1) {
                while (r > 1 && r & 1) {
                    r >>= 1;
                }
                if (cond(f(seg[r], cur))) {
                    while (r < n) {
                        push(r);
                        r = r << 1 ^ 1;
                        if (!cond(f(seg[r], cur))) {
                            cur = f(seg[r], cur);
                            r--;
                        }
                    }
                    return r - n;
                }
                if ((r & -r) == r) {
                    break;
                }
                r--;
            }
            return -1;
        }
        T operator[](int i) {
            pushAll(i + n);
            return seg[i + n];
        }
        friend ostream& operator<<(ostream &os, const LazySegTree &o) {
            os << '[';
            REP (i, 0, o._n) {
                os << o[i];
                if (i != o._n - 1) {
                    os << ", ";
                }
            }
            os << ']';
            return os;
        }
    private:
        int n, _n, lg;
        vector<T> seg;
        const T e;
        vector<U> lz;
        const U ue;
        const F f;
        const G fup;
        const H flz;
        inline void pull(int u) {
            seg[u] = f(seg[u << 1], seg[u << 1 ^ 1]);
        }
        inline void put(int u, const U &x) {
            seg[u] = fup(seg[u], x);
            if (u < n) {
                lz[u] = flz(lz[u], x);
            }
        }
        inline void push(int u) {
            put(u << 1, lz[u]);
            put(u << 1 ^ 1, lz[u]);
            lz[u] = ue;
        }
        void pullAll(int u) {
            u >>= 1;
            while (u) {
                pull(u);
                u >>= 1;
            }
        }
        void pushAll(int u) {
            RREP (k, lg, 1) {
                push(u >> k);
            }
        }
};

template <class T>
class SegTree {
    typedef function<T(T, T)> F;
    public:
        SegTree() {}
        SegTree(int n, const T &e, const F &f): SegTree(vector<T>(n, e), e, f) {}
        SegTree(const vector<T>& v, const T &e, const F &f): e(e), f(f) {
            _n = v.size();
            n = 1;
            while (n < _n) {
                n <<= 1;
            }
            seg = vector<T>(2 * n, e);
            REP (i, 0, _n) {
                seg[i + n] = v[i];
            }
            RREP (i, n - 1, 0) {
                pull(i);
            }
        }
        void upd(int i, const T &x) {
            i += n;
            seg[i] = x;
            for (i >>= 1; i > 0; i >>= 1) {
                pull(i);
            }
        }
        T qry(int l, int r) {
            if (l > r) {
                return e;
            }
            mxto(l, 0); mnto(r, _n - 1);
            l += n, r += n;
            T lans = e, rans = e;
            while (l < r) {
                if (l & 1) {
                    lans = f(lans, seg[l++]);
                }
                if (r & 1 ^ 1) {
                    rans = f(seg[r--], rans);
                }
                l >>= 1, r >>= 1;
            }
            if (l == r) {
                lans = f(lans, seg[l]);
            }
            return f(lans, rans);
        }
        T qryAll() {
            return seg[1];
        }
        // returns minimum x such that l <= x and 
        // cond(x) = true and cond(x - 1) = false
        template <class C>
        int findFirst(int l, const C &cond) {
            if (l >= _n) {
                return _n;
            } 
            l += n;
            T cur = e;
            do {
                while (l & 1 ^ 1) {
                    l >>= 1;
                }
                if (cond(f(cur, seg[l]))) {
                    while (l < n) {
                        l <<= 1;
                        if (!cond(f(cur, seg[l]))) {
                            cur = f(cur, seg[l]);
                            l++;
                        }
                    }
                    return l - n;
                }
                cur = f(cur, seg[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }
        // find maximum x such that x <= r and
        // cond(x) = true and cond(x + 1) = false
        template <class C>
        int findLast(int r, const C &cond) {
            if (r < 0) {
                return -1;
            }
            mnto(r, _n - 1);
            r += n;
            T cur = e;
            while (1) {
                while (r > 1 && r & 1) {
                    r >>= 1;
                }
                if (cond(f(seg[r], cur))) {
                    while (r < n) {
                        r = r << 1 ^ 1;
                        if (!cond(f(seg[r], cur))) {
                            cur = f(seg[r], cur);
                            r--;
                        }
                    }
                    return r - n;
                }
                if ((r & -r) == r) {
                    break;
                }
                r--;
            }
            return -1;
        }
        T operator[](int i) const {
            assert(i < n);
            return seg[i + n];
        }
        friend ostream& operator<<(ostream &os, const SegTree &o) {
            os << '[';
            REP (i, 0, o._n) {
                os << o[i];
                if (i != o._n - 1) {
                    os << ", ";
                }
            }
            os << ']';
            return os;
        }
    private:
        int n, _n;
        vector<T> seg;
        const T e;
        const F f;
        inline void pull(int u) {
            seg[u] = f(seg[u << 1], seg[u << 1 ^ 1]);
        }
};

int n, m, q;
int x[MAXN], y[MAXN];
vii adj[MAXN];

ll f(ll l, ll r) {
    return min(l, r);
}
ll fup(ll l, ll x) {
    return l + x;
}
ll flz(ll l, ll r) {
    return l + r;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m >> q;
    REP (i, 0, n - 1) {
        cin >> x[i] >> y[i + 1];
    }
    REP (i, 0, m) {
        int x, y, z; cin >> x >> y >> z;
        x--; y--;
        adj[x].pb(MP(y, z));
    }
    vll bv(n);
    REP (i, 0, n) {
        bv[i] = y[i];
    }
    LazySegTree<ll, ll> bsg(bv, LINF, 0, f, fup, flz);
    vll av(n);
    REP (u, 0, n) {
        for (auto [v, w] : adj[u]) {
            bsg.upd(0, v, w);
        }
        av[u] = bsg.qryAll() + x[u];
    }
    SegTree<ll> asg(av, LINF, f);
    cout << asg.qryAll() << '\n';
    while (q--) {
        int v, w; cin >> v >> w;
        v--;
        asg.upd(v, asg[v] - x[v] + w);
        x[v] = w;
        cout << asg.qryAll() << '\n';
    }
    return 0;
}