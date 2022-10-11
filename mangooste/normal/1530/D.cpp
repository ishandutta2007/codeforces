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
    vector<int> a(n);
    for (auto &x : a)
        cin >> x, x--;

    int answer = 0;
    vector<int> perm(n, -1);
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++)
        if (parent[a[i]] == -1) {
            parent[a[i]] = i;
            perm[i] = a[i];
            answer++;
        }

    array<vector<int>, 2> rem;
    for (int i = 0; i < n; i++)
        if (perm[i] == -1)
            rem[parent[i] == -1].push_back(i);

    if (rem[0].empty()) {
        if (len(rem[1]) > 1) {
            for (int i = 0; i < len(rem[1]); i++)
                perm[rem[1][i]] = rem[1][(i + 1) % len(rem[1])];
        } else if (len(rem[1])) {
            perm[rem[1][0]] = a[rem[1][0]];
            perm[parent[a[rem[1][0]]]] = rem[1][0];
        }
    } else {
        auto get_parent = [&](int pos) {
            while (parent[pos] != -1)
                pos = parent[pos];

            return pos;
        };

        while (len(rem[0]) > 1) {
            perm[rem[0].back()] = get_parent(rem[0].back());
            rem[0].pop_back();
        }

        rem[1].insert(rem[1].begin(), rem[0][0]);
        rem[1].push_back(get_parent(rem[0][0]));
        for (int i = 0; i < len(rem[1]) - 1; i++)
            perm[rem[1][i]] = rem[1][i + 1];
    }

    cout << answer << '\n';
    for (auto x : perm)
        cout << x + 1 << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}