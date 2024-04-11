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
    string s;

    void print() {
        cout << s << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int k, n;
    ll x;
    string s;

    input() = default;

    void read() {
        cin >> n >> k >> x >> s;
    }

    void print() {
    }

    void gen() {
        // use static
    }

    output fast() {
        vector<ll> a;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*')
                continue;
            int j = i;
            while (j < n && s[j] == '*') j++;
            j--;
            // [i, j]
            int cnt = j - i + 1;
            a.push_back(1ll * cnt * k + 1);
            i = j;
        }
        if (a.empty())
            return output{s};
        int sz = (int) a.size();
        int i = sz;
        __int128 cur = 1;
        while (cur < x) {
            i--;
            cur *= __int128(a[i]);
        }
        vector<ll> sf(sz + 1); sf[sz] = 1;
        for (int j = sz - 1; j >= 0; j--)
            sf[j] = sf[j + 1] * a[j];
        vector<int> cnt(sz);
        while (i < sz) {
            if (x <= sf[i + 1]) {
                i++;
                continue;
            }
            // x - tmp * sf[i + 1] <= sf[i + 1]
            // tmp >= (x - sf[i + 1]) / sf[i + 1]
            ll tmp = (x - sf[i + 1] + sf[i + 1] - 1) / sf[i + 1];
            x -= tmp * sf[i + 1];
            cnt[i] = tmp;
            i++;
        }
        string res;
        int ptr = 0;
        for (i = 0; i < n; i++) {
            if (s[i] != '*') {
                res.push_back(s[i]);
                continue;
            }
            int j = i;
            while (j < n && s[j] == '*') j++;
            j--;
            res += string(cnt[ptr], 'b');
            ptr++;
            i = j;
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