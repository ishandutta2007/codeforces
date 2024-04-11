#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 3005;
const int MAXM = 40005;

int n, m, k;
vector<pii> adj[MAXN];
int x[MAXM], y[MAXM];
map<pii, int> mp;
vector<int> bad[MAXM];
int dist[MAXM], par[MAXM];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x[2*i], &y[2*i]);
        x[2*i]--, y[2*i]--;
        x[2*i+1] = y[2*i], y[2*i+1] = x[2*i];
    }
    for (int i=0; i<2*m; i++) {
        adj[x[i]].push_back(pii(y[i], i));
        mp[pii(x[i], y[i])] = i;
    }
    for (int i=0; i<n; i++)
        sort(adj[i].begin(), adj[i].end());
    for (int i=0; i<k; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--, b--, c--;
        if (mp.count(pii(a, b)))
            bad[mp[pii(a, b)]].push_back(c);
    }
    for (int i=0; i<2*m; i++)
        sort(bad[i].begin(), bad[i].end());

    memset(dist, -1, sizeof(dist));
    queue<pii> que;
    for (int i=0; i<adj[0].size(); i++)
        que.push(pii(adj[0][i].se, -1));

    for (int t=1; !que.empty(); t++) {
        int sz = que.size();
        for (int i=0; i<sz; i++) {
            int a = que.front().fi, b = que.front().se; que.pop();
            if (dist[a] != -1) continue;
            dist[a] = t;
            par[a] = b;
            if (y[a] == n-1) {
                printf("%d\n", t);
                vector<int> ans;
                int cur = a;
                ans.push_back(n-1);
                while (cur != -1) {
                    ans.push_back(x[cur]);
                    cur = par[cur];
                }
                for (int i=ans.size()-1; i>=0; i--)
                    printf("%d ", ans[i]+1);
                return 0;
            }
            int p = 0;
            for (int j=0; j<adj[y[a]].size(); j++) {
                int c = adj[y[a]][j].fi, d = adj[y[a]][j].se;
                while (p<bad[a].size() && bad[a][p] < c) p++;
                if (p<bad[a].size() && bad[a][p] == c) continue;
                if (dist[d] == -1)
                    que.push(pii(d, a));
            }
        }
    }
    printf("-1\n");
    return 0;
}