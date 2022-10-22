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

const int mod = inf + 7;

inline int sum_(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int mul_(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sub_(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void inc_(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void dec_(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int binpow_(int x, int pw) {
    if (x == 0)
        return 0;
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = mul_(res, tmp);
        }
        tmp = mul_(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int div_(int a, int b) {
    return mul_(a, binpow_(b, mod - 2));
}


struct output {
    int res = 0;

    output() = default;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct Fen {
    int n = 0; // [0, n)
    vector<int> f;

    Fen() = default;

    Fen(int nn) {
        n = nn;
        f.assign(n, 0);
    }

    void upd(int i, int x) {
        for (int cur = i; cur < n; cur |= (cur + 1))
            inc_(f[cur], x);
    }

    void upd(int l, int r, int x) {
        upd(l, x);
        upd(r + 1, x ? mod - x : 0);
    }

    int get(int i) {
        int res = 0;
        for (int cur = i; cur >= 0; cur = (cur & (cur + 1)) - 1)
            inc_(res, f[cur]);
        return res;
    }
};

struct input {
    int n = 0;
    vector<int> a, b;
    int t = 0;
    vector<int> s;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n + 1);
        b.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i];
        cin >> t;
        s.resize(t);
        for (int i = 0; i < t; i++)
            cin >> s[i];
    }

    void print() {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << a[i] << " " << b[i] << "\n";
        cout << t << "\n";
        for (int i : s)
            cout << i << " ";
        cout << "\n";
    }

    void gen() {
        // use static
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 1;
        a.resize(n + 1);
        b.resize(n + 1);
        vector<int> poses(2 * n);
        iota(poses.begin(), poses.end(), 1);
        shuffle(poses.begin(), poses.end(), rnd);
        for (int i = 1; i <= n; i++) {
            a[i] = poses[2 * (i - 1)];
            b[i] = poses[2 * (i - 1) + 1];
            if (a[i] > b[i])
                swap(a[i], b[i]);
        }
        t = rnd() % n + 1;
        s.resize(n);
        iota(s.begin(), s.end(), 1);
        shuffle(s.begin(), s.end(), rnd);
        s.resize(t);
    }

    output fast() {
        vector<int> seq;
        vector<int> link(2 * n + 1), id(2 * n + 1);
        for (int i = 1; i <= n; i++)
            link[a[i]] = b[i], link[b[i]] = a[i], id[a[i]] = id[b[i]] = i;
        int total = 0;
        int R = 0;
        int best = -1;
        for (int i = 0; i < t; i++) {
            R = max(R, b[s[i]]);
            if (best == -1 || b[best] < b[s[i]])
                best = s[i];
        }
        Fen fen(2 * n + 1);
        vector<int> POS(2 * n + 1);

        vector<int> need(n + 1);
        for (int i : s)
            need[i] = 1;

        sort(s.begin(), s.end(), [&](int i, int j) {
            return b[i] < b[j];
        });

        vector<int> prv(n + 1);
        for (int i = 1; i < t; i++)
            prv[s[i]] = s[i - 1];

        int res = 0;

//        vector<vector<int>> mem_seq(2 * n + 1);
//        vector<Fen> mem_fen(2 * n + 1);

        int last = b[s.back()];

        int from = -1;
        vector<vector<pii>> asks(2 * n + 1);
        while (1) {
//            inc_(res, mem_fen[last].get(POS[last]));
            asks[last].emplace_back(last, +1);
            inc_(res, 1);
            if (from != -1) {
//                dec_(res, mem_fen[last].get(POS[from]));
                asks[last].emplace_back(from, mod - 1);
            }

            int nxt = prv[id[last]];
            while (nxt && a[nxt] < a[id[last]])
                nxt = prv[nxt];

            if (!nxt)
                break;

            from = a[id[last]];
            last = b[nxt];
        }

        for (int i = 1; i <= 2 * n; i++) {
            int j = link[i];
            seq.push_back(i);
            POS[i] = (int) seq.size() - 1;
            fen.upd((int) seq.size() - 1, (int) seq.size() - 1, total);
            for (auto [key, coef] : asks[i]) {
                inc_(res, mul_(coef, fen.get(POS[key])));
            }
//            mem_seq[i] = seq;
//            mem_fen[i] = fen;
            if (i < j) {
                continue;
            }
            int pos = POS[j];
            int delta = sub_(total, fen.get(pos));
            inc_(delta, 1);
            inc_(total, delta);
            fen.upd(pos, (int) seq.size() - 1, delta);
        }

        return output{res};
    }

    output slow() {
        vector<int> used(n + 1);
        auto check = [&]() -> bool {
            for (int i : s) {
                if (!used[i])
                    return false;
            }
            return true;
        };
        vector<int> link(2 * n + 1), id(2 * n + 1);
        for (int i = 1; i <= n; i++)
            link[a[i]] = b[i], link[b[i]] = a[i], id[a[i]] = id[b[i]] = i;
        int total = 0;
        for (int i = 1; !check();) {
//            cout << i << "\n";
            int j = link[i];
            if (i < j || used[id[i]]) {
                i++;
                continue;
            }
            used[id[i]] = 1;
            i = j;
            inc_(total, 1);
//            cout << "\t1\n";
            for (int q = 1; q <= n; q++) {
                if (a[q] > i)
                    used[q] = 0;
            }
        }
        return output{total};
    }
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