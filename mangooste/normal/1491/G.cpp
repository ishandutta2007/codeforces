#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> perm(n);
    for (auto &x : perm)
        cin >> x, x--;

    vector<pair<int, int>> ops;

    auto do_swap = [&](int i, int j) {
        swap(perm[i], perm[j]);
        perm[i] *= -1, perm[j] *= -1;
        ops.emplace_back(i, j);
    };

    vector<vector<int>> cycles;
    vector<char> used(n);
    for (int i = 0; i < n; i++)
        if (perm[i] == i)
            used[i] = 1;

    for (int i = 0; i < n; i++)
        if (!used[i]) {
            cycles.push_back({});
            for (int j = i; !used[j]; used[j] = 1, j = perm[j])
                cycles.back().push_back(j);
        }

    while (len(cycles) > 1) {
        const auto first = cycles.back();
        cycles.pop_back();
        const auto second = cycles.back();
        cycles.pop_back();

        do_swap(first[0], second[0]);
        for (int i = 1; i < len(first); i++)
            do_swap(second[0], first[i]);

        for (int i = 1; i < len(second); i++)
            do_swap(first[0], second[i]);

        do_swap(first[0], second[0]);
    }

    if (len(cycles)) {
        const auto cycle = cycles[0];
        int good = 0;
        while (good < n && perm[good] != good)
            good++;

        if (good != n) {
            do_swap(cycle[0], good);
            for (int i = 1; i < len(cycle); i++)
                do_swap(good, cycle[i]);

            do_swap(cycle[0], good);
        } else {
            assert(len(cycle) > 2);
            do_swap(cycle[0], cycle[1]);
            for (int i = 2; i < len(cycle) - 1; i++)
                do_swap(cycle[0], cycle[i]);

            do_swap(cycle[1], cycle.back());
            do_swap(cycle[0], cycle.back());
            do_swap(cycle[0], cycle[1]);
        }
    }

    assert(len(ops) <= n + 1);
    for (int i = 0; i < n; i++)
        assert(perm[i] == i);

    cout << len(ops) << '\n';
    for (const auto &[i, j] : ops)
        cout << i + 1 << ' ' << j + 1 << '\n';
}