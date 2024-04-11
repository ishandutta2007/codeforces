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
    for (auto &x : a)
        cin >> x;

    a.insert(a.begin(), 0);

    vec<ll> dp(n + 1, INF);
    dp[0] = 0;
    vec<ll> ndp(n + 1);

    vec<deque<int>> freq(n + 1);
    ll value = 0;

    auto insert_front = [&](int x, int pos) {
        if (len(freq[x]))
            value += freq[x].front() - pos;

        freq[x].push_front(pos);
    };

    auto insert_back = [&](int x, int pos) {
        if (len(freq[x]))
            value += pos - freq[x].back();

        freq[x].push_back(pos);
    };

    auto erase_front = [&](int x) {
        if (len(freq[x]) > 1)
            value -= freq[x][1] - freq[x][0];

        freq[x].pop_front();
    };

    auto erase_back = [&](int x) {
        if (len(freq[x]) > 1)
            value -= freq[x].end()[-1] - freq[x].end()[-2];

        freq[x].pop_back();
    };

    for (int i = 0; i <= n; i++)
        insert_back(a[i], i);

    for (int i = 1; i <= k; i++) {
        fill(all(ndp), INF);

        y_combinator([&](auto recursive, int l, int r, int vl, int vr) {
            if (r <= l)
                return;

            int m = (l + r) / 2;
            for (int i = r - 1; i > m; i--)
                erase_back(a[i]);

            ll best = INF;
            int where = -1;

            for (int i = vl; i < vr && i < m; i++) {
                erase_front(a[i]);

                ll cur_value = value + dp[i];
                if (best > cur_value || where == -1) {
                    best = cur_value;
                    where = i;
                }
            }

            ndp[m] = best;

            for (int i = min(vr, m) - 1; i >= vl; i--)
                insert_front(a[i], i);

            erase_back(a[m]);
            recursive(l, m, vl, where + 1);

            for (int i = m; i < r; i++)
                insert_back(a[i], i);

            for (int i = vl; i < where; i++)
                erase_front(a[i]);

            recursive(m + 1, r, where, vr);

            for (int i = where - 1; i >= vl; i--)
                insert_front(a[i], i);
        })(i, n + 1, 0, n + 1);

        swap(dp, ndp);
    }

    cout << dp.back() << '\n';
}