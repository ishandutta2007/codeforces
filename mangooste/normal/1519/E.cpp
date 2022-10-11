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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    map<pair<ll, ll>, int> id;
    vector<vector<pair<int, int>>> g;

    auto get_id = [&](pair<ll, ll> p) {
        ll c = gcd(p.first, p.second);
        p.first /= c, p.second /= c;

        if (id.find(p) == id.end()) {
            id[p] = len(g);
            g.push_back({});
        }
        return id[p];
    };

    auto add_edge = [&](int v, int u, int who) {
        g[v].emplace_back(u, who);
        g[u].emplace_back(v, who);
    };

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add_edge(get_id({1ll * (a + b) * d, 1ll * b * c}), get_id({1ll * a * d, 1ll * b * (c + d)}), i);
    }

    int sz = len(g);
    vector<char> used(sz);
    vector<pair<int, int>> answer;
    for (int i = 0; i < sz; i++)
        if (!used[i])
            y_combinator([&](auto dfs, int v, int parent) -> bool {
                used[v] = 1;
                vector<int> tot;
                for (const auto &[u, id] : g[v])
                    if (id != parent && used[u])
                        tot.push_back(id);

                for (const auto &[u, id] : g[v])
                    if (!used[u] && dfs(u, id))
                        tot.push_back(id);

                while (len(tot) >= 2) {
                    answer.emplace_back(tot.back(), tot.end()[-2]);
                    tot.pop_back(), tot.pop_back();
                }

                if (parent != -1 && len(tot)) {
                    answer.emplace_back(tot[0], parent);
                    return false;
                }
                return true;
            })(i, -1);

    cout << len(answer) << '\n';
    for (const auto &[i, j] : answer)
        cout << i + 1 << ' ' << j + 1 << '\n';
}