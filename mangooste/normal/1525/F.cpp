#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<typename T>
inline bool setmin(T &a, const T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
inline bool setmax(T &a, const T b) { if (a < b) { a = b; return true; } return false; }


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vec<vec<int>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;

        g[v].push_back(u);
    }

    vec<ar<char, 2>> banned(n);
    vec<int> matched(n);
    vec<int> used(n);
    int timer, mx;

    auto init = [&]() {
        fill(all(matched), -1);
        fill(all(used), -1);
        timer = mx = 0;

        auto khun = y_combinator([&](auto khun, int v) -> bool {
            if (used[v] == timer || banned[v][0])
                return false;

            used[v] = timer;

            for (auto u : g[v])
                if (!banned[u][1] && matched[u] == -1) {
                    matched[u] = v;
                    return true;
                }

            for (auto u : g[v])
                if (!banned[u][1] && khun(matched[u])) {
                    matched[u] = v;
                    return true;
                }

            return false;
        });

        for (int i = 0; i < n; i++) {
            mx += khun(i);
            timer++;
        }
    };

    init();
    int start = mx;

    vec<pair<int, int>> ord;

    while (true) {
        init();
        if (mx < n - k)
            break;

        [&]() {
            int before = mx;

            for (int type = 0; type < 2; type++)
                for (int i = 0; i < n; i++) {
                    if (banned[i][type])
                        continue;

                    banned[i][type] = 1;
                    init();
                    if (mx == before - 1) {
                        ord.emplace_back(i, type);
                        return;
                    }

                    banned[i][type] = 0;
                }

            assert(false);
        }();
    }

    const ll INF = 1e18;
    vec<vec<ll>> dp(k + 1, vec<ll>(len(ord) + 1, -INF));
    dp[0][0] = 0;
    vec<vec<int>> par(k + 1, vec<int>(len(ord) + 1, -1));

    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;

        int need = max(-1, start - (n - i));
        for (int cur = need + 1; cur <= len(ord); cur++)
            for (int prev = 0; prev <= cur; prev++)
                if (dp[i - 1][prev] != -INF && setmax(dp[i][cur], dp[i - 1][prev] + max(0ll, x - 1ll * (cur - prev) * y)))
                    par[i][cur] = prev;
    }

    vec<int> answer;
    for (int i = k, cur = len(ord); i; i--) {
        answer.push_back(0);
        int prev = par[i][cur];
        for (int i = prev; i < cur; i++)
            answer.push_back((ord[i].first + 1) * (1 - 2 * ord[i].second));


        cur = prev;
    }

    reverse(all(answer));
    cout << len(answer) << '\n';
    for (auto x : answer)
        cout << x << ' ';

    cout << '\n';
}