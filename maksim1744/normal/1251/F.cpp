/*
    author:  Maksim1744
    created: 24.10.2019 18:54:20
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
const int N = 302;
const int K = 10;
const int P2 = 1 << K;
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
const int N = 300010;
const int K = 20;
const int P2 = 1 << K;
#endif

const long long mod = 998244353, g = 3, ginv = 332748118, inv2 = (mod + 1) / 2;

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;

long long mpow(long long a, long long p) {
    if (a == 0)
        return 0;
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

// vector<ll> w_(P2);
// vector<ll> wi_(P2);
// vector<int> ind(P2);
array<ll, P2> w_;
array<ll, P2> wi_;
array<int, P2> ind;

ll mpi2k;

void precalc() {
    {
        ll w0 = mpow(ginv, (mod - 1) / (P2));

        wi_[0] = 1;
        wi_[1] = w0;
        for (int i = 2; i < P2; ++i) {
            if (i >= P2 / 2) {
                wi_[i] = (mod - wi_[i - P2 / 2]);
                if (wi_[i] == mod) wi_[i] = 0;
            } else {
                wi_[i] = wi_[i / 2] * wi_[i - i / 2] % mod;
            }
        }
    }
    {
        ll w0 = mpow(g, (mod - 1) / (P2));

        w_[0] = 1;
        w_[1] = w0;
        for (int i = 2; i < P2; ++i) {
            if (i >= P2 / 2) {
                w_[i] = (mod - w_[i - P2 / 2]);
                if (w_[i] == mod) w_[i] = 0;
            } else {
                w_[i] = w_[i / 2] * w_[i - i / 2] % mod;
            }
        }
    }
    {
        ind[0] = 0;
        ind[1] = 1 << (K - 1);
        int id = 2;
        for (int i = 1; i < K; ++i) {
            int z = (1 << i);
            for (int j = 0; j < z; ++j) {
                ind[id] = (ind[id - z]) + (1 << (K - 1 - i));
                ++id;
            }
        }
    }
    mpi2k = mpow(inv2, K);
}

array<ll, P2> ntttmp;

void ntt(array<ll, P2>& v, array<ll, P2>& res, bool inv = false) {
    // array<ll, P2>* w = &w_;
    // if (inv)
    //     w = &wi_;
    res = v;
    int n = P2;
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (res[i], res[j]);
    }
 
    for (int len=2; len<=n; len<<=1) {
        ll g0 = g;
        if (inv)
            g0 = ginv;
        ll wlen = mpow(g0, (mod - 1) / (len));
        for (int i=0; i<n; i+=len) {
            ll w (1);
            for (int j=0; j<len/2; ++j) {
                ll u = res[i+j],  v = res[i+j+len/2] * w % mod;
                res[i+j] = (u + v) % mod;
                res[i+j+len/2] = (u - v + mod) % mod;
                w = w * wlen % mod;
            }
        }
    }
    // for (int i = 0; i < P2; ++i) {
    //     res[i] = v[ind[i]];
    // }
    // for (int i = K - 1; i >= 0; --i) {
    //     int cnt = (1 << i);
    //     int sz = (1 << (K - i));
    //     int k1 = sz / 2 - 1;
    //     for (int j = 0; j < cnt; ++j) {
    //         int k2 = sz * j;
    //         // vector<long long> va(res.begin() + sz * j, res.begin() + sz * j + sz / 2);
    //         // vector<long long> vb(res.begin() + sz * j + sz / 2, res.begin() + sz * j + sz);
    //         for (int u = 0; u < sz; ++u) {
    //             // res[k2 + u] = (va[u & k1] + (*w)[u << i] * vb[u & k1]);
    //             res[k2 + u] = (v[ind[sz * j + (u & k1)]] + (*w)[u << i] * v[ind[(u & k1) + sz * j + sz / 2]]);
    //             if (res[k2 + u] >= mod) res[k2 + u] %= mod;
    //         }
    //     }
    // }

    if (inv) {
        for (int i = 0; i < P2 / 2; ++i) {
            res[i] = res[i] * mpi2k;
            if (res[i] >= mod) res[i] %= mod;
        }
    }
}

int main() {
    precalc();
    array<int, N> f;
    array<int, N> finv;
    f[0] = 1;
    for (int i = 1; i < f.size(); ++i) {
        f[i] = 1ll * f[i - 1] * i % mod;
    }
    finv.back() = mpow(f.back(), mod - 2);
    for (int i = (int)finv.size() - 2; i >= 0; --i) {
        finv[i] = 1ll * finv[i + 1] * (i + 1) % mod;
    }
    auto calc_c = [&](int n, int k) {
        if (k < 0 || k > n)
            return 0ll;
        return 1ll * f[n] * finv[k] % mod * finv[n - k] % mod;
    };
    // show(f[3]*finv[3]%mod);
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = readInt(), k = readInt();
    // cin >> n >> k;
    array<int, N> a;
    array<int, N> a0;
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        // cin >> a0[i];
        a0[i] = readInt();
    }
    sort(a0.begin(), a0.begin() + n);
    int ia = 0;
    for (int i = 0; i < n; ++i) {
        if (i < 2 || a0[i] != a0[i - 1] || a0[i] != a0[i - 2])
            a[ia++] = (a0[i]);
    }
    n = ia;
    // vector<ll> b(k);
    // cin >> b;
    // sort(b.begin(), b.end());
    array<int, 5> b;
    for (int i = 0; i < k; ++i) {
        b[i] = readInt();
    }
    sort(b.begin(), b.begin() + k);
    // show(b);
    // show(cnt);
    array<int, 5> uniq, prs;
    int ind = 0;
    for (int i = 0; i < k; ++i) {
        if (i != 0) {
            prs[i] = prs[i - 1];
            uniq[i] = uniq[i - 1];
        }
        while (ind < n && a[ind] < b[i]) {
            if (ind + 1 < n && a[ind] == a[ind + 1]) {
                prs[i] += 2;
                ind += 2;
            } else {
                uniq[i]++;
                ind++;
            }
        }
    }
    array<ll, P2> vv1;
    array<ll, P2> vv2;
    vv1.fill(0);
    vv2.fill(0);
    vv1[0] = 1; vv1[1] = 2;
    vv2[0] = 1; vv2[1] = 1;
    array<ll, P2> ntt1, ntt2;
    ntt(vv1, ntt1);
    ntt(vv2, ntt2);
    array<ll, P2 + P2> res;
    res.fill(0);
    array<ll, P2> tmp;
    for (int i = 0; i < k; ++i) {
        int p1 = uniq[i], p2 = prs[i];
        if (p1 == 0 && p2 == 0) {
            res[b[i]]++;
        } else {
            for (int i = 0; i < P2; ++i) {
                tmp[i] = 1;
                if (p1 != 0)
                    tmp[i] = mpow(ntt1[i], p1);
                if (p2 != 0)
                    tmp[i] = tmp[i] * mpow(ntt2[i], p2);
                if (tmp[i] >= mod) tmp[i] %= mod;
            }
            // shows;
            // show(vv1, vv2, p1, p2, tmp);
            ntt(tmp, ntttmp, true);
            for (int j = 0; j < P2; ++j) {
                res[j + b[i]] += ntttmp[j];
            }
        }
    }
    int Q;
    // cin >> Q;
    Q = readInt();
    for (int iii = 0; iii < Q; ++iii) {
        int q = readInt();
        // cin >> q;
        q /= 2;
        if (res[q - 1] >= mod)
            res[q - 1] %= mod;
        // cout << res[q - 1] << '\n';
        writeInt(res[q - 1]);
        writeChar('\n');
    }
    return 0;
}