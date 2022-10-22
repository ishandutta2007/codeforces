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
        throw;
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
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> crd = a;
        for (auto x : b) crd.push_back(x);
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        for (auto& x : a) x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        for (auto& x : b) x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);

        vector<int> lu(n, -1), dr(n, -1);
        {
            sort(perm.begin(), perm.end(), [&](int i, int j) { return a[i] < a[j]; });
            int mx = -1, mx_id = -1;
            for (int i : perm) {
                if (mx < b[i]) mx = b[i], mx_id = i;
                lu[i] = mx_id;
            }
        }
        {
            sort(perm.begin(), perm.end(), [&](int i, int j) { return b[i] < b[j]; });
            int mx = -1, mx_id = -1;
            for (int i : perm) {
                if (mx < a[i]) mx = a[i], mx_id = i;
                dr[i] = mx_id;
            }
        }
        int sz = (int) crd.size();
        vector<int> f(sz, -1);
        for (int i = 0; i < n; i++) {
            f[a[i]] = max(f[a[i]], b[i]);
        }
        for (int i = sz - 2; i >= 0; i--)
            f[i] = max(f[i], f[i + 1]);

        vector<int> link(2 * n, -1);
        iota(link.begin(), link.end(), 0);
        for (int i = 0; i < n; i++) {
            link[i] = dr[i] + n;
            link[i + n] = lu[i];
        }
        for (int j = 0; j < 30; j++) {
            vector<int> nxt_link(2 * n);
            for (int i = 0; i < 2 * n; i++)
                nxt_link[i] = link[link[i]];
            swap(nxt_link, link);
        }
        string res(n, '?');
        for (int i = 0; i < n; i++) {
            int j1 = link[i] % n;
            int j2 = link[i + n] % n;
            int a0 = max(a[j1], a[j2]);
            int b0 = max(b[j1], b[j2]);
            int pos = upper_bound(crd.begin(), crd.end(), a0) - crd.begin();
            if (pos < sz && f[pos] > b0) res[i] = '0';
            else res[i] = '1';
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