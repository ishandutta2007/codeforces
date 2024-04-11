#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 100100;
const ll INF = 1e18;

ll n[3];
vector<int> adj[3][MAXN];
ll sub[3][MAXN], sdist[3][MAXN], dist[3][MAXN];
ll sumd[3], maxd[3];
ll far[3][MAXN];

void dfs1(int c, int cur, int p) {
    sub[c][cur] = 1;
    for (int i=0; i<adj[c][cur].size(); i++) {
        int nxt = adj[c][cur][i];
        if (nxt == p) continue;
        dfs1(c, nxt, cur);
        sdist[c][cur] += sdist[c][nxt] + sub[c][nxt];
        sub[c][cur] += sub[c][nxt];
    }
}

void dfs2(int c, int j1, int j2, int cur, int p, ll val) {
    dist[c][cur] = sdist[c][cur] + val;
    far[c][cur] = dist[c][cur]*n[j2];
    for (int i=0; i<adj[c][cur].size(); i++) {
        int nxt = adj[c][cur][i];
        if (nxt == p) continue;
        dfs2(c, j1, j2, nxt, cur, val + n[c] + sdist[c][cur] - sdist[c][nxt] - 2*sub[c][nxt]);
        far[c][cur] = max(far[c][cur], far[c][nxt]+n[j1]*n[j2]);
    }
}

void dfs3(int c, int j1, int j2, int cur, int p, ll val) {
    far[c][cur] = max(far[c][cur], val);
    multiset<ll> st;
    for (int i=0; i<adj[c][cur].size(); i++) {
        int nxt = adj[c][cur][i];
        if (nxt == p) continue;
        st.insert(far[c][nxt]);
        if (st.size() > 2) st.erase(st.begin());
    }
    for (int i=0; i<adj[c][cur].size(); i++) {
        int nxt = adj[c][cur][i];
        if (nxt == p) continue;
        ll pass = *st.rbegin();
        if (pass == far[c][nxt]) {
            if (st.size() == 1) pass = -INF;
            else pass = *st.begin();
        }
        pass += 2*n[j1]*n[j2];
        dfs3(c, j1, j2, nxt, cur, max(val+n[j1]*n[j2], pass));
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    for (int i=0; i<3; i++) cin >> n[i];
    for (int i=0; i<3; i++)
        for (int j=0; j<n[i]-1; j++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[i][a].push_back(b);
            adj[i][b].push_back(a);
        }

    for (int i=0; i<3; i++) {
        int j1 = 0, j2 = 1;
        if (j1 == i) j1 = 2;
        if (j2 == i) j2 = 2;
        dfs1(i, 0, 0);
        dfs2(i, j1, j2, 0, 0, 0);
        dfs3(i, j1, j2, 0, 0, dist[i][0]*n[j2]);
        for (int j=0; j<n[i]; j++) {
            maxd[i] = max(maxd[i], dist[i][j]);
            sumd[i] += dist[i][j];
        }
        sumd[i] /= 2;
    }

    ll ans = 0;

    for (int i=0; i<3; i++) //let i be the center
        for (int n1=0; n1<n[i]; n1++) {
            ll cur = far[i][n1] + sumd[0] + sumd[1] + sumd[2];
            int j1 = 0, j2 = 1;
            if (j1 == i) j1 = 2;
            if (j2 == i) j2 = 2;
            cur += dist[i][n1] * n[j1] + maxd[j1] * n[i] + n[i] * n[j1];
            cur += maxd[j2] * n[i] + n[i] * n[j2] + maxd[j1] * n[j2] + maxd[j2] * n[j1] + 2 * n[j1] * n[j2];
            ans = max(ans, cur);
        }

    cout << ans << '\n';
    return 0;
}