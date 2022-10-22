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

    input() = default;

    void read() {

    }

    void print() {

    }

    void gen() {
        // use static
    }
};

struct output {

    output() = default;

    void print() {

    }

    bool operator == (const output& o) const {
        return true;
    }
};

output slow(input in) {
    return output();
}

output fast(input in) {

}

void test_case() {
    input in;
    in.read();
    output res = fast(in);
    res.print();
}

void work() {
    int n;
    cin >> n;
    auto ask = [&](const vector<int>& a) -> int {
        cout << "? "; for (auto x : a) cout << x << " "; cout << endl;
        int res;
        cin >> res;
        return res;
    };
    vector<int> p(n + 1);
    int y = 1;
    while (y < n) {
        vector<int> a(n, 1);
        a[n - 1] += y;
        if (!ask(a)) {
            p[n] = n + 1 - y;
            break;
        } else {
            y++;
        }
    }
    if (y == n) p[n] = 1;
    y = p[n];
    for (int x = 1; x <= n; x++) {
        if (x == y)
            continue;
        int delta = y - x;
        vector<int> a(n);
        if (delta > 0) {
            for (int j = 0; j < n - 1; j++)
                a[j] = delta + 1;
            a[n - 1] = 1;
        } else {
            for (int j = 0; j < n; j++) {
                a[j] += -delta + 1;
            }
            for (int j = 0; j < n - 1; j++)
                a[j] += delta;
        }
        int pos = ask(a);
        p[pos] = x;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << endl;
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
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}