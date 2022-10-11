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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    const int MAX = *max_element(all(a));
    const int LG = __lg(MAX) + 1;
    const int MASK = 1 << LG;

    vector<int> cnt(MASK, 0);
    int timer = 0;
    vector<int> used(MASK);
    int answer = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 2) {
            int mask = 0;
            for (int b = LG - 1; b >= 0; b--) {
                if (a[i] >> b & 1)
                    continue;

                if (cnt[mask ^ (1 << b)] >= 2)
                    mask ^= (1 << b);
            }
            answer = max(answer, mask ^ a[i]);
        }

        timer++;
        y_combinator([&](auto dfs, int mask) -> void {
            if (cnt[mask] >= 2 || used[mask] == timer)
                return;

            cnt[mask]++;
            used[mask] = timer;
            for (int b = 0; b < LG; b++)
                if (mask >> b & 1)
                    dfs(mask ^ (1 << b));
        })(a[i]);
    }

    cout << answer << '\n';
}