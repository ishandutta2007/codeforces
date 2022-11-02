#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 6005;

int n, r[MAXN];
vector<int> adj[MAXN];

map<int, int> mp;
int cnt = 1;

short dp1[MAXN][MAXN], dp2[MAXN][MAXN]; //dp1 - inc, dp2 - dec
pii ma1[MAXN][2], ma2[MAXN][2];
int ans;

void setmax(short& a, short b) { if (a < b) a = b; }

void dfs(int cur, int p = -1) {
    dp1[cur][r[cur]] = dp2[cur][r[cur]] = 1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
        for (int j=0; j<=n+1; j++) {
            setmax(dp1[cur][j], dp1[nxt][j]);
            setmax(dp2[cur][j], dp2[nxt][j]);
        }
        setmax(dp1[cur][r[cur]], dp1[nxt][r[cur]-1]+1);
        setmax(dp2[cur][r[cur]], dp2[nxt][r[cur]+1]+1);
    }

    for (int i=0; i<=n; i++)
        setmax(dp1[cur][i+1], dp1[cur][i]);
    for (int i=n; i>=0; i--)
        setmax(dp2[cur][i], dp2[cur][i+1]);

    //calculate ans
    for (int i=0; i<=n+1; i++)
        for (int j=0; j<2; j++)
            ma1[i][j] = pii(0, -1), ma2[i][j] = pii(0, -1);
    vector<pii> v (3);
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        for (int j=0; j<=n+1; j++) {
            v[0] = pii(dp1[nxt][j], nxt), v[1] = ma1[j][0], v[2] = ma1[j][1];
            sort(v.begin(), v.end());
            ma1[j][0] = v[2], ma1[j][1] = v[1];

            v[0] = pii(dp2[nxt][j], nxt), v[1] = ma2[j][0], v[2] = ma2[j][1];
            sort(v.begin(), v.end());
            ma2[j][0] = v[2], ma2[j][1] = v[1];
        }
    }

    for (int i=0; i<=n; i++) {
        if (ma1[i][0].second == ma2[i+1][0].second) {
            ans = max(ans, ma1[i][0].first+ma2[i+1][1].first);
            ans = max(ans, ma1[i][1].first+ma2[i+1][0].first);
        } else ans = max(ans, ma1[i][0].first+ma2[i+1][0].first);
    }

    if (ma1[r[cur]-1][0].second == ma2[r[cur]+1][0].second) {
        ans = max(ans, ma1[r[cur]-1][0].first+ma2[r[cur]+1][1].first+1);
        ans = max(ans, ma1[r[cur]-1][1].first+ma2[r[cur]+1][0].first+1);
    } else ans = max(ans, ma1[r[cur]-1][0].first+ma2[r[cur]+1][0].first+1);
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> r[i];
        mp[r[i]] = 0;
    }
    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++)
        mp[it->first] = cnt++;
    for (int i=0; i<n; i++) r[i] = mp[r[i]];

    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);

    cout << ans << '\n';
}