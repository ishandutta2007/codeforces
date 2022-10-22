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

    void print() {

    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {

    input() = default;

    void read() {

    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        return output();
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

int cnt = 0;
int ask(vector<int> a) {
    cout << "? " << (int) a.size() << " ";
    cnt++;
    assert(cnt <= 82);
    for (auto x : a) cout << x << " ";
    cout << endl;
    string s;
    cin >> s;
    return s == "YES";
}

vector<int> concat(vector<int> a, vector<int> b) {
    for (auto x : b) a.push_back(x);
    return a;
}

void solve(vector<int> a) {
    int sz = (int) a.size();
    if (sz <= 2) {
        for (int x : a) {
            cout << "! " << x << endl;
            string res;
            cin >> res;
            if (res == ":)") break;
        }
        return;
    }
    int k = (sz + 1) / 3;
    // [0, k)[k, 2*k)[2*k,n)
    assert(2 * k < sz);

    vector<int> le, mid, ri;
    for (int i = 0; i < k; i++)
        le.push_back(a[i]);
    for (int i = k; i < 2 * k; i++)
        mid.push_back(a[i]);
    for (int i = 2 * k; i < sz; i++)
        ri.push_back(a[i]);

    vector<int> nxt;

    int A = ask(concat(le, mid));

    if (A == 0) {
        int B = ask(concat(mid, ri));
        if (B == 0) {
            nxt = concat(le, ri);
        } else {
            nxt = concat(mid, ri);
        }
    } else {
        int B = ask(ri);
        if (B == 0) {
            nxt = concat(le, mid);
        } else {
            int C = ask(mid);
            if (C == 0) {
                nxt = concat(le, ri);
            } else {
                nxt = concat(mid, ri);
            }
        }
    }

    solve(nxt);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    solve(a);

    return 0;
}