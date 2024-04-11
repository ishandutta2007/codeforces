#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define x first
#define y second

ll gcd(ll a, ll b) { 
    if (a < b) swap(a,b);
    return b?gcd(b, a%b):a;
}

vector<vector<int>> E;
vector<int> A;

ll dfs(int u, int p) {
    ll t = 0, ch = 0;
    for (int v:E[u]) if (v != p) {
        ++ch;
        ll r = dfs(v, u);
        if (t == 0) t = r;
        else {
            ll g = gcd(t, r);
            t /= g;
            if (r >= 1e14/t) return 1e14;
            t *= r;
        }
    }
    return t?ch*t:1;
}

ll dfs2(int u, int p, ll x) {
    if (x == 0) return 0;
    int ch = E[u].size() - (p != -1);
    if (ch == 0) return A[u] / x;
    ll ans = 1e14;
    for (int v:E[u]) if (v != p) {
        ans = min(ans, dfs2(v, u, x/ch));
    }
    return ans;
}

int main() {
    int N; cin >> N;
    E.resize(N); A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    ll ans = dfs(0, -1);
    ll ans2 = dfs2(0, -1, ans);
    ll ans3 = 0;
    for (int a:A) ans3 += a;
    cout << ans3 - ans2 * ans << endl;
}