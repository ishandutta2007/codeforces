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
    vector<int> res;

    void print() {
        cout << (int) res.size() << "\n";
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> cnt(n + 2), used(n + 2);
        int timer = 10;
        for (auto x : a)
            cnt[x]++;
        int mex = 0;
        while (cnt[mex]) mex++;
        vector<int> res;
        for (int i = 0; i < n;) {
            int curmex = 0;
            int j = i + 1;
            timer++;
            if (a[i] == 0) curmex++;
            cnt[a[i]]--;
            used[a[i]] = timer;
            int next_mex = mex;
            if (cnt[a[i]] == 0) next_mex = min(next_mex, a[i]);
            while (j < n && curmex < mex) {
                used[a[j]] = timer;
                cnt[a[j]]--;
                if (cnt[a[j]] == 0)
                    next_mex = min(next_mex, a[j]);
                j++;
                while (used[curmex] == timer)
                    curmex++;
            }
            res.push_back(curmex);
            i = j;
            mex = next_mex;
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