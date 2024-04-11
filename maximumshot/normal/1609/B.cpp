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
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, q;
    string s;
    vector<pair<int, char>> seq;

    input() = default;

    void read() {
        cin >> n >> q >> s;
        seq.resize(q);
        for (auto& [pos, symb] : seq)
            cin >> pos >> symb, pos--;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        auto check = [&](int i) -> int {
            if (i + 2 >= (int) s.size() || i < 0)
                return false;
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
                return true;
            return false;
        };
        int total = 0;
        for (int i = 0; i + 2 < (int) s.size(); i++)
            total += check(i);
        vector<int> res;
        for (auto [pos, symb] : seq) {
            total = total - (check(pos) + check(pos - 1) + check(pos - 2));
            s[pos] = symb;
            total = total + (check(pos) + check(pos - 1) + check(pos - 2));
            res.push_back(total);
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
    int t = 1;
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