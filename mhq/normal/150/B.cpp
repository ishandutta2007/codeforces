#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int n, m, k;
const int maxN = 2005;
int p[maxN];
int get(int a) {
    if (a == p[a]) return a;
    p[a] = get(p[a]);
    return p[a];
}
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rand() % 2) swap(a, b);
    p[a] = b;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int len = 1; len <= n - k + 1; len++) {
        int l = len;
        int r = len + k - 1;
        for (int j = l; j <= r; j++) {
            int t = r + l - j;
            if (j >= t) continue;
            unite(j, t);
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) ans = mult(ans, m);
    }
    cout << ans;
    return 0;
}