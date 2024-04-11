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

const vector<int> dx{1, 0, -1, 0};
const vector<int> dy{0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a)
        cin >> s;

    vector<vector<int>> g(n * m);
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++) {
            if (a[i][j] != 'X')
                continue;

            vector<int> adj;
            adj.reserve(4);
            for (int d = 0; d < 4; d++) {
                int ii = i + dx[d];
                int jj = j + dy[d];
                if (a[ii][jj] == '.')
                    adj.push_back(ii * m + jj);
            }

            if (len(adj) % 2 != 0) {
                cout << "NO\n";
                return 0;
            }

            for (int k = 0; k < len(adj); k += 2) {
                g[adj[k]].push_back(adj[k + 1]);
                g[adj[k + 1]].push_back(adj[k]);
            }
        }

    vector<vector<int>> answer(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (answer[i][j] == -1 && a[i][j] == '.') {
                answer[i][j] = 1;

                y_combinator([&](auto dfs, int v) -> void {
                    int i = v / m;
                    int j = v % m;
                    for (auto u : g[v]) {
                        int ii = u / m;
                        int jj = u % m;
                        if (answer[ii][jj] == -1) {
                            answer[ii][jj] = 5 - answer[i][j];
                            dfs(ii * m + jj);
                        }
                        assert(answer[ii][jj] == 5 - answer[i][j]);
                    }
                })(i * m + j);
            }

    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++)
            if (a[i][j] == 'X') {
                answer[i][j] = 0;
                for (int d = 0; d < 4; d++) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];
                    if (a[ii][jj] == '.')
                        answer[i][j] += answer[ii][jj];
                }
                assert(answer[i][j] % 5 == 0);
            }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << answer[i][j] << " \n"[j == m - 1];
}