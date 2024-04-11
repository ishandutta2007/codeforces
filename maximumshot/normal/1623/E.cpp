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
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct Fen {
    vector<int> f;
    int n = 0; // [0, n)

    Fen() = default;

    Fen(vector<int> f_) {
        n = (int) f_.size();
        f.assign(n, 0);
        for (int i = 0; i < n; i++)
            update(i, i, f_[i]);
    }

    void update(int i, int x) {
        for (int cur = i; cur < n; cur |= (cur + 1))
            f[cur] += x;
    }

    void update(int l, int r, int x) {
        update(l, x);
        update(r + 1, -x);
    }

    int get(int i) {
        int res = 0;
        for (int cur = i; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += f[cur];
        return res;
    }
};

struct input {
    int n, k;
    string c;
    vector<pii> sons;
    vector<int> p;
    vector<int> euler, euler2;
    vector<int> depth;
    vector<int> tin;
    vector<int> tout;
    int timer = 0;
    vector<int> ds, pos, used, nxt;
    Fen fen;

    input() = default;

    void read() {
        cin >> n >> k >> c;
        c = "#" + c;
        sons.resize(n + 1);
        p.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> sons[i].first >> sons[i].second;
            p[sons[i].first] = p[sons[i].second] = i;
        }
        depth.assign(n + 1, 0);
        tin.resize(n + 1);
        tout.resize(n + 1);
    }

    void dfs(int v) {
        if (!v)
            return;
        tin[v] = timer++;
        euler2.push_back(v);
        depth[sons[v].first] = depth[sons[v].second] = depth[v] + 1;
        dfs(sons[v].first);
        euler.push_back(v);
        dfs(sons[v].second);
        tout[v] = timer;
    }

    void print() {
        cout << n << " " << k << "\n";
        cout << c.substr(1) << "\n";
        for (int i = 1; i <= n; i++) {
            cout << sons[i].first << " " << sons[i].second << "\n";
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 1;
        k = rnd() % n + 1;
        c.resize(n + 1, '?');
        for (char& x : c)
            x = rnd() % 3 + 'a';
        sons.assign(n + 1, make_pair(0, 0));
        p.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            vector<int> ar;
            for (int j = 1; j < i; j++) {
                if (!sons[j].first || !sons[j].second)
                    ar.push_back(j);
            }
            shuffle(ar.begin(), ar.end(), rnd);
            int j = ar[0];
            p[i] = j;
            if (sons[j].first) sons[j].second = i;
            else if (sons[j].second) sons[j].first = i;
            else if (rnd() % 2) sons[j].first = i;
            else sons[j].second = i;
        }
        depth.assign(n + 1, 0);
        tin.resize(n + 1);
        tout.resize(n + 1);
    }

    void update(int v) {
        int ql = tin[v], qr = tout[v];
        fen.update(ql, qr - 1, -1);
//        for (int i = ql; i < qr; i++)
//            ds[i]--;
    }

    void go(int v) {
        if (!v)
            return;
        int i = pos[v];
        int j = nxt[i];
        if (k >= fen.get(tin[v]) && j < n && c[euler[i]] < c[euler[j]]) {
            k -= fen.get(tin[v]);
            for (int x = v; x > 0 && !used[x]; x = p[x]) {
                used[x] = 1;
                update(x);
            }
        }
        go(sons[v].first);
        if (used[v])
            go(sons[v].second);
    }

    output fast() {
        dfs(1);
        ds.resize(n);
        pos.resize(n + 1);
        used.assign(n + 1, 0);
        nxt.assign(n + 1, n);
        for (int i = 0; i < n; i++) {
            ds[i] = depth[euler2[i]] + 1;
            pos[euler[i]] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n && c[euler[i]] != c[euler[i + 1]]) nxt[i] = i + 1;
            else nxt[i] = nxt[i + 1];
        }
        fen = Fen(ds);
        go(1);
        string res;
        for (int v : euler) {
            res.push_back(c[v]);
            if (used[v])
                res.push_back(c[v]);
        }
        return output{res};
    }

    output slow() {
        dfs(1);
        string res;
        for (int mask = 0; mask < (1 << n); mask++) {
            used.assign(n + 1, 0);
            int nused = 0;
            for (int i = 1; i <= n; i++) {
                if ((1 << (i - 1)) & mask)
                    used[i] = 1, nused++;
            }
            if (nused > k)
                continue;
            int ok = 1;
            for (int v = 2; v <= n; v++) {
                if (used[v] && !used[p[v]]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok)
                continue;
            string tmp;
            for (int i = 0; i < n; i++) {
                int v = euler[i];
                tmp.push_back(c[v]);
                if (used[v])
                    tmp.push_back(c[v]);
            }
            if (res.empty() || res > tmp)
                res = tmp;
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