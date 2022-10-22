#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

template<int mod, int root, int LOG>
struct FFT {
    vector<int> G[LOG + 1];
    vector<int> rev[LOG + 1];
    FFT() {
        for (int start = root, lvl = LOG; lvl >= 0; lvl--, start = mul(start, start)) {
            int tot = 1 << lvl;
            G[lvl].resize(tot);
            for (int cur = 1, i = 0; i < tot; i++, cur = mul(cur, start)) {
                G[lvl][i] = cur;
            }
        }
        for (int lvl = 1; lvl <= LOG; lvl++) {
            int tot = 1 << lvl;
            rev[lvl].resize(tot);
            for (int i = 1; i < tot; i++) {
                rev[lvl][i] = ((i & 1) << (lvl - 1)) | (rev[lvl][i >> 1] >> 1);
            }
        }
    }
    void fft(vector<int>& a, int sz, bool invert) {
        int n = 1 << sz;
        for (int j, i = 0; i < n; i++) {
            if ((j = rev[sz][i]) < i)
                swap(a[i], a[j]);
        }
        for (int f1, f2, lvl = 0, len = 1; len < n; len <<= 1, lvl++) {
            for (int i = 0; i < n; i+= (len << 1)) {
                for (int j = 0; j < len; j++) {
                    f1 = a[i + j];
                    f2 = mul(a[i + j + len], G[lvl + 1][j]);
                    a[i + j] = sum(f1, f2);
                    a[i + j + len] = sub(f1, f2);
                }
            }
        }
        if (invert) {
            reverse(a.begin() + 1, a.end());
            int rn = binpow(n, mod - 2);
            for (int i = 0; i < n; i++) {
                a[i] = mul(a[i], rn);
            }
        }
    }
    vector<int> multiply(const vector<int>& a, const vector<int>& b) {
        vector<int> fa(a.begin(), a.end());
        vector<int> fb(b.begin(), b.end());
        int n = (int) a.size();
        int m = (int) b.size();
        int maxnm = max(n, m), sz = 0;
        while ((1 << sz) < maxnm)
            sz++;
        sz++;
        fa.resize(1 << sz);
        fb.resize(1 << sz);
        fft(fa, sz, false);
        fft(fb, sz, false);
        int SZ = 1 << sz;
        for (int i = 0; i < SZ; i++) {
            fa[i] = mul(fa[i], fb[i]);
        }
        fft(fa, sz, true);
        return fa;
    }
    int sum(int x, int y) {
        return x + y < mod ? x + y : x + y - mod;
    }
    int sub(int x, int y) {
        return x >= y ? x - y : x - y + mod;
    }
    int mul(int x, int y) {
        return (1ll * x * y) % mod;
    }
    int mul(const vector<int>& a) {
        int res = 1;
        for (const auto& x : a)
            res = mul(res, x);
        return res;
    }
    void inc(int& x, int y) {
        if ((x += y) >= mod)
            x -= mod;
    }
    void dec(int& x, int y) {
        if ((x -= y) < 0)
            x += mod;
    }
    int binpow(int x, int pw) {
        int res = 1, tmp = x;
        while (pw > 0) {
            if (pw & 1) res = mul(res, tmp);
            tmp = mul(tmp, tmp);
            pw >>= 1;
        }
        return res;
    }
};

//    const int mod = 998244353;
//    const int root = 31;
//    const int LOG = 23;

const int mod = 998244353;

FFT<mod, 31 * 31 * 31 * 31, 21> fft;

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, k, f;

    input() = default;

    void read() {
        cin >> n >> k >> f;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> cur(k + 1);
        for (int i = 0; i <= k; i++)
            cur[i] = 1;
        for (int it = 0; it < n - 1; it++) {
            vector<int> tmp = fft.multiply(cur, cur);
//            tmp.resize(2 * k + 1);
            vector<int> nxt(k + 1);
            vector<int> sf = tmp;
            for (int i = (int) sf.size() - 2; i >= 0; i--)
                fft.inc(sf[i], sf[i + 1]);
            for (int x = 0; x <= k; x++) {
                if (x + 1 < (int) sf.size())
                    fft.inc(nxt[x], sf[x + 1]);
//                for (int ij = x + 1; ij < (int) tmp.size(); ij++)
//                    fft.inc(nxt[x], tmp[ij]);
//                for (int ij = 0; ij <= x && ij < (int) tmp.size(); ij++)
//                    fft.inc(nxt[ij], tmp[ij]);
            }
            for (int ij = 0; ij < (int) tmp.size() && ij <= k; ij++) {
                fft.inc(nxt[ij], fft.mul(max(0, k - ij + 1), tmp[ij]));
//                for (int x = ij; x <= k; x++)
//                    fft.inc(nxt[ij], tmp[ij]);
            }
            swap(nxt, cur);
        }
        int res = 0;
        for (int i = 0; i <= k && i <= f; i++) {
            if (f - i <= k)
                fft.inc(res, fft.mul(cur[i], cur[f - i]));
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return output();
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}
#endif

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}