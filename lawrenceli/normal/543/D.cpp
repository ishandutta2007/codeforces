#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200100;
const int MOD = 1e9 + 7;

int n, dp[MAXN], dp2[MAXN], cnt[MAXN], par[MAXN];
vector<int> adj[MAXN];

void dfs(int cur, int p=-1) {
    par[cur] = p;
    dp[cur] = 1;
    for (int i : adj[cur]) {
        if (i == p) continue;
        dfs(i, cur);
        dp[cur] = ll(dp[cur])*(dp[i]+1)%MOD;
        if ((dp[i]+1)%MOD == 0) cnt[cur]++;
    }
}

int exp(int b, int e) {
    if (!e) return 1;
    if (e&1) return ll(exp(b, e-1))*b%MOD;
    int res = exp(b, e>>1);
    return ll(res)*res%MOD;
}

void dfs2(int cur, int p=-1) {
    if (p == -1) dp2[cur] = 1;
    else {
        dp2[cur] = dp2[p];
        if ((dp[cur]+1)%MOD == 0) {
            if (cnt[p] > 1) dp2[cur] = 0;
            else {
                for (int j : adj[p]) if (j != par[p] && j != cur)
                    dp2[cur] = ll(dp2[cur]) * (dp[j]+1)%MOD;
            }
        } else dp2[cur] = ll(dp2[cur])*dp[p]%MOD*exp((dp[cur]+1)%MOD, MOD-2)%MOD;
        dp2[cur] = (dp2[cur]+1)%MOD;
    }

    for (int i : adj[cur])
        if (i != p)
            dfs2(i, cur);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    cin >> n;
    for (int i=1; i<n; i++) {
        int p; cin >> p; p--;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    dfs(0);
    dfs2(0);

    for (int i=0; i<n; i++)
        cout << ll(dp[i])*dp2[i]%MOD << ' ';
}