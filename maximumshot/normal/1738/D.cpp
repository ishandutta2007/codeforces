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
    int k;
    vector<int> a;

    void print() {
        cout << k << "\n";
        for (int i = 1; i < (int) a.size(); i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        return true;
    }
};

vector<int> gen(int n, int k, vector<int> a) {
    vector<int> b(n + 1);
    int last_le = 0;
    int last_gt = n + 1;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (x <= k) {
            b[x] = last_gt;
            last_le = x;
        } else {
            b[x] = last_le;
            last_gt = x;
        }
    }
    return b;
}

struct input {
    int n, kk;
    vector<int> b, aa;

    input() = default;

    void read() {
        cin >> n;
        b.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> b[i];
    }

    void print() {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        n = rnd() % MAXN + 1;
        vector<int> a(n + 1);
        iota(a.begin(), a.end(), 0);
        shuffle(a.begin() + 1, a.end(), rnd);
        int k = rnd() % (n + 2);
        b = ::gen(n, k, a);
        aa = a;
        kk = k;
    }

    void gen_max_test() {

    }

    output fast() {
//        if (*max_element(b.begin() + 1, b.end()) == 0) {
//            int k = 0;
//            vector<int> a(n + 1);
//            iota(a.begin(), a.end(), 0);
//            return output{k, a};
//        }
        int k = 0;
        while (k < n && b[k + 1] > k + 1) k++;
        int cur = 0, cur_b = 0;
        vector<int> vis(n + 2);
        for (int i = 1; i <= n; i++) {
            vis[b[i]] = 1;
            if (b[i] == 0) cur = +1, cur_b = 0;
            if (b[i] == n + 1) cur = -1, cur_b = n + 1;
        }
        vector<vector<int>> where(n + 2);
        for (int i = 1; i <= n; i++)
            where[b[i]].push_back(i);
        vector<int> res = {0};
        while ((int) res.size() <= n) {
            vector<int> ar = where[cur_b];
            sort(ar.begin(), ar.end(), [&](int i, int j) {
                return vis[i] < vis[j];
            });
            for (int i : ar)
                res.push_back(i);
            cur_b = ar.back();
        }
        return output{k, res};
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
        in.print();
        cout.flush();
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