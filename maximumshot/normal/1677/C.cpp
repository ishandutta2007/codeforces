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
        return res == o.res;
    }
};

struct input {
    int n;
    vector<int> a, b;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (auto& x : a) cin >> x, x--;
        for (auto& x : b) cin >> x, x--;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x + 1 << " ";
        cout << "\n";
        for (auto x : b)
            cout << x + 1 << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int N = 10;
        n = rnd() % N + 1;
        a.resize(n);
        b.resize(n);
        iota(a.begin(), a.end(), 0);
        iota(b.begin(), b.end(), 0);
//        shuffle(a.begin(), a.end(), rnd);
        shuffle(b.begin(), b.end(), rnd);
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            p[a[i]] = b[i];
        vector<int> used(n);
        vector<vector<int>> ar;
        vector<int> loops;
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            vector<int> cycle;
            for (int j = i; !used[j]; j = p[j]) {
                used[j] = 1;
                cycle.push_back(j);
            }
            if (cycle.size() > 1)
                ar.push_back(cycle);
            else
                loops.push_back(i);
        }
        sort(ar.begin(), ar.end(), [&](const auto& s1, const auto& s2) {
            return s1.size() > s2.size();
        });
        vector<int> ql(ar.size());
        vector<int> pref, suff;
        while ((int) pref.size() + (int) suff.size() < n - (int) loops.size()) {
            int j = 0;
            while (j < (int) ar.size() && ql[j] < (int) ar[j].size()) j++;
            for (int i = 0; i < j; i++) {
                pref.push_back(ar[i][ql[i]++]);
                if (ql[i] < (int) ar[i].size())
                    suff.push_back(ar[i][ql[i]++]);
                if (ql[i] + 1 == (int) ar[i].size()) {
                    loops.push_back(ar[i].back());
                    ar[i].clear();
                }
            }
        }
        vector<int> perm = pref;
        reverse(suff.begin(), suff.end());
        for (auto x : loops)
            perm.push_back(x);
        for (auto x : suff)
            perm.push_back(x);
        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            num[perm[i]] = i;
//            cout << perm[i] + 1 << " ";
//            num[i] = i;
        }
//        cout << "\n";
        ll res = 0;
        for (int i = 0; i < n; i++)
            res += abs(num[a[i]] - num[b[i]]);
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            p[a[i]] = b[i];
        vector<int> best;
        ll res = -1;
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        int cnt = 0;
        do {
            ll tmp = 0;
            for (int i = 0; i < n; i++)
                tmp += abs(perm[i] - perm[p[i]]);
            if (tmp >= res) {
                res = tmp;
                best = perm;
            } else if (tmp == res) {
                cnt++;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        vector<int> used(n);
        cout << "cnt = " << cnt << "\n";
        cout << "\n====\n";
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            for (int j = i; !used[j]; j = p[j]) {
                used[j] = 1;
                cout << best[j] << " ";
            }
            cout << "\n";
        }
        cout << "\n====\n";
        return output{res};
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