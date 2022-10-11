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

const int SZ = 21;

void solve() {
    int n, k;
    cin >> n >> k;

    auto get_mask = [&](int x) {
        vector<int> mask(SZ);
        for (int i = 0; x > 0; i++, x /= k)
            mask[i] = x % k;

        return mask;
    };

    auto restore = [&](vector<int> mask) {
        int x = 0;
        for (int i = SZ - 1; i >= 0; i--)
            x = x * k + mask[i];

        return x;
    };

    vector<int> cur_mask(SZ);
    for (int x = 0; x < n; x++) {
        auto mask = get_mask(x);
        vector<int> need(SZ);
        for (int i = 0; i < SZ; i++)
            need[i] = (mask[i] * (x % 2 == 0 ? 1 : -1) + cur_mask[i] + k) % k;

        cout << restore(need) << endl;
        int r;
        cin >> r;
        if (r)
            return;

        for (int i = 0; i < SZ; i++)
            cur_mask[i] = (need[i] - cur_mask[i] + k) % k;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}