#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 2 * (int)1e5 + 10;
const int maxK = 2005;
const int maxLOG = 25;
pair < int, int > point[maxK];
int n, m, k, s;
int fact[maxN];
int invfact[maxN];
int inv[maxN];
int dp[maxK][maxLOG];
int path(int x, int y) {
    if (x < 0 || y < 0) return 0;
    return mult(fact[x + y], mult(invfact[x], invfact[y]));
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= k; i++) {
        cin >> point[i].first >> point[i].second;
    }
    sort(point + 1, point + k + 1);
    if (point[k].first != n || point[k].second != m) {
        k++;
        point[k].first = n;
        point[k].second = m;
    }
    else {
        s = (s + 1) / 2;
    }
    fact[0] = 1;
    invfact[0] = 1;
    inv[1] = 1;
    fact[1] = 1;
    invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(mod - (mod / i), inv[mod % i]);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    for (int i = 0; i < maxLOG; i++) {
        for (int j = 1; j <= k; j++) {
            int cnt = path(point[j].first - 1, point[j].second - 1);
            for (int t = 0; t < i; t++) cnt = sub(cnt, dp[j][t]);
            for (int t = 1; t < j; t++) {
                int coef = path(point[j].first - point[t].first, point[j].second - point[t].second);
                cnt = sub(cnt, mult(dp[t][i], coef));
            }
            dp[j][i] = cnt;
        }
    }
    int ans = 0;
    int cnt = path(n - 1, m - 1);
    for (int i = 0; i < maxLOG; i++) {
        if (s == 0) break;
        if (s == 1) {
            ans = sum(ans, mult(s, cnt));
            break;
        }
        ans = sum(ans, mult(s, dp[k][i]));
        cnt = sub(cnt, dp[k][i]);
        s = (s + 1) / 2;
    }
    cout << mult(ans, mult(invfact[n - 1 + m - 1], mult(fact[n - 1], fact[m - 1])));
}