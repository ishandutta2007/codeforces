#pragma GCC optimize("O3")

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

    string s;
    int x;
    cin >> s >> x;
    const int MASK = 1 << (x - 1);

    int divisors = 0;
    for (int i = 1; i < x; i++)
        if (x % i == 0)
            divisors ^= 1 << (i - 1);

    vector<vector<pair<int, int>>> good_masks(10);
    for (int mask = 0; mask < MASK; mask++)
        for (int y = 1; y < 10; y++) {
            if (mask & divisors || y == x)
                continue;

            if (y < x && x % y != 0) {
                int z = x - y - 1;
                if (mask >> z & 1) {
                    int submask = mask & ((1 << (z + 1)) - 1);
                    if (!((submask & divisors) || ((submask << y) & divisors)))
                        continue;
                }
            }

            int new_mask = (((mask << y) ^ (1 << (y - 1)))) & (MASK - 1);
            if (new_mask & divisors) {
                int a = new_mask & divisors;
                int f = 0;
                while (!(a >> f & 1))
                    f++;

                new_mask &= (1 << f) - 1;
            }

            good_masks[y].emplace_back(mask, new_mask);
        }

    vector<int> dp(MASK, -len(s));
    dp[0] = 0;
    vector<int> new_dp(MASK);

    for (auto c : s) {
        int y = c - '0';
        new_dp = dp;
        for (auto &[mask, new_mask] : good_masks[y])
            new_dp[new_mask] = max(new_dp[new_mask], dp[mask] + 1);

        swap(dp, new_dp);
    }

    cout << len(s) - *max_element(all(dp)) << '\n';
}