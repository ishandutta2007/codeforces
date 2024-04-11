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
    vector<vector<vector<int>>> res;

    void print() {
        for (int i = 0; i < (int) res.size(); i++) {
            for (int j = 0; j < (int) res[i].size(); j++) {
                cout << (int) res[i][j].size() << " ";
                for (auto x : res[i][j])
                    cout << x << " ";
                cout << "\n";
            }
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m, k;

    input() = default;

    void read() {
        cin >> n >> m >> k;
    }

    void print() {
    }

    void gen() {
        // use static
    }

    output fast() {
        vector<vector<vector<int>>> res;
        vector<int> b(n + 1), perm(n);
        iota(perm.begin(), perm.end(), 1);
        int big = (n + m - 1) / m, small = n / m;
        int cnt_big = n % m;
        int cnt_small = m - cnt_big;
        vector<int> cap(m, small);
        for (int i = 0; i < cnt_big; i++)
            cap[i] = big;
        for (int it = 0; it < k; it++) {
            sort(perm.begin(), perm.end(), [&](int i, int j) {
                return b[i] < b[j];
            });
            vector<vector<int>> tmp(m);
            int cur = 0;
            for (int i : perm) {
                if ((int) tmp[cur].size() == cap[cur]) cur++;
                tmp[cur].push_back(i);
                if (cap[cur] == big) b[i]++;
            }
            res.push_back(tmp);
        }
        return output{res};
    }

    output slow() {
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