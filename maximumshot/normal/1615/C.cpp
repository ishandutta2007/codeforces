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
        return res == o.res;
    }
};

struct input {
    int n;
    string a, b;

    input() = default;

    void read() {
        cin >> n >> a >> b;
    }

    void print() {
        cout << n << "\n" << a << "\n" << b << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 1;
        a.resize(n, '?');
        b.resize(n, '?');
        for (int i = 0; i < n; i++) {
            a[i] = rnd() % 2 + '0';
            b[i] = rnd() % 2 + '0';
        }
    }

    int min_even(vector<int> c) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += c[i];
        }
        return cnt % 2 ? inf : cnt;
    }

    int min_odd(vector<int> c) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += c[i];
        }
        return cnt % 2 ? cnt : inf;
    }

    output fast() {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            c1 += a[i] == '1';
            c2 += b[i] == '1';
        }
        if (c1 != c2 && c1 + c2 != n + 1)
            return output{-1};
        int d1 = 0, d2 = 0;
        for (int i = 0; i < n; i++)
            d1 += a[i] != b[i], d2 += a[i] == b[i];
        if (d1 % 2 == 1 || c1 != c2) d1 = inf;
        if (d2 % 2 == 0 || c1 + c2 != n + 1) d2 = inf;
        int res = min(d1, d2);
        if (res == inf)
            res = -1;
        return output{res};
    }

    output slow() {
        vector<int> dist(1 << n, inf);
        int st = 0, fn = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1') st |= 1 << i;
            if (b[i] == '1') fn |= 1 << i;
        }
        dist[st] = 0;
        queue<int> q;
        q.push(st);
        int all = ((1 << n) - 1);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if ((1 << i) & v) {
                    int to = v ^ all ^ (1 << i);
                    if (dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        q.push(to);
                    }
                }
            }
        }
        int res = dist[fn];
        if (res == inf)
            res = -1;
        return output{res};
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