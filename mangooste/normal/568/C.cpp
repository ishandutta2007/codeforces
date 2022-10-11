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

    string type;
    cin >> type;
    array<bool, 2> occ{};
    for (auto c : type)
        occ[c == 'C'] = 1;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    vector<vector<int>> g(2 * n);
    vector<vector<int>> rev_g(2 * n);

    auto add_edge = [&](int from, int to) {
        g[from].push_back(to);
        rev_g[to].push_back(from);
        edges.emplace_back(from, to);
    };

    auto add_one = [&](int a, int va) {
        add_edge((a << 1) ^ va ^ 1, (a << 1) ^ va);
    };

    auto add = [&](int a, int va, int b, int vb) {
        add_edge((a << 1) ^ va ^ 1, (b << 1) ^ vb);
        add_edge((b << 1) ^ vb ^ 1, (a << 1) ^ va);
    };

    auto pop_back = [&]() {
        auto [v, u] = edges.back();
        edges.pop_back();
        g[v].pop_back();
        rev_g[u].pop_back();
    };

    vector<int> order;
    order.reserve(2 * n);
    vector<char> used(2 * n);
    vector<int> where(2 * n);

    auto any = [&]() {
        fill(all(used), 0);
        for (int i = 0; i < 2 * n; i++)
            if (!used[i])
                y_combinator([&](auto dfs, int v) -> void {
                    used[v] = 1;
                    for (auto u : g[v])
                        if (!used[u])
                            dfs(u);

                    order.push_back(v);
                })(i);

        reverse(all(order));
        fill(all(where), -1);
        int current = 0;

        for (auto v : order)
            if (where[v] == -1) {
                y_combinator([&](auto dfs, int v) -> void {
                    where[v] = current;
                    if (where[v ^ 1] == current)
                        return;

                    for (auto u : rev_g[v])
                        if (where[u] == -1) {
                            dfs(u);
                        }
                })(v);
                current++;
            }

        for (int i = 0; i < n; i++)
            if (where[i << 1] == where[i << 1 | 1])
                return false;

        return true;
    };

    for (int i = 0; i < m; i++) {
        int pos1, pos2;
        char val1, val2;
        cin >> pos1 >> val1 >> pos2 >> val2;
        pos1--, pos2--;
        add(pos1, (val1 == 'C') ^ 1, pos2, (val2 == 'C'));
    }

    if (!any()) {
        cout << "-1\n";
        return 0;
    }

    string s;
    cin >> s;

    for (int i : {0, 1})
        if (!occ[i]) {
            for (int j = 0; j < n; j++)
                add_one(j, i ^ 1);

            if (!any())
                cout << "-1\n";
            else
                cout << s << '\n';

            return 0;
        }

    auto find_next = [&](char c) {
        array<bool, 2> used{};
        vector<int> res;
        res.reserve(2);
        for (int i = c - 'a' + 1; i < len(type) && len(res) < 2; i++)
            if (!used[type[i] == 'C']) {
                used[type[i] == 'C'] = 1;
                res.push_back(i);
            }

        return res;
    };

    auto nxt = find_next('a' - 1);
    for (int i = 0; i < n; i++)
        add_one(i, type[s[i] - 'a'] == 'C');

    for (int pref = n; pref >= 0; pref--, pop_back()) {
        if (!any())
            continue;

        if (pref == n) {
            cout << s << '\n';
            return 0;
        }

        for (auto c : find_next(s[pref])) {
            add_one(pref, type[c] == 'C');
            if (!any()) {
                pop_back();
                continue;
            }

            auto answer = s;
            answer[pref] = 'a' + c;

            for (int i = pref + 1; i < n; i++) {
                add_one(i, type[nxt[0]] == 'C');
                answer[i] = 'a' + nxt[0];
                if (len(nxt) != 1 && !any()) {
                    pop_back();
                    add_one(i, type[nxt[1]] == 'C');
                    answer[i] = 'a' + nxt[1];
                }
            }

            cout << answer << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}