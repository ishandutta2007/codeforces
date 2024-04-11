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

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

    void print() {
    }

    void gen() {
        // use static
    }
};

struct output {
    vector<int> seq;

    output() = default;

    void print() {
        cout << (int) seq.size() << "\n";
        for (auto x : seq)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        return true;
    }
};

output slow(input in) {
    return output();
}

bool is_prime(int x) {
    for (int p = 2; p * p <= x; p++) {
        if (x % p == 0)
            return false;
    }
    return true;
}

output fast(input in) {
    int S = 0;
    for (auto x : in.a) {
        S += x;
    }
    output res;
    if (!is_prime(S)) {
        for (int i = 1; i <= in.n; i++)
            res.seq.push_back(i);
        return res;
    }
    // S >= 3 and prime
    // S mod 2 = 1
    for (int i = 1; i <= in.n; i++) {
        if (in.a[i] % 2) {
            for (int j = 1; j <= in.n; j++) {
                if (i == j)
                    continue;
                res.seq.push_back(j);
            }
            return res;
        }
    }
    return output();
}

void test_case() {
    input in;
    in.read();
    output res = fast(in);
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

void test() {
    while (1) {
        input in;
        in.gen();
        output fs = fast(in);
        output sl = slow(in);
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA\n";
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