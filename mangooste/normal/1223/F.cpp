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

constexpr int SZ = 3;
constexpr array<int, SZ> mods = array<int, SZ>{int(1e9) + 7, int(1e9) + 9, int(1e9) + 21};
constexpr array<int, SZ> bases = array<int, SZ>{239, 241, 251};

int add(int a, int b, int j) {
    a += b;
    if (a >= mods[j])
        return a - mods[j];

    return a;
}

int mult(int a, int b, int j) {
    return (long long) a * b % mods[j];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    ll answer = 0;

    y_combinator([&](auto solve, int l, int r) -> void {
        if (l + 1 >= r)
            return;

        int mid = (l + r) >> 1;
        solve(l, mid);
        solve(mid, r);

        vector<int> st;
        vector<array<int, SZ>> hash;

        auto init = [&]() {
            st.clear();
            hash = {{0, 0, 0}};
        };

        auto insert = [&](int x) {
            if (st.empty() || st.back() != x) {
                hash.push_back(array<int, SZ>());
                for (int j = 0; j < SZ; j++)
                    hash.back()[j] = add(mult(hash[len(hash) - 2][j], bases[j], j), x, j);

                st.push_back(x);
            } else {
                hash.pop_back();
                st.pop_back();
            }
        };

        map<array<int, SZ>, int> left;
        init();
        for (int i = mid - 1; i >= l; i--) {
            insert(a[i]);
            left[hash.back()]++;
        }

        init();
        for (int i = mid; i < r; i++) {
            insert(a[i]);
            auto it = left.find(hash.back());
            if (it != left.end())
                answer += it->second;
        }
    })(0, n);

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}