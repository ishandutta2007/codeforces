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

    int n, k;
    cin >> n >> k;

    vector<ll> dp(k, -1);
    dp[0] = 0;
    int prev_sum = 0;

    while (n--) {
        int a, b;
        cin >> a >> b;
        vector<ll> ndp(k, -1);

        for (int delta = 0; delta < k; delta++) {
            int na = a - delta;
            int nb = b + (delta == 0 ? 0 : delta - k);
            if (na < 0 || nb < 0)
                continue;

            for (int prev_a = 0; prev_a < k; prev_a++) {
                if (dp[prev_a] == -1)
                    continue;

                int prev_b = (prev_sum - prev_a + k) % k;
                int new_rem = (na + prev_a) % k;
                ndp[new_rem] = max(ndp[new_rem], dp[prev_a] + (delta != 0) + na / k + nb / k
                    + (na % k + prev_a >= k) + (nb % k + prev_b >= k));
            }
        }

        dp = ndp;
        prev_sum = (1ll * prev_sum + a + b) % k;
    }

    cout << *max_element(all(dp)) << '\n';
}