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

struct output {
    int can;
    vector<pii> res;

    void print() {
        if (can) {
            cout << "YES\n";
            for (auto [x, y] : res) {
                cout << x + 1 << " " << y + 1 << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        return true;
    }
};

struct DSU {
    int n = 0; // [0, n)
    vector<int> p;

    DSU(int nn) {
        n = nn;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        p[y] = x;
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
        const int N = 10;
        n = rnd() % N + 2;
        s = string(n, '?');
        for (char& c : s)
            c = rnd() % 2 + '0';
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> a(n);
        int xr = 0, any = 0;
        for (int i = 0; i < n; i++)
            a[i] = s[i] - '0', xr ^= a[i], any |= a[i];
        if (xr || !any) return output{0, {}};

        vector<pii> res;
        set<int> Q;
        for (int v = 0; v < n; v++) {
            Q.insert(v);
        }
        int cnt[2] = {0, 0};
        for (int v : Q) cnt[a[v]]++;
        auto it = Q.begin();
        while (cnt[0] > 0 && (int) Q.size() > 2) {
            auto nit = next(it); if (nit == Q.end()) nit = Q.begin();
            {
                int u = *it;
                int v = *nit;
                if (a[u] && !a[v]) {
                    res.emplace_back(u, v);
                    Q.erase(u);
                    it = Q.lower_bound(u);
                    if (it == Q.end()) it = Q.begin();
                    cnt[0]--;
                    a[v] ^= 1;
                    continue;
                }
            }
            it = nit;
        }
        vector<int> rem(Q.begin(), Q.end());
        for (int i = 1; i < (int) rem.size(); i++)
            res.emplace_back(rem[0], rem[i]);
        return output{1, res};
    }

#ifdef DEBUG
    output slow() {
        return fast();
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
    int t;
    cin >> t;
    while (t--)
        test_case();
}

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        in.print();
        cout.flush();
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

    work();
//    test();
//    max_test();

    return 0;
}