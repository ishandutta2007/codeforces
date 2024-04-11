#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 300005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
vector <int> seq;
int myp[Maxn];
ll val[Maxn];
ll best;
lli dp[Maxn][2];
ll mid;

void getSeq(int v, int p)
{
    myp[v] = p;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (p == u) continue;
        getSeq(u, v);
    }
    seq.push_back(v);
}

void getBest()
{
    for (int j = 0; j < seq.size(); j++) {
        int v = seq[j];
        val[v] = a[v];
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == myp[v]) continue;
            val[v] += max(0ll, val[u]);
        }
        best = max(best, val[v]);
    }
}

void Compute()
{
    for (int j = 0; j < seq.size(); j++) {
        int v = seq[j];
        dp[v][0] = lli(0, 0);
        dp[v][1] = lli(a[v], 0);
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == myp[v]) continue;
            dp[u][0] = max(dp[u][0], lli(dp[u][1].first - mid, dp[u][1].second + 1));
            dp[v][0] = lli(dp[v][0].first + dp[u][0].first, dp[v][0].second + dp[u][0].second);
            if (dp[u][1] > dp[u][0]) dp[u][0] = dp[u][1];
            dp[v][1] = lli(dp[v][1].first + dp[u][0].first, dp[v][1].second + dp[u][0].second);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int mx = -1000000007, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > mx) { mx = a[i]; cnt = 0; }
        if (a[i] == mx) cnt++;
    }
    if (mx <= 0) {
        cout << ll(mx) * ll(cnt) << " " << cnt << endl;
        return 0;
    }
    getSeq(1, 0);
    getBest();
    mid = best;
    Compute();
    lli got = max(dp[1][0], lli(dp[1][1].first - mid, dp[1][1].second + 1));
    cout << mid * ll(got.second) << " " << got.second << endl;
    return 0;
}