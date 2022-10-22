// time-limit: 4000
// problem-url: https://codeforces.com/contest/1667/problem/B

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
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
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
#define MAXN 500005

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

int t;
int n;
pll a[MAXN];
int ra[MAXN];
int arr[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n + 5) {
            arr[i] = -INF;
        }
        a[0] = {0, 0};
        REP (i, 1, n + 1) {
            cin >> a[i].FI;
            a[i].FI += a[i - 1].FI;
            a[i].SE = i;
        }
        sort(a, a + n + 1);
        ll p = -LINF;
        int ptr = -1;
        REP (i, 0, n + 1) {
            if (a[i].FI != p) {
                ptr++;
                p = a[i].FI;
            }
            ra[a[i].SE] = ptr;
        }
        REP (i, 0, n + 1) {
            cerr << ra[i] << ' ';
        }
        cerr << '\n';
        ptr++;
        SegTree<int> mnst(ptr, -INF, [&] (int l, int r) {return max(l, r);});
        SegTree<int> mxst(ptr, -INF, [&] (int l, int r) {return max(l, r);});
        mnst.upd(ra[0], 0);
        mxst.upd(ra[0], 0);
        arr[ra[0]] = 0;
        int ans = -INF;
        REP (i, 1, n + 1) {
            int lo = i + mnst.qry(0, ra[i] - 1),
                mid = arr[ra[i]],
                hi = -i + mxst.qry(ra[i] + 1, ptr);
            cerr << i << ' ' << lo << ' ' << mid << ' ' << hi << '\n';
            int dp = max(lo, max(mid, hi));
            mxto(arr[ra[i]], dp);
            mnst.upd(ra[i], max(mnst[ra[i]], dp - i));
            mxst.upd(ra[i], max(mxst[ra[i]], dp + i));
            if (i == n) {
                ans = dp;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}