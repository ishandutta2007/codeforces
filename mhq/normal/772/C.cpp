#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 100;
int sum(int a, int b, int mod) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b, int mod) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b, int mod) {
    if (b == 0) return 1 % mod;
    if (b & 1) return mult(a, pw(a, b - 1, mod), mod);
    int res = pw(a, b / 2, mod);
    return mult(res, res, mod);
}
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
int n, m;
bool bad[maxN];
int phi[maxN];
vector < int > divs[maxN];
vector < int > byGcd[maxN];
int dp[maxN];
int prv[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    if (m == 1) {
        cout << 1 << "\n" << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bad[x] = true;
    }
    for (int i = 1; i < maxN; i++) {
        for (int j = i; j < maxN; j += i) {
            divs[j].push_back(i);
        }
    }
    for (int i = 1; i < maxN; i++) {
        phi[i] = i;
        for (int v : divs[i]) {
            if (v < i) phi[i] -= phi[v];
        }
    }
    for (int i = 0; i < m; i++) {
        int d = gcd(i, m);
        if (!bad[i]) byGcd[d].push_back(i);
    }
    for (int i = 1; i <= m; i++) dp[i] = -(int)1e9;
    for (int i = 1; i <= m; i++) {
        if (m % i != 0) continue;
        if (byGcd[i].empty()) {
            dp[i] = 0;
            continue;
        }
        dp[i] = byGcd[i].size();
        for (int v : divs[i]) {
            if (v == i) continue;
            dp[i] = max(dp[i], (int)byGcd[i].size() + dp[v]);
            if ((dp[i] == (int)byGcd[i].size() + dp[v]) && (dp[v] != 0)) {
                prv[i] = v;
            }
        }
    }
    vector < int > all;
    pair < int, int > best = make_pair(-1, -1);
    for (int i = 1; i <= m; i++) {
        if (m % i != 0) continue;
        best = max(best, make_pair(dp[i], i));
    }
    int ind = best.second;
    while (ind != 0) {
        all.push_back(ind);
        ind = prv[ind];
    }
    reverse(all.begin(), all.end());
    vector < int > vals;
    for (int v : all) {
        for (int t : byGcd[v]) vals.push_back(t);
    }
    vector < int > ans;
    ans.push_back(vals[0]);
    for (int i = 0; i + 1 < vals.size(); i++) {
        int from = vals[i];
        int to = vals[i + 1];
        int d1 = gcd(from, m);
        int d2 = gcd(to, m);
        assert(d2 % d1 == 0);
        int rev = pw(from / d1, phi[m / d1] - 1, m / d1);
        ans.push_back(mult(to / d1, rev, m / d1));
    }
    cout << ans.size() << '\n';
    for (int v : ans) cout << v << " ";
};