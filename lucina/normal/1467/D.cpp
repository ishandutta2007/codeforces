#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void plusle(int &a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
}
void minun(int &a, int b) {
    a -= b;
    while (a < 0) a += MOD;
}
int add(int a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    return a;
}
int sub(int a, int b) {
    a -= b;
    while (a < 0) a += MOD;
    return a;
}
int mul(int a, int b) {
    return int64_t(a) * b % MOD;
}
int power(int a, int64_t b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

const int nax = 5010;
int n, k, nq;
int a[nax];

int f[nax];
int memo[nax][nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k >> nq;

    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];

    fill(memo[0] + 1, memo[0] + n + 1, 1);

    for (int i = 1 ; i <= k ; ++ i)
    for (int j = 1 ; j <= n ; ++ j)
        memo[i][j] = add(memo[i - 1][j - 1], memo[i - 1][j + 1]);


    for (int i = 1 ; i <= k ; ++ i)
    for (int j = 1 ; j <= n ; ++ j)
        plusle(f[j], mul(memo[i][j], memo[k - i ][j]));

    for (int i = 1 ; i <= n ; ++ i)
        plusle(f[i], memo[k][i]);

    int ans = 0;

    for (int i = 1 ; i <= n ; ++ i)
        plusle(ans, mul(f[i], a[i]));


    while (nq -- ) {
        int i, x;
        cin >> i >> x;
        minun(ans, mul(f[i], a[i]));
        a[i] = x;
        plusle(ans, mul(f[i], a[i]));
        cout << ans << '\n';
    }

}