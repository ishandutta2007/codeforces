#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;

int n, q, a[MAXN], b[MAXN], l[MAXN], sub[MAXN], dep[MAXN];
ll sub2[MAXN], sum;
vector<pii> adj[MAXN];

void dfs(int cur, int p=-1) {
    dep[cur] = p == -1 ? 0 : dep[p]+1;
    sub[cur] = 1;
    sub2[cur] = 0;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i].first;
        if (nxt == p) continue;
        dfs(nxt, cur);
        sub[cur] += sub[nxt];
        sub2[cur] += sub2[nxt]+ll(sub[nxt])*adj[cur][i].second;
    }

    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i].first;
        if (nxt == p) continue;
        sum += (sub2[nxt]+ll(sub[nxt])*adj[cur][i].second)*(sub[cur]-sub[nxt]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        cin >> a[i] >> b[i] >> l[i];
        a[i]--, b[i]--;
        adj[a[i]].push_back(pii(b[i], l[i]));
        adj[b[i]].push_back(pii(a[i], l[i]));
    }

    dfs(0);
    cin >> q;
    for (int i=0; i<q; i++) {
        int r, w; cin >> r >> w;
        r--;
        if (dep[a[r]] < dep[b[r]]) swap(a[r], b[r]);
        sum -= ll(sub[a[r]])*(n-sub[a[r]])*(l[r]-w);
        l[r] = w;
        double res = double(sum)*2/(ll(n)*(n-1))*3;
        cout << fixed << setprecision(10) << res << '\n';
    }
    return 0;
}