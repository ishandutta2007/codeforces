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

    int n, q;
    cin >> n >> q;
    vector<vector<int>> positions(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        positions[--a[i]].push_back(i);
    }

    const int LG = __lg(n) + 1;
    vector<vector<int>> pref(LG, vector<int>(n + 1));
    for (int bit = 0; bit < LG; bit++)
        for (int i = 0; i < n; i++)
            pref[bit][i + 1] = pref[bit][i] + (a[i] >> bit) % 2;

    auto freq = [&](int value, int l, int r) -> int {
        if (value >= n || value < 0)
            return 0;

        return lower_bound(all(positions[value]), r) - lower_bound(all(positions[value]), l);
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; 

        int value = 0;
        for (int bit = 0; bit < LG; bit++)
            if (pref[bit][r] - pref[bit][l] > (r - l + 1) / 2)
                value ^= 1 << bit;

        int cnt = freq(value, l, r);
        cout << max(1, 2 * cnt - r + l) << '\n';
    }
}