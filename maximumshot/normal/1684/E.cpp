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
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

int mex(vector<int> a) {
    sort(a.begin(), a.end());
    if (a.front() > 0) return 0;
    for (int i = 0; i + 1 < (int) a.size(); i++) {
        if (a[i] + 1 < a[i + 1])
            return a[i] + 1;
    }
    return a.back() + 1;
}

int diff(vector<int> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return (int) a.size();
}

struct input {
    int n, k;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> k;
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
        vector<int> mem_a = a;
        int mem_k = k;
        sort(a.begin(), a.end());
        if (k > 0 && a.front() > 0) {
            a.pop_back();
            a.insert(a.begin(), 0);
            k--;
        }
        if (a.front() > 0) {
            set<int> q(a.begin(), a.end());
            return output{(int) q.size()};
        }
        vector<int> q;
        for (int i = 0; i + 1 < (int) a.size() && k > 0; i++) {
            if (a[i] + 1 >= a[i + 1])
                continue;
            a.pop_back();
            k--;
            q.push_back(a[i]);
            a[i]++;
            i--;
        }
        for (int x : q) a.push_back(x);
        int MEX = mex(a);
        int DIFF = inf;

        a = mem_a;
        k = mem_k;
        int c_ge = 0;
        for (int x : a) {
            if (x >= MEX)
                c_ge++;
        }
        if (c_ge <= k) {
            DIFF = MEX;
        } else {
            unordered_map<int, int> cnt;
            for (int x : a) {
                if (x > MEX) cnt[x]++;
                else if (x == MEX) k--;
            }
            vector<int> ar;
            for (auto [x, c] : cnt) {
                ar.push_back(c);
            }
            sort(ar.rbegin(), ar.rend());
            while (!ar.empty() && ar.back() <= k) {
                k -= ar.back();
                ar.pop_back();
            }
            DIFF = MEX + (int) ar.size();
        }
        int res = DIFF - MEX;
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