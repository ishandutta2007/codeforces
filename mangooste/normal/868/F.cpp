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

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    vec<ll> dp(n + 1, INF);
    dp[0] = 0;
    while (k--) {
        vec<ll> ndp(n + 1, INF);
        vec<int> cnt(n);
        ll cur_ans = 0;
        auto insert = [&](int x) {
            cur_ans += cnt[x]++;
        };
        auto erase = [&](int x) {
            cur_ans -= --cnt[x];
        };
        for (int i = 0; i < n; i++) {
            insert(a[i]);
        }
        y_combinator([&](auto solve, int l, int r, int ql, int qr) {
            if (r <= l) return;
            int mid = (l + r) / 2;
            for (int i = r - 1; i > mid; i--) {
                erase(a[i]);
            }
            ll best = INF;
            int where_best = -1;
            for (int i = ql; i < qr && i <= mid; i++) {
                ll cur = dp[i] + cur_ans;
                if (where_best == -1 || best > cur) {
                    best = cur;
                    where_best = i;
                }
                erase(a[i]);
            }
            assert(where_best != -1);
            ndp[mid + 1] = best;
            for (int i = min(mid, qr - 1); i >= ql; i--) {
                insert(a[i]);
            }
            erase(a[mid]);
            solve(l, mid, ql, where_best + 1);
            insert(a[mid]);
            for (int i = ql; i < where_best; i++) {
                erase(a[i]);
            }
            for (int i = mid + 1; i < r; i++) {
                insert(a[i]);
            }
            solve(mid + 1, r, where_best, qr);
            for (int i = where_best - 1; i >= ql; i--) {
                insert(a[i]);
            }
        })(0, n, 0, n);
        dp = ndp;
    }
    cout << dp.back() << '\n';
}