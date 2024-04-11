#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<int> deg(n);
    ll ans = 1ll * n * (n - 1) * (n - 2) / 6 - 1ll * (n - 2) * m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        ans += deg[v] + deg[u];
        deg[v]++;
        deg[u]++;
    }
    cout << ans << '\n';
}