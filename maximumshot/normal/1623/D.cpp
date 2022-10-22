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
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n, m;

    struct pt {
        int x = 0; // [1, n]
        int y = 0; // [1, m]

        pt apply_mask(int mask) const {
            int x2 = x, y2 = y;
            if ((1 << 0) & mask) x2 = -x2;
            if ((1 << 1) & mask) y2 = -y2;
            return {x2, y2};
        }

        pt operator + (const pt& o) const {
            return {x + o.x, y + o.y};
        }

        bool check_x(int n) const {
            return 1 <= x && x <= n;
        }

        bool check_y(int m) const {
            return 1 <= y && y <= m;
        }

        bool operator == (const pt& o) const {
            return x == o.x && y == o.y;
        }
    };

    pt a, b;
    int p, q;

    input() = default;

    void read() {
        cin >> n >> m >> a.x >> a.y >> b.x >> b.y >> p;
        p = div_(p, 100);
        q = sub_(1, p);
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        vector<vector<vector<int>>> used(n + 1, vector<vector<int>>(m + 1, vector<int>(4, 0)));
        used[a.x][a.y][0] = 1;
        vector<pair<pt, int>> seq;
        pt v = a;
        int mask = 0;
        seq.emplace_back(v, mask);
        while (1) {
            pt dir = pt{1, 1}.apply_mask(mask);
            pt to = v + dir;
            if (!to.check_x(n)) mask ^= 1 << 0;
            if (!to.check_y(m)) mask ^= 1 << 1;
            to = v + pt{1, 1}.apply_mask(mask);
            v = to;
            seq.emplace_back(v, mask);
            if (used[v.x][v.y][mask])
                break;
            used[v.x][v.y][mask] = 1;
        }
//        for (auto [v, mask] : seq) {
//            pt dir = pt{1, 1}.apply_mask(mask);
//            cout << "(" << v.x << ", " << v.y << ") dir = (" << dir.x << ", " << dir.y << ")\n";
//        }
        int sz = (int) seq.size();
        vector<int> E(sz);
        vector<pii> linear(sz);
        int A = 1, B = 0;
        int i;
        linear[sz - 1] = {1, 0};
        for (i = sz - 2; i >= 0; i--) {
            pt v = seq[i].first;
            if (v.x != b.x && v.y != b.y) {
                inc_(B, 1);
            } else {
                A = mul_(A, q);
                B = mul_(B, q);
                inc_(B, 1);
            }
            linear[i] = {A, B};
            if (seq[i] == seq[sz - 1])
                break;
        }
        assert(A != 1);
        int x = div_(B, sub_(1, A));
        i--;
        while (i >= 0) {
            pt v = seq[i].first;
            if (v.x != b.x && v.y != b.y) {
                inc_(B, 1);
            } else {
                A = mul_(A, q);
                B = mul_(B, q);
                inc_(B, 1);
            }
            linear[i] = {A, B};
            i--;
        }
        int res = 0;
        for (i = 0; i < sz; i++) {
            pt v = seq[i].first;
            tie(A, B) = linear[i];
//            cout << "(" << v.x << ", " << v.y << ") = " << A << " " << B << "\n";
            if (seq[i].first == a) {
                inc_(res, sum_(mul_(A, x), B));
                break;
            }
        }
        dec_(res, 1);
        return output{res};
    }

    output slow() {
        return output();
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