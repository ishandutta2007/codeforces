#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 2e5 + 10;
int p[maxN];
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int where[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        where[p[i]] = i;
    }
    vector < int > inds;
    ll ans = 0;
    for (int i = n; i >= n - k + 1; i--) {
        ans += i;
        inds.emplace_back(where[i]);
    }
    sort(inds.begin(), inds.end());
    int coef = 1;
    for (int i = 0; i + 1 < inds.size(); i++) {
        coef = mult(coef, inds[i + 1] - inds[i]);
    }
    cout << ans << " " << coef << endl;
    return 0;
}