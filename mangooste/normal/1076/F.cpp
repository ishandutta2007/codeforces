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

#define int ll

void setmin(int &a, int b) {
    if (a > b)
        a = b;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> cnt(n);
    for (int j : {0, 1})
        for (int i = 0; i < n; i++)
            cin >> cnt[i][j];

    constexpr int INF = 1e8;
    array<int, 2> dp{1, 1};

    for (int i = 0; i < n; i++) {
        if (dp[0] == INF && dp[1] == INF)
            break;

        array<int, 2> new_dp{INF, INF};
        for (int last : {0, 1}) {
            {
                int can_take = dp[last] != INF ? k : k - dp[last ^ 1];
                int limit = (cnt[i][last] - 1) * k;
                int new_cnt = cnt[i][last ^ 1] - max(1ll, min(can_take, max(0ll, cnt[i][last ^ 1] - limit)));

                if (can_take >= 1 && new_cnt <= limit && cnt[i][last] <= (new_cnt + 1) * k) {
                    if (new_cnt * k >= cnt[i][last] - 1)
                        setmin(new_dp[last], 1);
                    else
                        setmin(new_dp[last], cnt[i][last] - new_cnt * k);
                }
            }
            {
                int can_take = dp[last ^ 1] != INF ? k : k - dp[last];
                int limit = (cnt[i][last ^ 1] + k - 1) / k;
                int new_cnt = cnt[i][last] - max(1ll, min({cnt[i][last] - 1, can_take, max(0ll, cnt[i][last] - limit)}));

                if (can_take >= 1 && k * new_cnt >= cnt[i][last ^ 1] && k * cnt[i][last ^ 1] >= new_cnt) {
                    if ((cnt[i][last ^ 1] - 1) * k >= new_cnt - 1)
                        setmin(new_dp[last], 1);
                    else
                        setmin(new_dp[last], new_cnt - (cnt[i][last ^ 1] - 1) * k);
                }
            }
        }

        swap(dp, new_dp);
    }

    cout << (min(dp[0], dp[1]) <= k ? "YES" : "NO") << '\n';
}