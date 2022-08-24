#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n;
const int maxN = 5e5 + 10;
int a[maxN];
int inc[maxN];
int f[maxN], g[maxN];
int solve() {
    int pos = find(a + 1, a + n + 1, n) - a;
//    for (int i = 1; i <= n; i++) cout << a[i] << " ";
//    cout << endl;
//    cout << pos << endl;
    int T = 0;
    inc[0] = 0;
    inc[1] = 0;
    for (int i = 2; i <= pos; i++) {
        inc[i] = 1e9;
        if (a[i] > a[i - 1]) inc[i] = inc[i - 1];
        if (a[i] > inc[i - 1]) inc[i] = min(inc[i], a[i - 1]);
    }
    if (inc[pos] > n) return 0;
    T = inc[pos];
    inc[n] = 0;
    for (int z = n - 1; z > pos; z--) {
        inc[z] = 1e9;
        if (a[z] > a[z + 1]) inc[z] = inc[z + 1];
        if (a[z] > inc[z + 1]) inc[z] = min(inc[z], a[z + 1]);
    }
    f[pos] = T;
    g[pos] = -1e9;
    int ans = 0;
    for (int z = pos + 1; z <= n; z++) {
        //{f[z - 1], a[z - 1]}
        //{a[z - 1], g[z - 1]}
        g[z] = -1e9;
        f[z] = 1e9;
        if (a[z] < a[z - 1]) f[z] = min(f[z], f[z - 1]);
        if (a[z] > f[z - 1]) g[z] = max(g[z], a[z - 1]);
        if (a[z] > a[z - 1]) g[z] = max(g[z], g[z - 1]);
        if (a[z] < g[z - 1]) f[z] = min(f[z], a[z - 1]);
//        cout << z << " " << inc[z] << endl;
        if (inc[z] > n) continue;
        if (g[z] > inc[z]) ans++;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t.emplace_back(a[i]);
    }
    sort(t.begin(), t.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin() + 1;
//        cout << a[i] << " ";
    }
//    cout << endl;
    int ans = 0;
    ans += solve();
    reverse(a + 1, a + n + 1);
    ans += solve();
    cout << ans << '\n';
    return 0;
}