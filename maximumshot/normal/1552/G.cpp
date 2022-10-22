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
        cout << (res ? "ACCEPTED" : "REJECTED") << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

ll sort_submask(ll mask, ll to_sort) {
    ll base = mask & (~to_sort);
    ll flex = mask & to_sort;
    int cnt0 = __builtin_popcountll(to_sort & (~flex));
#ifdef DEBUG
    cout << "sort\n";
    cout << "\tmask = " << bitset<3>(mask) << "\n";
    cout << "\tto_sort = " << bitset<3>(to_sort) << "\n";
    cout << "\tresult = " << bitset<3>(base) << "\n";
    cout << "\tcnt0 = " << cnt0 << "\n";
#endif
    for (int ptr = 0, i = 0; (1ll << i) <= to_sort; i++) {
        if ((1ll << i) & to_sort) {
            if (ptr++ >= cnt0) base |= 1ll << i;
        }
    }
    return base;
}

struct input {
    int n, k;
    vector<vector<int>> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(k);
        for (int i = 0; i < k; i++) {
            int sz;
            cin >> sz;
            a[i].resize(sz);
            for (auto& pos : a[i]) cin >> pos, pos--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        if (n == 1) return output{1};
        vector<ll> used(k), pref_used(k);
        for (int i = 0; i < k; i++) {
            for (int j : a[i])
                used[i] |= 1ll << j;
            pref_used[i] = (i ? pref_used[i - 1] : 0ll) | used[i];
        }
        if (k == 0 || pref_used[k - 1] != (1ll << n) - 1) return output{0};
        function<bool(int, ll)> rec = [&](int it, ll cur) -> bool {
            if (it == k) {
                int cnt = __builtin_popcountll(cur);
                ll need = ((1ll << cnt) - 1) << (n - cnt);
#ifdef DEBUG
                if (need != cur) {
                    cout << "it = " << it << "\n";
                    cout << "cur = " << bitset<4>(cur) << "\n";
                    cout << "need = " << bitset<4>(need) << "\n";
                    cout << "cnt = " << cnt << "\n";
                }
#endif
                return need == cur;
            }
            ll diff = pref_used[it] ^ (it ? pref_used[it - 1] : 0ll);
            while (1) {
                if (!rec(it + 1, sort_submask(cur | diff, used[it]))) return false;
                if (!diff) break;
                diff ^= 1ll << __builtin_ctzll(diff);
            }
            return true;
        };
        return output{rec(0, 0ll)};
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
    int t = 1;
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

    work();
//    test();
//    max_test();

    return 0;
}