#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, t;
const int maxN = 242;
typedef bitset < maxN > bs;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int cnt[maxN];
int ans = 0;
void dfs(int pos, int ways, bs& hs) {
    if (pos > m - pos) {
        ans = sum(ans, ways);
        return;
    }
    dfs(pos + 1, ways, hs);
    if (!hs[pos]) {
        bs ct = hs << pos;
        ct |= ct >> m;
        bs nhs = hs | ct;
        bs ct2 = hs << ((m - pos));
        ct2 |= ct2 >> m;
        nhs |= ct2;
        dfs(pos + 1, mult(ways, cnt[pos]), nhs);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> t;
    //n = 0; m = 120; t = 0;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        cnt[min(x % m,  (m - x % m) % m)]++;
    }
    bs cur;
    cur[0] = true;
    dfs(0, 1, cur);
    cout << ans;
    return 0;
}