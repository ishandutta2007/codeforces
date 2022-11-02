#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 100100;
const int MAXM = 500100;

int n, m, ea[MAXM], eb[MAXM], deg[MAXN];
bool used[MAXM];
vector<pii> adj[MAXN];

void add_edge(int i) {
    adj[ea[i]].push_back(pii(eb[i], i));
    adj[eb[i]].push_back(pii(ea[i], i));
    deg[ea[i]]++, deg[eb[i]]++;
}

vector<int> ans;

void dfs(int cur) {
    while (!adj[cur].empty()) {
        pii p = adj[cur].back();
        if (used[p.se]) adj[cur].pop_back();
        else {
            used[p.se] = 1;
            dfs(p.fi);
        }
    }
    ans.push_back(cur);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> ea[i] >> eb[i];
        add_edge(i);
    }

    for (int i=1, j=0; i<=n; i++)
        if (deg[i]%2) {
            if (j == 0) j = i;
            else {
                ea[m] = i, eb[m] = j;
                add_edge(m++);
                j = 0;
            }
        }

    if (m%2) ea[m] = eb[m] = 1, add_edge(m++);

    dfs(1);
    cout << m << '\n';
    for (int i=0; i+1<ans.size(); i++)
        if (i%2 == 0) cout << ans[i] << ' ' << ans[i+1] << '\n';
        else cout << ans[i+1] << ' ' << ans[i] << '\n';
}