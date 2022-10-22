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
    vector<pii> res;

    void print() {
        cout << (int) res.size() << "\n";
        for (auto [l, r] : res)
            cout << l + 1 << " " << r + 1 << "\n";
    }

    bool operator == (const output& o) const {
        return res.size() == o.res.size();
    }
};

bool is_balanced(string s) {
    int b = 0;
    for (char c : s) {
        if (c == ')') b--;
        else b++;
        if (b < 0) return false;
    }
    if (b) return false;
    return true;
}

bool validate(vector<pii> res, string s) {
    for (auto [l, r] : res) {
        reverse(s.begin() + l, s.begin() + r + 1);
    }
    return is_balanced(s);
}

pair<bool, vector<pii>> solve1(int n, string s) {
    vector<int> seq = {0};
    int b = 0;
    for (char c : s) {
        if (c == '(') b++;
        else b--;
        seq.push_back(b);
    }
    vector<pii> res;
    if (*min_element(seq.begin(), seq.end()) >= 0) return {true, {}};
    else {
        int ql = 0;
        while (seq[ql] >= 0) ql++;
        int qr = n;
        while (seq[qr] >= 0) qr--;
        int X = *max_element(seq.begin() + ql, seq.begin() + qr + 1);
        vector<int> ar(n + 1, X);
        for (int j = ql - 1; j >= 0; j--) {
            ar[j] = max(ar[j + 1], seq[j]);
        }
        for (int j = qr + 1; j <= n; j++) {
            ar[j] = max(ar[j - 1], seq[j]);
        }
        for (int mx = -1, j = ql, i = qr + 1; i <= n; i++) {
            while (j > 0 && ar[j - 1] <= ar[i]) {
                j--;
                if (mx == -1 || seq[mx] < seq[j]) mx = j;
            }
            if (mx != -1 && seq[i] + seq[mx] - ar[i] >= 0) {
                res = {{mx, i - 1}};
                break;
            }
        }
        for (int mx = -1, i = qr, j = ql - 1; j >= 0; j--) {
            while (i < n && ar[i + 1] <= ar[j]) {
                i++;
                if (mx == -1 || seq[mx] < seq[i]) mx = i;
            }
            if (mx != -1 && seq[mx] + seq[j] - ar[j] >= 0) {
                res = {{j, mx - 1}};
                break;
            }
        }
        if (res.empty()) return {false, {}};
        else return {true, res};
    }
}

vector<pii> solve2(int n, string s) {
    vector<int> seq = {0};
    int b = 0;
    for (char c : s) {
        if (c == '(') b++;
        else b--;
        seq.push_back(b);
    }
    int mx = max_element(seq.begin(), seq.end()) - seq.begin();
    int mn = min_element(seq.begin(), seq.end()) - seq.begin();
    vector<int> pts = {mn, mx, 0, n};
    for (int l : pts) {
        for (int r : pts) {
            if (l >= r) continue;
            string t = s;
            reverse(t.begin() + l, t.begin() + r);
            auto [flg, res] = solve1(n, t);
            if (flg) {
                res.insert(res.begin(), make_pair(l, r - 1));
                return res;
            }
        }
    }
}

struct input {
    int n;
    string s;

    input() = default;

    void read() {
        cin >> n >> s;
        n *= 2;
    }

    void print() {
        cout << n / 2 << "\n" << s << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 100;
        n = rnd() % MAXN + 1;
        s.resize(2 * n, '?');
        for (int i = 0; i < 2 * n; i++)
            s[i] = i < n ? '(' : ')';
        shuffle(s.begin(), s.end(), rnd);
        n *= 2;
    }

    void gen_max_test() {

    }

    output fast() {
        auto [flg, res] = solve1(n, s);
        if (!flg) {
            res = solve2(n, s);
        }
#ifdef DEBUG
        assert(validate(res, s));
#endif
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return fast();
        vector<int> dist(1 << n, inf);
        vector<tuple<int, int, int>> fr(1 << n, make_tuple(-1, -1, -1));
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') start |= 1 << i;
        }
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int finish = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            string sv(n, '?');
            for (int i = 0; i < n; i++) {
                if ((1 << i) & v) sv[i] = '(';
                else sv[i] = ')';
            }
            if (is_balanced(sv)) {
                finish = v;
                break;
            }
            for (int l = 0; l < n; l++) {
                for (int r = l; r < n; r++) {
                    string s_to = sv;
                    reverse(s_to.begin() + l, s_to.begin() + r + 1);
                    int to = 0;
                    for (int i = 0; i < n; i++) {
                        if (s_to[i] == '(') to |= 1 << i;
                    }
                    if (dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        fr[to] = {l, r, v};
                        q.push(to);
                    }
                }
            }
        }
        vector<pii> res;
        while (finish != start) {
            auto [l, r, v] = fr[finish];
            res.emplace_back(l, r);
            finish = v;
        }
        reverse(res.begin(), res.end());
        assert(validate(res, s));
        return output{res};
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
        in.print();
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