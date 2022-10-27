#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 20;
constexpr int MOD = 998244353;
void plusle (int &a, int b) {
    if ((a += b) >= MOD ) a -= MOD;
}

void minun (int &a, int b) {
    if ((a -= b) < 0) a += MOD;
}
int add (int a, int b) {
    return ((a += b) >= MOD) ? a - MOD : a;
}
int sub (int a, int b) {
    return (( a -= b) < 0) ? a + MOD : a;
}
int mul (int a, int b) {
    return 1LL * a * b % MOD;
}
int power (int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1 , a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res ;
}

const int MX = 3e5 + 10;
int fac[MX], invf[MX] ;
void prefact () {
    fac[0] = 1 ;
    for (int i = 1 ; i < MX ; i ++) {
        fac[i] = mul(fac[i - 1], i);
    }
    invf[MX - 1] = power (fac[MX - 1], MOD - 2);
    for (int i = MX - 2 ; i >= 0 ; i --) {
        invf[i] = mul(invf[i + 1], i + 1);
    }
}

int ncr (int N, int R) {
    if (N < 0 || R < 0) return 0;
    if (R > N) return 0;
    if (R == 0 || R == N) return 1;
    return mul (fac[N], mul(invf[N - R], invf[R]));
}

int sum[M * 2 + 1][N];
pair <int, int> ban[M + 2];
int l[N];
int r[N];
int many[N];
int to_id[N];
int top_id = 0;
int n, m;

int main() {
    prefact();

    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d %d", l + i, r + i);
        many[l[i]] += 1;
        many[r[i] + 1] -= 1;
    }

    for (int i = 0 ; i < m ; ++ i) {
        scanf("%d %d", &ban[i].first, &ban[i].second);
        if (!to_id[ban[i].first]) to_id[ban[i].first] = ++ top_id;
        if (!to_id[ban[i].second]) to_id[ban[i].second] = ++ top_id;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        many[i] += many[i - 1];
        for (int j = 0 ; j < 2 * M + 1 ; ++ j)
            sum[j][i] = add(sum[j][i - 1], ncr(many[i] - j, i - j));
    }

    int ans = 0;

    for (int i = 0 ; i < (1 << m) ; ++ i) {
        int cur_l = 1, cur_r = n;
        int popcnt = 0;
        int64_t cnt = 0;
        for (int j = 0 ; j < m ; ++ j) {
            if (i >> j & 1) {
                const auto &[x, y] = ban[j];
                cur_l = max(cur_l, l[x]);
                cur_r = min(cur_r, r[x]);
                cur_l = max(cur_l, l[y]);
                cur_r = min(cur_r, r[y]);
                cnt |= (1LL << to_id[x]);
                cnt |= (1LL << to_id[y]);
                popcnt += 1;
            }
        }

        cnt = __builtin_popcountll(cnt);

        if (cur_l > cur_r) continue;
        int to_add = sub(sum[cnt][cur_r], sum[cnt][cur_l - 1]);
        if (popcnt % 2) minun(ans, to_add);
        else plusle(ans, to_add);
    }
    printf("%d\n", ans);
}