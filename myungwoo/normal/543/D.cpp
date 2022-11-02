#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define pb push_back
typedef long long lld;

const int MOD = 1e9 + 7;
int N, P[MAXN], D[MAXN], ans[MAXN];
vector <int> con[MAXN];

void dy(int n)
{
    D[n] = 1;
    if (con[n].empty()) return;
    for (int t: con[n]){
        dy(t);
        D[n] = (lld)D[n] * (D[t] + 1) % MOD;
    }
}

int inv(int n)
{
    int ret = 1, v = MOD - 2, tmp = n;
    for (;v;v>>=1,tmp=(lld)tmp*tmp%MOD) if (v&1){
        ret = (lld)ret * tmp % MOD;
    }
    return ret;
}

void dfs(int n, int opp)
{
    ans[n] = (lld)D[n] * (opp + 1) % MOD;
    int zero_cnt = 0, without_zero = 1;

    if ((opp + 1) % MOD == 0) zero_cnt++;
    else without_zero = (lld)without_zero * (opp + 1) % MOD;

    for (int t: con[n]){
        if ((D[t]+1) % MOD == 0) zero_cnt++;
        else without_zero = (lld)without_zero * (D[t] + 1) % MOD;
    }
    for (int t: con[n]){
        int nxt = zero_cnt > 1 ? 0 : ((D[t] + 1) % MOD == 0 ? without_zero : ((lld)ans[n] * inv(D[t]+1) % MOD));
        dfs(t, nxt);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i=2;i<=N;i++){
        scanf("%d", P+i);
        con[P[i]].pb(i);
    }
    dy(1); dfs(1, 0);
    for (int i=1;i<=N;i++) printf("%d ", ans[i]); puts("");
}