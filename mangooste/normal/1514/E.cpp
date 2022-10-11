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
    inline decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n;
    cin >> n;

    auto compare = [&](int v, int u) {
        cout << "1 " << v << ' ' << u << endl;
        int res;
        cin >> res;
        return res;
    };

    auto ord = y_combinator([&](auto sort, int l, int r) -> vector<int> {
        if (r - l == 1)
            return {l};

        auto m = (l + r) >> 1;
        auto ord_left = sort(l, m);
        auto ord_right = sort(m, r);

        vector<int> ord;
        ord.reserve(r - l);

        int j = 0;
        for (auto v : ord_left) {
            while (j < len(ord_right) && compare(ord_right[j], v))
                ord.push_back(ord_right[j++]);

            ord.push_back(v);
        }
        while (j < len(ord_right))
            ord.push_back(ord_right[j++]);

        return ord;
    })(0, n);

    dbg(ord);

    auto backward = [&](int v, const vector<int> &vers) {
        cout << "2 " << v << ' ' << len(vers);
        for (auto x : vers)
            cout << ' ' << x;

        cout << endl;
        int res;
        cin >> res;
        return res;
    };

    vector<vector<int>> groups;
    groups.reserve(n);
    groups.push_back({ord[0]});

    for (int i = 1; i < n; i++) {
        auto total = [&]() {
            vector<int> total;
            for (int i = 0; i < len(groups) - 1; i++)
                for (auto v : groups[i])
                    total.push_back(v);

            return total;
        };

        groups.push_back({ord[i]});
        while (len(groups) > 1 && backward(ord[i], total())) {
            for (auto x : groups.back())
                groups.end()[-2].push_back(x);

            groups.pop_back();
        }
    }

    vector<vector<int>> answer(n, vector<int>(n));
    for (int i = 0; i < len(groups); i++)
        for (auto v : groups[i])
            for (int j = i; j < len(groups); j++)
                for (auto u : groups[j])
                    answer[v][u] = 1;

    cout << "3\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << answer[i][j];

        cout << '\n';
    }
    cout << flush;

    int res;
    cin >> res;
    assert(res == 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}