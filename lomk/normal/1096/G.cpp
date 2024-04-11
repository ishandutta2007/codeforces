/*input
4 2
1 8
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

// tested on POLYMUL
int mod = 998244353; // 119*2^23+1
// can also be 107*2^23+1

using ll = long long;
inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
    return (int) ((long long) a * b % mod);
#endif
    unsigned long long x = (long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (mod)
    );
    return m;
}

#define pow binPow
int binPow(int a, ll q) {
    int ret = 1;
    while (q) {
        if (q & 1LL) ret = mul(ret, a);
        a = mul(a, a);
        q >>= 1LL;
    }
    return ret;
}



// only works for mod = c*2^k+1 and mod is prime
// to multiply with numbers upto 1e18, can use 2 mods then use Chinese Remainder Theorem
struct NTT {
private:
    int proot;
    int find_primitive_root() {
        int totient = mod - 1;
        vector<int> checks;
        int tmp = totient;
        for (int i = 2; i * i <= tmp; i++) {
            if (tmp % i) continue;
            checks.push_back(totient / i);
            while (tmp % i == 0) tmp /= i;
        }
        if (tmp > 1)
            checks.push_back(totient / tmp);
        for (int i = 2;; i++) {
            bool ok = none_of(checks.begin(), checks.end(), [&](int it) {
                if (binPow(i, it) == 1) return true;
                return false;
            });
            if (ok)
                return i;
        }
    }
public:
    NTT() {proot = find_primitive_root();}
    void ntt(vector<int> &a, bool invert) {
        int n = a.size();
        assert(__builtin_popcountll(n) == 1);
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;
            if (i < j)
                swap(a[i], a[j]);
        }

        int root = binPow(proot, (mod - 1) / n);
        if (invert)
            root = binPow(root, mod - 2);

        for (int len = 2; len <= n; len <<= 1) {
            int wlen = root;
            for (int i = len; i < n; i <<= 1)
                wlen = mul(wlen, wlen);
            for (int i = 0; i < n; i += len) {
                int w = 1;
                for (int j = 0; j < len / 2; ++j) {
                    int u = a[i + j], v = mul(a[i + j + len / 2], w);
                    a[i + j] = u + v < mod ? u + v : u + v - mod;
                    a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                    w = mul(w, wlen);
                }
            }
        }
        if (invert) {
            int nrev = binPow(n, mod - 2);
            for (auto &it : a)
                it = mul(it, nrev);
        }
    }

    int f2(int x) {
        if (__builtin_popcountll(x) != 1) return 1LL << ((63 - __builtin_clzll(x)) + 1);
        return x;
    }

    vector<int> multiply(vector<int> a, vector<int> b) {
        int rlen = a.size() + b.size() - 1;
        int len = f2(rlen);
        a.resize(len, 0); b.resize(len, 0);
        ntt(a, false); ntt(b, false);
        loop(i, 0, len - 1) a[i] = 1LL * a[i] * b[i] % mod;
        ntt(a, true);
        return vector<int>(a.begin(), a.begin() + rlen + 1);
    }

    vector<int> power(vector<int> a, int q) {
        int len = f2(q * a.size());
        a.resize(len, 0);
        ntt(a, false);
        for (auto &it : a) it = binPow(it, q);
        ntt(a, true);
        return a;
    }
} ntt;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(10, 0);
    loop(i, 1, m) {
        int t; cin >> t; a[t] = 1;
    }
    auto rec = ntt.power(a, n / 2);
    int ans = 0;
    for (auto it : rec) ans = (ans + mul(it, it)) % mod;
    cout << ans << endl;
}