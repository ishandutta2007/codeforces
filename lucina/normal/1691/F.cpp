#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
inline int fix_mod(int x) {
    return x - ((x >= MOD) - (x < 0)) * MOD;
}
inline void plusle(int &a, int b){a = fix_mod(a + b);}
inline void minun(int &a, int b){a = fix_mod(a - b);}
inline int add(int a, int b){return fix_mod(a + b);}
inline int sub(int a, int b){return fix_mod(a - b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
const int MX = 4e5 + 10;
int fac[MX], inv_fac[MX];
void prefact() {
    fac[0] = 1;
    for (int i = 1 ; i < MX ; ++ i) {
        fac[i] = mul(fac[i - 1], i);
    }
    inv_fac[MX - 1] = power(fac[MX - 1], MOD - 2);
    for (int i = MX - 2 ; i >= 0 ; -- i) {
        inv_fac[i] = mul(inv_fac[i + 1], i + 1);
    }
}
int ncr(int N, int R) {
    if (R > N) return 0;
    return mul(fac[N], mul(inv_fac[N - R], inv_fac[R]));
}
const int nax = 2e5 + 10;

int n, k;
int ans;
int sz[nax];
int dp[nax];
int kv[nax];
int f[nax];
int sum;
vector <int> g[nax];
int s_ans;

void dfs(int v, int par) {
    sz[v] = 1;
    dp[v] = 0;    

    for (int to : g[v]) {
        if (to == par) continue;
        dfs(to, v);
        sz[v] += sz[to];
        plusle(dp[v], dp[to]);
    }
    reverse(g[v].begin(), g[v].end());
    f[v] = sub(ncr(sz[v], k), dp[v]);
    dp[v] = add(dp[v], f[v]);
    sum = add(sum, f[v]);
    plusle(s_ans, mul(sz[v], f[v]));
}

void reroot(int v, int par) {
    for (int to : g[v]) {
        if (to == par) continue;
        int memo_to = sz[to];
        int memo_sum = sum;
        int memo_f_v = f[v];
        int memo_f_to = f[to];
        int memo_s_ans = s_ans;

        minun(s_ans, mul(sz[v], f[v]));
        minun(s_ans, mul(sz[to], f[to]));

        sz[v] = n - sz[to];
        f[v] = sub(ncr(sz[v], k), sub(sum, add(f[v], dp[to])));
        minun(sum, add(memo_f_v, f[to]));
        f[to] = sub(ncr(n, k), add(sum, f[v]));
        sz[to] = n;

        sum = add(sum, f[to]);
        sum = add(sum, f[v]);

        plusle(s_ans, mul(sz[v], f[v]));
        plusle(s_ans, mul(sz[to], f[to]));

        plusle(ans, s_ans);

        reroot(to, v);

        sz[to] = memo_to;
        sz[v] = n;
        f[v] = memo_f_v;
        f[to] = memo_f_to;
        sum = memo_sum;
        s_ans = memo_s_ans;
    }
}

int main() {
    prefact();
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    ans = s_ans;
    reroot(1, 0);
    cout << ans << '\n';

}