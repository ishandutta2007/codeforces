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
        return res == o.res;
    }
};

struct input {
    int n, a, b, c;
    string s;

    input() = default;

    void read() {
        cin >> n >> a >> b >> c >> s;
    }

    void print() {
        cout << n << " " << a << " " << b << " " << c << "\n" << s << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        const int MAXX = 5;
        n = rnd() % MAXN + 1;
        a = rnd() % MAXX + 1;
        b = rnd() % MAXX + 1;
        c = rnd() % MAXX + 1;
        s.resize(n, '?');
        for (char& c : s)
            c = rnd() % 2 + '0';
    }

    void gen_max_test() {

    }

    output fast() {
        if (s == string(n, '1'))
            return output{b * (n > 1)};
        if (s == string(n, '0'))
            return output{a * (n > 1)};
        int l0 = 0, l1 = 0;
        int c0 = 0, c1 = 0;
        for (char c : s) {
            if (c == '0') c0++;
            else c1++;
        }
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[i] == s[j]) j++; j--;
            if (s[i] == '0') l0 += j - i;
            else l1 += j - i;
            i = j;
        }
        ll res = 0;
        if (l0 <= l1) {
            res += 1ll * l0 * (a + b);
            int rem0 = c0, rem1 = l1;
            rem0 -= l0;
            rem1 -= l0;
            if (l1 > l0) res += b, rem1--;
            if (s[0] == '0') rem0--;
            if (s[n - 1] == '0') rem0--;
            res += 1ll * max(0, b - c) * rem0;
            if (s[0] == '0') {
                int j = 0;
                while (s[j] == '0') j++;
                if (j + 1 < n && s[j] == '1' && rem1 > 0) {
                    res += max(0, b - c);
                    rem1--;
                }
            }
            if (s[n - 1] == '0') {
                int j = n - 1;
                while (s[j] == '0') j--;
                if (j > 0 && s[j] == '1' && rem1 > 0) {
                    res += max(0, b - c);
                    rem1--;
                }
            }
        } else {
            res += 1ll * l1 * (a + b);
            ll tmp = res;
            if (l0 > l1) tmp += a;
            vector<int> lens;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    continue;
                int j = i;
                while (j < n && s[j] == '0') j++; j--;
                if (i > 0 && j + 1 < n)
                    lens.push_back(j - i + 1);
                i = j;
            }
            sort(lens.begin(), lens.end());
            int rem = l1;
            for (int x : lens) {
                if (x - 1 <= rem) {
                    rem -= x - 1;
                    res += max(0, b - c);
                }
            }
            if (l0 > l1) res += a;
            res = max(res, tmp);
        }
        return output{res};
    }

    output slow() {
        map<string, int> dp;
        dp["0" + s] = 0;
        dp["1" + s] = 0;
        queue<string> q;
        q.push("0" + s);
        q.push("1" + s);
        while (!q.empty()) {
            string v = q.front();
            int now = dp[v];
            q.pop();
            int x = v[0] - '0';
            v.erase(v.begin());
            int l = (int) v.size();
            if (x == 0) {
                for (int i = 0; i < l; i++) {
                    if (v[i] == '0') {
                        string to = v;
                        to.erase(to.begin() + i);
                        to = "1" + to;
                        int was = dp.count(to) ? dp[to] : -inf;
                        if (was < now - c) {
                            dp[to] = now - c;
                            q.push(to);
                        }
                    }
                    if (i + 1 < l && v[i] == '0' && v[i + 1] == '0') {
                        string to = v;
                        to.erase(to.begin() + i);
                        to = "1" + to;
                        int was = dp.count(to) ? dp[to] : -inf;
                        if (was < now + a) {
                            dp[to] = now + a;
                            q.push(to);
                        }
                    }
                }
            } else {
                for (int i = 0; i + 1 < l; i++) {
                    if (v[i] == '1' && v[i + 1] == '1') {
                        string to = v;
                        to.erase(to.begin() + i);
                        to = "0" + to;
                        int was = dp.count(to) ? dp[to] : -inf;
                        if (was < now + b) {
                            dp[to] = now + b;
                            q.push(to);
                        }
                    }
                }
            }
        }
        int res = -inf;
        string best;
        for (auto [v, x] : dp) {
            if (x > res) {
                res = x;
                best = v;
            }
        }
//        cout << "best = " << best << "\n";
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