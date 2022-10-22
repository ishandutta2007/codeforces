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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, K;
    vector<int> p, s;

    input() = default;

    void read() {
        cin >> n >> K;
        p.resize(n);
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        s.resize(n);
        for (auto& x : s) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++)
            g[p[i]].push_back(i);
        vector<map<int, ll>> dp(n);
        function<void(int, vector<int>)> dfs = [&](int v, vector<int> ks) {
            int sz = (int) g[v].size();
            if (sz == 0) { // leaf
                for (int k : ks) {
                    dp[v][k] = 1ll * s[v] * k;
                }
                return;
            }
            vector<int> nks;
            for (auto k : ks) {
                nks.push_back(k / sz);
                if (k % sz)
                    nks.push_back(k / sz + 1);
            }
            sort(nks.begin(), nks.end());
            nks.erase(unique(nks.begin(), nks.end()), nks.end());
            for (auto to : g[v]) {
                dfs(to, nks);
            }
            for (int k : ks) {
                int small = k / sz;
                if (k % sz == 0) {
                    ll sm = 1ll * k * s[v];
                    for (int to : g[v]) {
                        sm += dp[to][small];
                    }
                    dp[v][k] += sm;
                    continue;
                }
                int big = k / sz + 1;
                int c_big = k % sz;
                int c_small = sz - c_big;
                ll sm = 0;
                vector<ll> ar;
                ar.reserve(sz);
                for (int to : g[v]) {
                    sm += dp[to][small];
                    ar.push_back(dp[to][big] - dp[to][small]);
                }
                sort(ar.rbegin(), ar.rend());
                for (int j = 0; j < c_big; j++)
                    sm += ar[j];
                sm += 1ll * s[v] * k;
                dp[v][k] = sm;
            }
        };
        dfs(0, {K});
        ll res = dp[0][K];
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
//#ifdef DEBUG
    cin >> t;
//#endif
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