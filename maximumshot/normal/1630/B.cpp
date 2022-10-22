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
    int x, y;
    vector<pii> res;

    void print() {
        cout << x << " " << y << "\n";
        for (auto [l, r] : res)
            cout << l << " " << r << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, k;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; i++)
            cnt[a[i]]++;
        int bl = -1, br = -1;
        int s = 0;
        for (int i = 1; i <= n; i++)
            s -= cnt[i];
        for (int l = 1, r = 1; r <= n; r++) {
            s += 2 * cnt[r];
            while (l < r && s - 2 * cnt[l] >= k) {
                s -= 2 * cnt[l];
                l++;
            }
            if (s >= k && (bl == -1 || br - bl > r - l)) {
                bl = l;
                br = r;
            }
        }
        vector<pii> res;
        int sf = 0;
        for (int i = 1; i <= n; i++)
            sf += (bl <= a[i] && a[i] <= br ? +1 : -1);
        int kk = k;
        for (int i = 1; i <= n; ) {
            if (k == 1) {
                res.emplace_back(i, n);
                break;
            }
            int j = i;
            s = (bl <= a[i] && a[i] <= br ? +1 : -1);
            while (s <= 0 || sf - s < k - 1) {
                j++;
                s += (bl <= a[j] && a[j] <= br ? +1 : -1);
            }
            res.emplace_back(i, j);
            i = j + 1;
            sf -= s;
            k--;
        }
        k = kk;
        while ((int) res.size() > k) {
            auto [l2, r2] = res.back();
            res.pop_back();
            auto [l1, r1] = res.back();
            res.pop_back();
            res.emplace_back(l1, r2);
        }
        return output{bl, br, res};
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