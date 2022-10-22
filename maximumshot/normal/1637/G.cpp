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
    vector<pii> res;

    void print() {
        if (res.empty()) {
            cout << "-1\n";
        } else {
            cout << (int) res.size() << "\n";
            for (auto [x, y] : res)
                cout << x << " " << y << "\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        if (n == 2)
            return output{{}};
        int LOG = 0;
        while ((1 << LOG) <= n) LOG++; LOG += 2;
        vector<int> cnt(LOG);
        vector<pii> res;
        function<void(int, int)> rec = [&](int log_coef, int k) {
            if (k < 1)
                return;
            if (k == 1) {
                cnt[log_coef]++;
                return;
            }
            if (k == 2) {
                cnt[log_coef]++;
                cnt[log_coef + 1]++;
                return;
            }
            int log_ub = 0;
            while ((1 << log_ub) < k) log_ub++;
            if ((1 << log_ub) == k) {
                cnt[log_coef + log_ub]++;
                rec(log_coef, k - 1);
                return;
            }
            log_ub--;
            int pos = 1 << log_ub;
            int l = pos - 1, r = pos + 1, cc = 0;
            cnt[log_coef + log_ub]++;
            while (l >= 1 && r <= k) {
                res.emplace_back(l << log_coef, r << log_coef);
                l--, r++;
                cc++;
                cnt[log_coef + log_ub + 1]++;
            }
            rec(log_coef + 1, cc);
            rec(log_coef, l);
        };
        rec(0, n);
        int log_ub = 0;
        while ((1 << log_ub) < n) log_ub++;
        for (int j = 0; j < log_ub; j++) {
            if (cnt[j] >= 2) {
                res.emplace_back(1 << j, 1 << j);
                cnt[j] -= 2;
                cnt[j + 1]++;
                break;
            }
        }
        for (int j = 0; j < log_ub; j++) {
            while (cnt[j] > 0) {
                cnt[j]--;
                int nj = j;
                while (nj < log_ub && cnt[nj] == 0) nj++;
                if (nj == log_ub) {
                    cnt[j]++;
                    break;
                }
                cnt[nj]--;

                int x = 1 << j;
                int y = 1 << nj;
                res.emplace_back(x, y);
                res.emplace_back(x + y, y - x);
                cnt[j + 1]++;
                cnt[nj + 1]++;
            }
        }
        for (int j = 0; j <= log_ub; j++) {
            if (cnt[j]) {
                int x = 1 << j;
                res.emplace_back(0, x);
                while (x < (1 << log_ub)) {
                    res.emplace_back(x, x);
                    res.emplace_back(0, 2 * x);
                    x *= 2;
                }
                break;
            }
        }
        return output{res};
        assert((int) res.size() <= 20 * n);
        multiset<int> q;
        for (int i = 1; i <= n; i++)
            q.insert(i);
        for (auto [x, y] : res) {
            assert(q.count(x));
            q.erase(q.find(x));
            assert(q.count(y));
            q.erase(q.find(y));
            int x1 = x + y;
            int x2 = abs(x - y);
            q.insert(x1);
            q.insert(x2);
        }
        assert(*q.begin() == *(--q.end()));
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        auto check = [&](int ub) -> bool {
            set<vector<int>> used;
            vector<int> p(n);
            iota(p.begin(), p.end(), 1);
            used.insert(p);
            queue<vector<int>> q;
            q.push(p);
            while (!q.empty()) {
                auto v = q.front();
                q.pop();
                if (*min_element(v.begin(), v.end()) == *max_element(v.begin(), v.end())) {
                    return true;
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == j)
                            continue;
                        int x = v[i] + v[j];
                        int y = abs(v[i] - v[j]);
                        if (x > ub || y > ub)
                            continue;
                        auto to = v;
                        to[i] = x;
                        to[j] = y;
                        if (!used.count(to)) {
                            used.insert(to);
                            q.push(to);
                        }
                    }
                }
            }
            return false;
        };
        int res = n;
        while (res < 20 * n && !check(res)) res++;
        if (!check(res)) res = -1;
        return output{{{res, res}}};
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