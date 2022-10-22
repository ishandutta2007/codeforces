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

const ld eps = 1e-9;

struct output {
    vector<ld> res;

    void print() {
        cout.precision(20);
        cout << fixed;
        for (auto x : res) {
            if (x >= eps) {
                cout << x << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

ld sqr(ld x) {
    return x * x;
}

struct pt {
    ld x = 0;
    ld y = 0;
    ld z = 0;

    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y, z - o.z};
    }

    pt operator * (ld coef) const {
        return {x * coef, y * coef, z * coef};
    }

    pt operator / (ld coef) const {
        return {x / coef, y / coef, z / coef};
    }

    static ld det(ld a, ld b, ld c, ld d) {
        return a * d - b * c;
    }

    pt vector_mul(const pt& o) const {
        return {
            det(y, z, o.y, o.z),
            -det(x, z, o.x, o.z),
            det(x, y, o.x, o.y)
        };
    }

    ld scalar_mul(const pt& o) const {
        return x * o.x + y * o.y + z * o.z;
    }

    ld sqr_norm() const {
        return scalar_mul(*this);
    }

    ld norm() const {
        return sqrtl(max(ld(0), sqr_norm()));
    }

    ld area(const pt& o) const {
        return vector_mul(o).norm() / 2;
    }

    pt normalize_z() const {
        return (*this) / abs(z);
    }
};

struct Polynom {
    vector<ld> f = {0};

    Polynom operator * (const Polynom& o) const {
        vector<ld> res(f.size() + o.f.size());
        for (int i = 0; i < (int) f.size(); i++) {
            for (int j = 0; j < (int) o.f.size(); j++) {
                res[i + j] += f[i] * o.f[j];
            }
        }
        while ((int) res.size() > 1 && abs(res.back()) < eps)
            res.pop_back();
        return Polynom{res};
    }

    Polynom operator * (ld coef) const {
        vector<ld> res = f;
        for (auto& x : res) x *= coef;
        return Polynom{res};
    }

    Polynom operator - (const Polynom& o) const {
        vector<ld> res(max(f.size(), o.f.size()));
        for (int i = 0; i < (int) f.size(); i++)
            res[i] += f[i];
        for (int i = 0; i < (int) o.f.size(); i++)
            res[i] -= o.f[i];
        return Polynom{res};
    }

    Polynom sqr() const {
        return (*this) * (*this);
    }

    ld operator()(ld x) const {
        ld res = 0;
        for (int i = (int) f.size() - 1; i >= 0; i--)
            res = res * x + f[i];
        return res;
    }

    Polynom& operator += (const Polynom& o) {
        if (f.size() < o.f.size())
            f.resize(o.f.size());
        for (int i = 0; i < (int) o.f.size(); i++)
            f[i] += o.f[i];
        return *this;
    }

    bool operator < (const Polynom& o) const {
        return f.size() < o.f.size();
    }
};

template<class T>
struct DSU {
    int n = 0; // [0, n)
    vector<int> p;
    vector<T> f;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        f.resize(n);
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
        f[x] += f[y];
    }

    void add(int v, T x) {
        v = find(v);
        f[v] += x;
    }

    T get(int v) {
        v = find(v);
        return f[v];
    }
};

struct input {
    int n;
    vector<pt> ps;
    int m;
    vector<vector<int>> f;
    int q;
    vector<pair<ld, int>> qs;

    input() = default;

    void read() {
        cin >> n;
        ps.resize(n);
        for (auto& p : ps)
            cin >> p.x >> p.y >> p.z;
        cin >> m;
        f.resize(m, vector<int>(3));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> f[i][j];
                f[i][j]--;
            }
        }
        cin >> q;
        qs.resize(q);
        for (auto& [h, p] : qs) {
            cin >> h >> p;
            p--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> qs_perm(q);
        iota(qs_perm.begin(), qs_perm.end(), 0);
        sort(qs_perm.begin(), qs_perm.end(), [&](int i, int j) {
            return qs[i].first > qs[j].first;
        });

        vector<tuple<ld, int, int>> add_es;
        vector<tuple<ld, Polynom, int>> add_poly;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                int k = (j + 1) % 3;
                int u = f[i][j];
                int v = f[i][k];
                add_es.emplace_back(min(ps[u].z, ps[v].z), u, v);
            }

            sort(f[i].begin(), f[i].end(), [&](int u, int v) {
                return ps[u].z < ps[v].z;
            });
            int a = f[i][0];
            int b = f[i][1];
            int c = f[i][2];
            if (ps[a].z + eps <= ps[c].z) {
                if (ps[b].z + eps <= ps[c].z) {
                    pt u = (ps[b] - ps[c]).normalize_z();
                    pt v = (ps[a] - ps[c]).normalize_z();
                    Polynom F = Polynom{{u.area(v)}} * Polynom{{ps[c].z, -1}}.sqr();
                    add_poly.emplace_back(ps[c].z, F, c);
                    add_poly.emplace_back(ps[b].z, F * -1, c);
                    add_poly.emplace_back(ps[b].z, Polynom{{F(ps[b].z)}}, c);
                }
                if (ps[a].z + eps <= ps[b].z) {
                    pt u = (ps[b] - ps[a]).normalize_z();
                    pt v = (ps[c] - ps[a]).normalize_z();
                    Polynom F = Polynom{{u.area(v)}} * Polynom{{-ps[a].z, 1}}.sqr();
                    F = Polynom{{F(ps[b].z)}} - F;
                    add_poly.emplace_back(ps[b].z, F, c);
                    add_poly.emplace_back(ps[a].z, F * -1, c);
                    add_poly.emplace_back(ps[a].z, Polynom{{F(ps[a].z)}}, c);
                }
            } else {
                pt u = ps[c] - ps[a];
                pt v = ps[b] - ps[a];
                add_poly.emplace_back(ps[c].z, Polynom{{u.area(v)}}, c);
            }
        }

        sort(add_es.rbegin(), add_es.rend());
        sort(add_poly.rbegin(), add_poly.rend());

        DSU<Polynom> dsu(n);
        vector<ld> res(q);
        for (int es_ptr = 0, poly_ptr = 0, iter = 0; iter < q; iter++) {
            int qid = qs_perm[iter];
            auto [h, p] = qs[qid];
            while (es_ptr < (int) add_es.size() && get<0>(add_es[es_ptr]) >= h + eps) {
                auto [t, u, v] = add_es[es_ptr++];
                dsu.merge(u, v);
            }
            while (poly_ptr < (int) add_poly.size() && get<0>(add_poly[poly_ptr]) >= h + eps) {
                auto [t, F, v] = add_poly[poly_ptr++];
                dsu.add(v, F);
            }
            auto F = dsu.get(p);
            ld area = F(h);
            res[qid] = area;
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