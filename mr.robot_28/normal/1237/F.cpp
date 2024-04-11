#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAX = 3610;
ll dp1[MAX][MAX], dp2[MAX][MAX];
int has1[MAX], has2[MAX];
ll fac[MAX], c[MAX][MAX];
int n, m, k;

void make(int n){
    dp1[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp1[i][j] = dp1[i - 1][j];
            if (j && i >= 2 && has1[i] == 0 && has1[i - 1] == 0){
                dp1[i][j] += dp1[i - 2][j - 1];
            }
            dp1[i][j] %= MOD;
        }
    }
}

int main(){
    cin >> n >> m >> k;
    int t = max(n, m) + 1;
    vector<ll> f(t);
    for (int i = 1; i <= k; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (has1[a] || has1[c] || has2[b] || has2[d]){
            cout << 0 << endl;
            return 0;
        }
        has1[a] = has1[c] = has2[b] = has2[d] = 1;
    }
    int N = n, M = m;
    for (int i = 1; i <= n; i++){
        N -= has1[i];
    }
    for (int i = 1; i <= m; i++){
        M -= has2[i];
    }
    make(n);
    swap(dp1, dp2);
    swap(has1, has2);
    make(m);
    swap(dp1, dp2);
    swap(has1, has2);
    c[0][0] = 1;
    f[0] = 1;
    for (int i = 1; i < t; i++){
        f[i] = (f[i - 1] * i) % MOD;
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD){
                c[i][j] -= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; (i << 1) <= N; i++){
        for (int j = 0; (j << 1) <= M; j++){
            int have1 = N - 2 * i;
            int have2 = M - 2 * j;
            ll res = dp1[n][i] * dp2[m][j];
            res %= MOD;
            res *= c[have1][j];
            res %= MOD;
            res *= c[have2][i];
            res %= MOD;
            res *= f[i];
            res %= MOD;
            res *= f[j];
            res %= MOD;
            ans += res;
        }
    }
    ans %= MOD;
    cout << ans << endl;
}