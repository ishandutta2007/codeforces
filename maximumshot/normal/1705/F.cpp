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

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

#ifdef DEBUG
    n = 1000;
    string gold(n, '?');
    mt19937 rnd(42);
    for (auto& x : gold)
        x = rnd() % 2 ? 'T' : 'F';
//    gold = "TTF";
//    n = (int) gold.size();
    cout << "gold = " << gold << "\n";
#else
    cin >> n;
#endif

    int cnt = 0;
    auto ask = [&](string s) {
        cnt++;
        int res = 0;
#ifdef DEBUG
        for (int i = 0; i < n; i++) {
            if (s[i] == gold[i])
                res++;
        }
#else
        cout << s << endl;
        cin >> res;
#endif
        if (res == n) {
#ifdef DEBUG
            cout << "found ! s = " << s << "\n";
            cout << "total number of questions = " << cnt << "\n";
            cout.precision(5);
            cout << fixed;
            cout << "relative number of questions = " << 1.0 * cnt / n << "\n";
#endif
            exit(0);
        }
        return res;
    };

    string tt(n, 'T');
    int TT = ask(tt);

    string tf(n, '?');
    for (int i = 0; i < n; i++)
        tf[i] = i % 2 == 0 ? 'T' : 'F';
    int TF = ask(tf);
    auto delta = 'T' ^ 'F';

    string s(n, 'T');

    int i = 0;
    for (i = 0; i + 2 < n; i += 3) {
        int q1 = i;
        int q2 = i + 1;
        int q3 = i + 2;

        tt[q1] ^= delta;
        tt[q2] ^= delta;
        int nTT = ask(tt);
        tt[q1] ^= delta;
        tt[q2] ^= delta;

        if (nTT == TT) {
            tf[q1] ^= delta;
            tf[q2] ^= delta;
            tf[q3] ^= delta;
            int nTF = ask(tf);
            tf[q1] ^= delta;
            tf[q2] ^= delta;
            tf[q3] ^= delta;

            if (nTF == TF + 3) {
                s[q1] = tf[q1] ^ delta;
                s[q2] = tf[q2] ^ delta;
                s[q3] = tf[q3] ^ delta;
            } else if (nTF == TF - 3) {
                s[q1] = tf[q1];
                s[q2] = tf[q2];
                s[q3] = tf[q3];
            } else if (nTF == TF - 1) {
                s[q1] = tf[q1];
                s[q2] = tf[q2];
                s[q3] = tf[q3] ^ delta;
            } else {
                s[q1] = tf[q1] ^ delta;
                s[q2] = tf[q2] ^ delta;
                s[q3] = tf[q3];
            }
        } else {
            if (nTT == TT + 2) {
                s[q1] = tt[q1] ^ delta;
                s[q2] = tt[q2] ^ delta;
            } else if (nTT == TT - 2) {
                s[q1] = tt[q1];
                s[q2] = tt[q2];
            }

            tt[q2] ^= delta;
            tt[q3] ^= delta;
            nTT = ask(tt);
            tt[q2] ^= delta;
            tt[q3] ^= delta;

            if (nTT == TT) {
                s[q3] = s[q2] ^ delta;
            } else {
                s[q3] = s[q2];
            }
        }
    }

    int cur = ask(s);
    while (i < n) {
        s[i] ^= delta;
        int tmp = ask(s);
        if (tmp > cur) {
            cur = tmp;
        } else {
            s[i] ^= delta;
        }
        i++;
    }
    ask(s);

    return 0;
}