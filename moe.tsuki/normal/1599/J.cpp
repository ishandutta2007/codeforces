#include <bits/stdc++.h>
#ifdef KISEKI
#define debug(a...) ckiseki(#a, a)
template <typename ...T> void ckiseki(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((std::cerr << "\e[1;32m(" << s << ") = ("), ... ,(std::cerr << args << (--cnt ? ", " : ")\e[0m\n")));
}
#define orange(a...) kiseki(#a, a)
template <typename T> void kiseki(const char *s, T L, T R) {
    std::cerr << "\e[1;32m[ " << s << " ] = [ ";
    for (int f = 0; L != R; ++L)
        std::cerr << (f++ ? ", " : "") << *L;
    std::cerr << " ]\e[0m\n";
}
#else
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
#define all(v) begin(v),end(v)

using namespace std;

int table[1400'0000];
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> seq(n), a;
    for (int &x: seq) cin >> x;
    sort(all(seq));
    for (int i = 1; i < n; i++)
        if (seq[i] == seq[i-1]) {
            a.resize(2);
            a[0] = 0;
            a[1] = seq[i];
            for (int j = 0; j < n; j++)
                if (j != i && j != i-1) {
                    a.push_back(seq[j]);
                }
            cout << "YES\n";
            for (int x: a)
                cout << x << ' ';
            cout << '\n';
            return 0;
        }

    vector<int> cnt[2];
    for (int i = 0; i < n; i++)
        cnt[seq[i] % 2].push_back(seq[i]);
    if (cnt[0].size() >= 3) {
        a.resize(3);
        int A = cnt[0][0];
        int B = cnt[0][1];
        int C = cnt[0][2];
        assert ((A + B + C) % 2 == 0);
        int S = (A + B + C) / 2;
        a[0] = S - A;
        a[1] = S - B;
        a[2] = S - C;
        for (int i = 3; i < (int)cnt[0].size(); i++)
            a.push_back(cnt[0][i] - a[0]);
        for (int x: cnt[1])
            a.push_back(x - a[0]);
        cout << "YES\n";
        for (int x: a)
            cout << x << ' ';
        return 0;
    }
    if (cnt[0].size()) {
        if (cnt[1].size() >= 2) {
            a.resize(3);
            int A = cnt[0][0];
            int B = cnt[1][0];
            int C = cnt[1][1];
            assert ((A + B + C) % 2 == 0);
            int S = (A + B + C) / 2;
            a[0] = S - A;
            a[1] = S - B;
            a[2] = S - C;
            for (int i = 1; i < (int)cnt[0].size(); i++)
                a.push_back(cnt[0][i] - a[0]);
            for (int i = 2; i < (int)cnt[1].size(); i++)
                a.push_back(cnt[1][i] - a[0]);
            cout << "YES\n";
            for (int x: a)
                cout << x << ' ';
            return 0;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    assert (cnt[0].empty());

    const int k = min(14, n / 2);
    const int msk = (1 << 14) - 1;
    int x = (1 << k) - 1, y = -1;
    vector<int> lsum(1 << 14), rsum(1 << 14);
    for (int i = 0; i < 14; i++) {
        if (i < n)
            lsum[1 << i] = seq[i];
        if (i + 14 < n)
            rsum[1 << i] = seq[i + 14];
    }

    for (int s = 1; s < (1<<14); s++) {
        lsum[s] = lsum[s - (s&-s)] + lsum[s & -s];
        rsum[s] = rsum[s - (s&-s)] + rsum[s & -s];
    }
    while (x < (1<<min(n, 28))) {
        int sum = lsum[x & msk] + rsum[x >> 14];
        if (table[sum]) {
            y = table[sum];
            break;
        } else {
            table[sum] = x;
        }
        x += x & -x;
        x += (1 << (k - __builtin_popcount(x))) - 1;
    }
    if (y == -1) {
        assert (n < 28);
        cout << "NO\n";
        return 0;
    }

    tie(x, y) = make_pair(x & ~y, y & ~x);
    assert (!(x & y) && __builtin_popcount(x) == __builtin_popcount(y));
    vector<int> cycle(2 * __builtin_popcount(x)), rest;
    for (int i = 0, l = 0, r = 0; i < 28 && i < n; i++) {
        if (x >> i & 1) {
            cycle[l << 1] = seq[i];
            ++l;
        } else if (y >> i & 1) {
            cycle[r << 1 | 1] = seq[i];
            ++r;
        } else {
            rest.push_back(seq[i]);
        }
    }
    for (int i = 28; i < (int)seq.size(); i++)
        rest.push_back(seq[i]);
    a.resize(cycle.size());
    for (int i = 1; i < (int)cycle.size(); i++) {
        a[i] = cycle[i] - a[i-1];
    }
    assert (cycle[0] == a.front() + a.back());
    for (int sum: rest)
        a.push_back(sum - a[0]);

    cout << "YES\n";
    for (int val: a)
        cout << val << ' ';
}