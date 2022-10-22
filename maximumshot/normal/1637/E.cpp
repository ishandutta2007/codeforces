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
    int n, m;
    vector<int> a;
    vector<pii> es;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
        es.resize(m);
        for (auto& [x, y] : es)
            cin >> x >> y;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        sort(a.begin(), a.end());
        vector<int> cnt;
        {
            vector<int> aa;
            for (int i = 0; i < n; i++) {
                int j = i;
                while (j < n && a[i] == a[j]) j++; j--;
                cnt.push_back(j - i + 1);
                aa.push_back(a[i]);
                i = j;
            }
            a = aa;
            n = (int) a.size();
        }
        for (auto& [x, y] : es) {
            x = lower_bound(a.begin(), a.end(), x) - a.begin();
            y = lower_bound(a.begin(), a.end(), y) - a.begin();
        }
        int k = 1;
        while (k * k < n) k++;
        vector<vector<int>> g(n);
        for (auto [x, y] : es) {
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end());
            if (cnt[i] >= k) { // heavy
                for (int ptr = 0, j = 0; j < n; j++) {
                    if (i == j)
                        continue;
                    while (ptr < (int) g[i].size() && g[i][ptr] < j) ptr++;
                    if (ptr < (int) g[i].size() && g[i][ptr] == j)
                        continue;
                    res = max(res, 1ll * (cnt[i] + cnt[j]) * (a[i] + a[j]));
                }
            }
        }
        vector<vector<int>> seq(k);
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            if (cnt[i] >= k)
                continue;
            seq[cnt[i]].push_back(i);
        }
        vector<vector<int>> blocked(k);
        for (int i = 0; i < k; i++) {
            sort(seq[i].begin(), seq[i].end());
            for (int it = 0; it < (int) seq[i].size(); it++) {
                int j = seq[i][it];
                pos[j] = it;
            }
            blocked[i].assign(seq[i].size(), 0);
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] >= k)
                continue;
            for (int j : g[i]) {
                if (cnt[j] < k)
                    blocked[cnt[j]][pos[j]] = 1;
            }
            blocked[cnt[i]][pos[i]] = 1;
            for (int cnty = 0; cnty < k; cnty++) {
                int ptr = (int) seq[cnty].size() - 1;
                while (ptr >= 0 && blocked[cnty][ptr]) ptr--;
                if (ptr >= 0) {
                    int j = seq[cnty][ptr];
                    res = max(res, 1ll * (cnt[i] + cnt[j]) * (a[i] + a[j]));
                }
            }
            for (int j : g[i]) {
                if (cnt[j] < k)
                    blocked[cnt[j]][pos[j]] = 0;
            }
            blocked[cnt[i]][pos[i]] = 0;
        }
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
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