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
    vector<int> a(n);
    vector<vector<int>> positions(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        positions[a[i]].push_back(i);
    }

    auto get_freq = [&](int x, int l, int r) {
        return lower_bound(all(positions[x]), r) - lower_bound(all(positions[x]), l);
    };

    vector<int> count(n);
    int timer = 0;
    vector<int> used(n);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k, l--;
        int need = (r - l) / k;

        constexpr int ITERS = 200;
        constexpr int WHEN = 8;

        vector<int> good;
        good.reserve(ITERS / WHEN);
        timer++;

        for (int it = 0; it < ITERS; it++) {
            int x = a[l + rng() % (r - l)];
            if (used[x] != timer) {
                used[x] = timer;
                count[x] = 0;
            }
            if (++count[x] == WHEN)
                good.push_back(x);
        }

        int answer = INT_MAX;
        for (auto x : good)
            if (get_freq(x, l, r) > need && answer > x)
                answer = x;

        cout << (answer == INT_MAX ? -1 : answer + 1) << '\n';
    }
}