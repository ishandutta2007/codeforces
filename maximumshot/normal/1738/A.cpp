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
        ll res = -inf64;
        vector<int> cnt(2);
        for (auto x : a) cnt[x]++;
        vector<int> v[2];
        for (int i = 0; i < n; i++)
            v[a[i]].push_back(b[i]);
        for (int x = 0; x < 2; x++)
            sort(v[x].rbegin(), v[x].rend());
        for (int s = 0; s < 2; s++) {
            if (cnt[s] == 0) continue;
            vector<int> type(n), cc = cnt;
            cc[s]--;
            type[0] = s;
            for (int i = 1; i < n; i++) {
                int x = type[i - 1] ^ 1;
                if (cc[x]) cc[x]--, type[i] = x;
                else cc[x ^ 1]--, type[i] = x ^ 1;
            }
            vector<int> val(n), vv[2];
            vv[0] = v[0], vv[1] = v[1];
            val[0] = vv[s].back();
            vv[s].pop_back();
            int ptr[2] = {0, 0};
            for (int i = 1; i < n; i++)
                val[i] = vv[type[i]][ptr[type[i]]++];
            ll tmp = 0;
            for (int i = 0; i < n; i++) {
                int cur = val[i];
                if (i > 0 && type[i] != type[i - 1])
                    cur *= 2;
                tmp += cur;
            }
            res = max(res, tmp);
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