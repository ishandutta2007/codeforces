#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
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
const int maxN = (int)1e5 + 100;
int before[maxN];
int cur[maxN];
int a[maxN];
const int block = 505;
const int T = (maxN / block) + 2;
int n, k;
int dp[maxN];
int total[T][maxN * 2];
int add[T];
int bal[maxN];
void upd(int l, int val) {
    if (l < 0) return ;
    int bl = l / block;
    for (int i = bl * block; i <= l; i++) {
        if (val == 1) {
            total[bl][maxN + bal[i]] = sub(total[bl][maxN + bal[i]], dp[i]);
            bal[i]++;
        }
        else {
            bal[i]--;
            total[bl][maxN + bal[i]] = sum(total[bl][maxN + bal[i]], dp[i]);
        }
    }
    for (int i = 0; i < bl; i++) {
        add[i] += val;
    }
}
void upd(int l, int r, int val) {
    upd(r, val);
    upd(l - 1, -val);
}
int get(int r) {
    int bl = r / block;
    int ans = 0;
    for (int i = bl * block; i <= r; i++) {
        if (bal[i] + add[bl] <= k) ans = sum(ans, dp[i]);
    }
    for (int i = 0; i < bl; i++) {
        ans = sum(ans, total[i][maxN + k - add[i]]);
    }
    return ans;
}
void build(int bl) {
    int l = bl * block;
    int r = min(n, l + block - 1);
    for (int i = 0; i < 2 * maxN; i++) total[bl][i] = 0;
    for (int i = l; i <= r; i++) {
        total[bl][maxN + bal[i]] = sum(total[bl][maxN + bal[i]], dp[i]);
    }
    for (int i = 1; i < 2 * maxN; i++) {
        total[bl][i] = sum(total[bl][i], total[bl][i - 1]);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    //n = 506;
    //k = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //a[i] = i;
        before[i] = cur[a[i]];
        cur[a[i]] = i;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int prv1 = before[i];
        int prv2 = before[prv1];
        upd(prv1, i - 1, 1);
        if (prv1 != 0) upd(prv2, prv1 - 1, -1);
        dp[i] = get(i - 1);
        if ((i + 1) % block == 0) build(i / block);
    }
    cout << dp[n];
}