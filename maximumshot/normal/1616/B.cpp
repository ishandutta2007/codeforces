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

pair<vector<int>, vector<int>>
manacker(const string& s) {
    // -> {d0, d1}. RUN test!
    int n = (int)s.size();
    vector<int> d0(n), d1(n);
    for (int l = 0, r = -1, i = 0; i < n; i++) {
        d1[i] =
                i <= r ? min(r - i, d1[l + r - i]) : 0;
        while (i >= d1[i] && i + d1[i] < n &&
               s[i - d1[i]] == s[i + d1[i]])
            d1[i]++;
        d1[i]--;
        if (i + d1[i] > r)
            l = i - d1[i], r = i + d1[i];
    }
    for (int l = 0, r = -1, i = 0; i < n; i++) {
        d0[i] =
                i < r ? min(r - i, d0[l + r - i - 1]) : 0;
        while (i >= d0[i] && i + d0[i] + 1 < n &&
               s[i - d0[i]] == s[i + d0[i] + 1])
            d0[i]++;
        if (d0[i] > 0 && i + d0[i] > r)
            l = i - d0[i] + 1, r = i + d0[i];
    }
    return {d0, d1};
}

struct output {
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n;
    string s;

    input() = default;

    void read() {
        cin >> n >> s;
    }

    void print() {
        cout << n << "\n" << s << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 1;
        s.resize(n, '?');
        for (char& c : s)
            c = rnd() % 3 + 'a';
    }

    output fast() {
        const int P = 37;
        const int mod = inf + 7;
        vector<int> pw(n + 1), h(n), hr(n);
        pw[0] = 1;
        for (int i = 1; i <= n; i++)
            pw[i] = (1ll * pw[i - 1] * P) % mod;
        for (int i = 0; i < n; i++) {
            if (i > 0) h[i] = h[i - 1], hr[i] = hr[i - 1];
            h[i] = (1ll * h[i] * P + s[i] - 'a' + 1) % mod;
            hr[i] = (1ll * hr[i] * P + s[n - 1 - i] - 'a' + 1) % mod;
        }
        auto get_hash = [&](int l, int r) -> int {
            int res = (h[r] - 1ll * (l > 0 ? h[l - 1] : 0) * pw[r - l + 1]) % mod;
            if (res < 0) res += mod;
            return res;
        };
        auto get_hash_r = [&](int l, int r) -> int {
            int res = (hr[r] - 1ll * (l > 0 ? hr[l - 1] : 0) * pw[r - l + 1]) % mod;
            if (res < 0) res += mod;
            return res;
        };
        auto get_hash_i = [&](int i, int r) -> int {
            if (r <= i)
                return get_hash(0, r);
            int le = get_hash(0, i);
            int ri_len = r - i;
            int ri = get_hash_r(n - 1 - i, n - 1 - (i - ri_len + 1));
            return (1ll * le * pw[ri_len] + ri) % mod;
        };
        auto get_lcp = [&](int i, int j) -> int {
            int bl = 0, br = (min(i, j) + 1) * 2 + 1, bm;
            while (br - bl > 1) {
                bm = (bl + br) >> 1;
                if (get_hash_i(i, bm - 1) == get_hash_i(j, bm - 1)) bl = bm;
                else br = bm;
            }
            return bl;
        };
        auto get_symb = [&](int i, int pos) -> int {
            if (pos >= 2 * (i + 1))
                return 0;
            if (pos <= i)
                return s[pos];
            int delta = pos - i - 1;
            return s[i - delta];
        };
        int best = 0;
        get_lcp(2, 3);
        for (int i = 1; i < n; i++) {
            int lcp = get_lcp(best, i);
            char x = get_symb(best, lcp);
            char y = get_symb(i, lcp);
            if (x > y)
                best = i;
        }
        string x = s.substr(0, best + 1);
        string y = x;
        reverse(y.begin(), y.end());
        return output{x + y};
    }

    output slow() {
        string res;
        for (int i = 0; i < n; i++) {
            string x = s.substr(0, i + 1);
            string y = x;
            reverse(y.begin(), y.end());
            if (res.empty() || res > x + y)
                res = x + y;
        }
        return output{res};
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}