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
    int k;

    input() = default;

    void read() {
        cin >> n >> k;
    }

    void print() {

    }

    void gen() {
        // use static
    }
};

struct output {
    vector<int> colors;

    output() = default;

    void print() {
        int c = *max_element(colors.begin(), colors.end());
        cout << c << "\n";
        for (auto x : colors)
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

output fast(input in) {
    function<vector<vector<int>>(int, int)> rec = [&](int n, int k) -> vector<vector<int>> {
        vector<vector<int>> C(n, vector<int>(n));
        if (n == 1) {
            return C;
        }
        vector<vector<int>> c = rec((n + k - 1) / k, k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i / k == j / k) {
                    C[i][j] = 1;
                } else {
                    C[i][j] = 1 + c[i / k][j / k];
                }
            }
        }
        return C;
    };
    vector<vector<int>> f = rec(in.n, in.k);
    output res;
    for (int i = 1; i <= in.n; i++) {
        for (int j = i + 1; j <= in.n; j++)
            res.colors.push_back(f[i - 1][j - 1]);
    }
    return res;
}

void test_case() {
    input in;
    in.read();
    output res = fast(in);
    res.print();
}

void work() {
    int t = 1;
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