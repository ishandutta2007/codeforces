
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

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
#define why_combinator(x...) y_combinator([&](auto self, x...)
#define yoyo(x) why_combinator x )

int k;

struct node {
    vi a;
    node() {
        a.assign(2 * k, 0);
    }
    void operator^=(const node &o) {
        rep(i, 0, 2 * k) {
            a[(i + 1) % (2 * k)] ^= o.a[i];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> k;
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<node> dp(n + 1);
    yoyo((int x, int p) -> void {
        dp[x].a[0] ^= a[x];
        for(int y : g[x]) {
            if(y != p) {
                self(y, x);
                dp[x] ^= dp[y];
            }
        }
    })(1, 1);
    yoyo((int x, int p) -> void {
        for(int y : g[x]) {
            if(y != p) {
                node tmp = dp[y];
                dp[x] ^= tmp;
                dp[y] ^= dp[x];
                self(y, x, self);
                dp[x] ^= tmp;
            }
        }
    })(1, 1);
    rep(i, 1, n + 1) {
        int x = 0;
        rep(j, k, 2 * k) {
            x ^= dp[i].a[j];
        }
        cout << (x == 0 ? 0 : 1) << ' ';
    }
    cout << '\n';
}