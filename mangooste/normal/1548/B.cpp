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

template<typename T, typename merge_t = std::function<T(const T&, const T&)>>
struct sparse_table {
    std::vector<std::vector<T>> sparse;
    merge_t merge;

    sparse_table(const merge_t &merge) : merge(merge) {}
    sparse_table(const std::vector<T> &a, const merge_t &merge) : merge(merge) {
        if (a.empty())
            return;

        int n = int(a.size());
        int lg = std::__lg(n);
        sparse.reserve(lg + 1);
        sparse.push_back(a);
        for (int level = 1; level <= lg; level++) {
            sparse.push_back(std::vector<T>(n - (1 << level) + 1));
            for (int i = 0; i < int(sparse[level].size()); i++)
                sparse[level][i] = merge(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
        }
    }

    T query(int l, int r) const {
        assert(l < r);
        int level = std::__lg(r - l);
        return merge(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> deltas(n);
    for (int i = 0; i < n - 1; i++)
        deltas[i] = abs(a[i + 1] - a[i]);

    sparse_table<ll> sparse(deltas, [](ll x, ll y) { return gcd(x, y); });

    int answer = 1;
    for (int i = 1, j = 0; i < n; i++) {
        while (j < i && sparse.query(j, i) == 1)
            j++;

        answer = max(answer, i - j + 1);
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}