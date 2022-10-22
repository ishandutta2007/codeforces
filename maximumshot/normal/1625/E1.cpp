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
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

template <class T>
struct RangeTree {
    int n = 0; // [0, n)
    vector<T> t;

    RangeTree() = default;

    RangeTree(const vector<T>& a) {
        n = (int) a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void set(int i, T x) {
        for (i += n, t[i] = x, i >>= 1; i > 0; i >>= 1)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    T get(int l, int r) {
        T res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};

struct Tree {
    int n = 0;
    vector<int> p, deg;
    vector<ll> f;
    vector<vector<int>> g;
    vector<int> tin, tout, pos;
    vector<ll> euler;
    vector<vector<int>> alive;
    vector<RangeTree<int>> rt_alive;
    RangeTree<ll> rt_euler;
    int timer = 0;

    Tree() = default;

    Tree(vector<int> p_) {
        p = p_;
        n = (int) p.size();
        f.resize(n);
        deg.resize(n);
        g.resize(n);
        for (int v = n - 1; v > 0; v--) {
            deg[p[v]]++;
            g[p[v]].push_back(v);
        }
        for (int v = 0; v < n; v++) {
            f[v] = 1ll * deg[v] * (deg[v] - 1) / 2 + 1;
        }
        for (int v = 0; v < n; v++) {
            sort(g[v].begin(), g[v].end());
        }
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        dfs(0);
        pos.resize(n);
        alive.resize(n);
        rt_alive.resize(n);
        for (int v = 0; v < n; v++) {
            alive[v].assign(g[v].size(), 1);
            rt_alive[v] = RangeTree<int>(alive[v]);
            for (int it = 0; it < (int) g[v].size(); it++) {
                int to = g[v][it];
                pos[to] = it;
            }
        }
        rt_euler = RangeTree<ll>(euler);
    }

    void dfs(int v) {
        tin[v] = timer++;
        euler.push_back(f[v]);
        for (int to : g[v])
            dfs(to);
        tout[v] = timer;
    }

    void update(int u) {
//        f[u] = 0;
//        euler[tin[u]] = 0;
        rt_euler.set(tin[u], 0);

        if (u > 0) {
            int pu = p[u];
            deg[pu]--;
            f[pu] = 1ll * deg[pu] * (deg[pu] - 1) / 2 + 1;
//            euler[tin[pu]] = f[pu];
//            alive[pu][pos[u]] = 0;
            rt_euler.set(tin[pu], f[pu]);
            rt_alive[pu].set(pos[u], 0);
        }
    }

    ll get(int u, int v) {
        assert(u <= v);
        int l = tin[u];
        int r = tout[v];
        // [l, r)
        ll res = 0;
//        for (int i = l; i < r; i++)
//            res += euler[i];
        res += rt_euler.get(l, r);
        if (u < v) {
            int cnt = 0;
//            for (int i = pos[u]; i <= pos[v]; i++)
//                cnt += alive[p[u]][i];
            cnt += rt_alive[p[u]].get(pos[u], pos[v] + 1);
            res += 1ll * cnt * (cnt - 1) / 2;
        }
        return res;
    }
};

struct input {
    int n, m;
    string s;

    struct Query {
        int t, l, r;
    };

    vector<Query> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        cin >> s;
        qs.resize(m);
        for (auto& [t, l, r] : qs) {
            cin >> t >> l >> r;
            l--, r--;
        }
    }

    void print() {
        cout << n << " " << m << "\n";
        cout << s << "\n";
        for (auto [t, l, r] : qs) {
            cout << t << " " << l + 1 << " " << r + 1 << "\n";
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 50;
        n = rnd() % (MAXN - 2) + 2;
        m = rnd() % 2 * MAXN + 1;
        s.resize(n, '?');
        for (char& c : s)
            c = rnd() % 2 ? '(' : ')';
        qs.resize(m);
        string buf = s;
        for (int it = 0; it < m; it++) {
            auto& [t, l, r] = qs[it];
            t = rnd() % 2 + 1;
            if (t == 1) {
                vector<pii> candidates;
                for (int i = 0; i < n; i++) {
                    if (buf[i] != '(')
                        continue;
                    int j = i + 1;
                    while (j < n && buf[j] == '.')
                        j++;
                    if (j < n && buf[j] == ')')
                        candidates.emplace_back(i, j);
                }
                if (candidates.empty())
                    t = 2;
                else {
                    tie(l, r) = candidates[rnd() % (int) candidates.size()];
                    buf[l] = buf[r] = '.';
                }
            }
            if (t == 2) {
                vector<pii> candidates;
                for (int j = 0; j < n; j++) {
                    if (s[j] != '(')
                        continue;
                    int b = 0;
                    for (int q = j; q < n; q++) {
                        if (s[q] == '(') b++;
                        else if (s[q] == ')') b--;
                        if (b < 0)
                            break;
                        if (s[q] != '.' && b == 0) {
                            candidates.emplace_back(j, q);
                        }
                    }
                }
                if (candidates.empty()) {
                    m = it;
                    break;
                } else {
                    tie(l, r) = candidates[rnd() % (int) candidates.size()];
                }
            }
        }
        qs.resize(m);
    }

    void gen_max_test() {

    }

    output fast() {
        {
            int b = 0, mnb = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '(') b++;
                else b--;
                mnb = min(mnb, b);
            }
            mnb = -mnb;
            s = string(mnb, '(') + s;
            n = (int) s.size();
            for (auto& [t, l, r] : qs) {
                l += mnb;
                r += mnb;
            }
        }
        {
            int b = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '(') b++;
                else b--;
            }
            s += string(b, ')');
            n = (int) s.size();
        }
        {
            s = "(" + s + ")";
            n = (int) s.size();
            for (auto& [t, l, r] : qs)
                l++, r++;
        }
        vector<int> st, ver(n, -1), p;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ver[i] = (int) p.size();
                p.push_back(-1);
                st.push_back(i);
            } else {
                int j = st.back();
                st.pop_back();
                ver[i] = ver[j];
                p[ver[j]] = st.empty() ? -1 : ver[st.back()];
            }
        }
        Tree tree(p);
        vector<ll> res;
//        cout << s << "\n";
        for (auto [t, l, r] : qs) {
//            cout << t << " " << l + 1 << " " << r + 1 << "\n";
            if (t == 1) {
                assert(ver[l] == ver[r]);
                tree.update(ver[l]);
            } else {
                res.push_back(tree.get(ver[l], ver[r]));
            }
        }
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        vector<ll> res;
        for (auto [t, l, r] : qs) {
            if (t == 1) {
                s[l] = s[r] = '.';
            } else {
                ll tmp = 0;
                for (int j = l; j <= r; j++) {
                    if (s[j] != '(')
                        continue;
                    int b = 0;
                    for (int q = j; q <= r; q++) {
                        if (s[q] == '(') b++;
                        else if (s[q] == ')') b--;
                        if (b < 0)
                            break;
                        if (s[q] != '.' && b == 0)
                            tmp++;
                    }
                }
                res.push_back(tmp);
            }
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