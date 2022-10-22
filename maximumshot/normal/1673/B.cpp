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
        cout << (res ? "YES" : "NO") << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    string s;

    input() = default;

    void read() {
        cin >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int n = (int) s.size();
        vector<int> f(n, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            f[i] = last[x];
            last[x] = i;
        }
        vector<vector<int>> cnt(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            cnt[i + 1][s[i] - 'a']++;
        }
        vector<int> used(26);
        for (char c : s) used[c - 'a'] = 1;
        for (int i = 0; i < n; i++) {
            int j = f[i];
            if (j == -1)
                continue;
            for (int x = 0; x < 26; x++) {
                if (!used[x] || x == s[i] - 'a')
                    continue;
                if (cnt[i + 1][x] - cnt[j][x] == 0)
                    return output{0};
            }
        }
        for (int i = 0; i < n; i++) {
            int j = f[i];
            if (j == -1) continue;
            j = f[j];
            if (j == -1) continue;
            for (int x = 0; x < 26; x++) {
                if (!used[x])
                    continue;
                if (x == s[i] - 'a' + 1)
                    continue;
                if (cnt[i + 1][x] - cnt[j][x] <= 1)
                    return output{0};
            }
        }
        return output{1};
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