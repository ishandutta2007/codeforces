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

const int mod1 = inf + 7;
const int mod2 = inf + 21;
const int P1 = 43;
const int P2 = 37;
const int MAXN = 1 << 19;

int pw1[MAXN];
int pw2[MAXN];

void precalc() {
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pw1[i] = (1ll * pw1[i - 1] * P1) % mod1;
        pw2[i] = (1ll * pw2[i - 1] * P2) % mod2;
    }
}

struct Hash {
    int l = 0;
    int h1 = 0;
    int h2 = 0;

    Hash concat(const Hash& o) const {
        return Hash{
            l + o.l,
            int( (1ll * h1 * pw1[o.l] + o.h1) % mod1 ),
            int( (1ll * h2 * pw2[o.l] + o.h2) % mod2 )
        };
    }

    bool operator == (const Hash& o) const {
        return l == o.l && h1 == o.h1 && h2 == o.h2;
    }
};

struct output {
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<vector<Hash>> t;

    RangeTree() = default;

    RangeTree(const string& s) {
        n = (int) s.size();
        t.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void build(int v, int tl, int tr, const string& s) {
        if (tl == tr) {
            t[v].push_back(Hash{1, s[tl] - 'a' + 1, s[tl] - 'a' + 1});
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, s);
            build(v << 1 | 1, tm + 1, tr, s);
            t[v].resize(t[v << 1].size() << 1);
            int len = tr - tl + 1;
            for (int mask = 0; mask < len; mask++) {
                if (mask < len / 2) t[v][mask] = t[v << 1][mask].concat(t[v << 1 | 1][mask]);
                else t[v][mask] = t[v << 1 | 1][mask - len / 2].concat(t[v << 1][mask - len / 2]);
            }
        }
    }

    pii get_sons(int v, int mask, int bit) {
        int vl = v << 1;
        int vr = v << 1 | 1;
        if ((1 << bit) & mask)
            swap(vl, vr);
        return {vl, vr};
    }

    Hash get_hash(int v, int mask, int bit) {
        return t[v][mask & ((1 << (bit + 1)) - 1)];
    }
};

struct input {
    int n;
    string s;
    RangeTree rt;

    input() = default;

    void read() {
        cin >> n >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    int lcp(int i, int j) {
//        int x = 0;
//        while (x < (1 << n) && s[i ^ x] == s[j ^ x])
//            x++;
//        return x;
        int v1 = 1;
        int v2 = 1;
        int bit = n - 1;
        int len = 1 << n;
        int res = 0;
        while (1) {
            if (rt.get_hash(v1, i, bit) == rt.get_hash(v2, j, bit)) {
                res += len;
//                assert(res == x);
                return res;
            }
            if (bit == -1) {
//                assert(res == x);
                return res;
            }
            auto [vl1, vr1] = rt.get_sons(v1, i, bit);
            auto [vl2, vr2] = rt.get_sons(v2, j, bit);
            if (rt.get_hash(vl1, i, bit - 1) == rt.get_hash(vl2, j, bit - 1)) {
                res += len / 2;
                v1 = vr1;
                v2 = vr2;
            } else {
                v1 = vl1;
                v2 = vl2;
            }
            len /= 2;
            bit--;
        }
    }

    bool cmp(int i, int j) {
        int x = lcp(i, j);
        if (x == (1 << n))
            return false;
        return s[x ^ i] < s[x ^ j];
    }

    void get_string(int l, int r, int mask, int bit, string& res) {
        if (r == l + 1) {
            res.push_back(s[l]);
            return;
        }
        int m = (l + r) / 2;
        if ((1 << bit) & mask) {
            get_string(m, r, mask, bit - 1, res);
            get_string(l, m, mask, bit - 1, res);
        } else {
            get_string(l, m, mask, bit - 1, res);
            get_string(m, r, mask, bit - 1, res);
        }
    }

    output fast() {
        rt = RangeTree(s);
        int best = 0;
        for (int j = 0; j < (1 << n); j++) {
            if (cmp(j, best))
                best = j;
        }
        string res;
        get_string(0, 1 << n, best, n - 1, res);
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

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}