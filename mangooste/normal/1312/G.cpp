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

    int n;
    cin >> n;
    n++;
    vector<vector<pair<char, int>>> g(n);
    for (int i = 1; i < n; i++) {
        int parent;
        char c;
        cin >> parent >> c;
        g[parent].emplace_back(c, i);
    }

    for (int i = 0; i < n; i++)
        sort(all(g[i]));

    int q;
    cin >> q;
    vector<int> a(q);
    vector<char> matched(n);
    for (auto &x : a) {
        cin >> x;
        matched[x] = 1;
    }

    vector<int> dist(n);
    multiset<int> st;

    y_combinator([&](auto dfs, int v, int pref) -> int {
        if (matched[v] && len(st))
            dist[v] = min(dist[v], *st.begin() + pref + 1);

        int size = matched[v];
        int value = dist[v] - pref;
        st.insert(value);
        for (const auto &[c, u] : g[v]) {
            dist[u] = dist[v] + 1;
            size += dfs(u, pref + size);
        }
        st.erase(st.find(value));
        return size;
    })(0, 0);

    for (auto x : a)
        cout << dist[x] << ' ';

    cout << '\n';
}