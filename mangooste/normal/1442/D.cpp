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

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n);
    vector<ll> sum(n);

    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        a[i].resize(size);
        for (auto &x : a[i])
            cin >> x;

        sum[i] = accumulate(all(a[i]), 0ll);
    }

    ll answer = 0;
    vector<ll> dp(k + 1);

    y_combinator([&](auto solve, int l, int r) -> void {
        if (r - l == 1) {
            ll pref = 0;
            for (int cnt = 0; cnt <= len(a[l]) && cnt <= k; cnt++) {
                answer = max(answer, pref + dp[k - cnt]);

                if (cnt != len(a[l]))
                    pref += a[l][cnt];
            }
            return;
        }

        auto update_dp = [&](int size, ll sum) {
            for (int j = k; j >= size; j--)
                dp[j] = max(dp[j], dp[j - size] + sum);
        };

        int m = (l + r) / 2;
        {
            auto prev_dp = dp;
            for (int i = m; i < r; i++)
                update_dp(len(a[i]), sum[i]);

            solve(l, m);
            dp = prev_dp;
        }
        {
            for (int i = l; i < m; i++)
                update_dp(len(a[i]), sum[i]);

            solve(m, r);
        }
    })(0, n);

    cout << answer << '\n';
}