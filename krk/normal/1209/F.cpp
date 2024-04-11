#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int mod = 1000000007;
const int Maxs = 1000005;
const int Maxd = 10;
const int Inf = 1000000000;

vector <int> W[Maxn];
int n, m;
vector <ii> neigh[Maxn];
int dist[Maxn];
int res[Maxs], lst[Maxs];
int nxt;
vector <int> gneigh[Maxs][Maxd];
int seq[Maxs], slen;
vector <int> rec[Maxd];

int main()
{
    for (int i = 1; i < Maxn; i++) {
        int num = i;
        while (num) {
            W[i].push_back(num % 10);
            num /= 10;
        }
        reverse(W[i].begin(), W[i].end());
    }
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(ii(b, i));
        neigh[b].push_back(ii(a, i));
    }
    fill(dist, dist + n + 1, Inf); dist[1] = 0;
    priority_queue <ii> Q; Q.push(ii(-dist[1], 1));
    nxt = n + 1;
    while (!Q.empty()) {
        int v = Q.top().second, d = -Q.top().first; Q.pop();
        if (dist[v] != d) continue;
        // before
        for (int i = 0; i < neigh[v].size(); i++) {
            ii u = neigh[v][i];
            if (dist[u.first] + int(W[u.second].size()) == dist[v]) {
                int cur = u.first;
                for (int j = 0; j < W[u.second].size(); j++) {
                    int oth = j + 1 < W[u.second].size()? nxt++: v;
                    gneigh[cur][W[u.second][j]].push_back(oth);
                    cur = oth;
                }
            }
        }
        // after
        for (int i = 0; i < neigh[v].size(); i++) {
            ii u = neigh[v][i];
            int cand = dist[v] + int(W[u.second].size());
            if (cand < dist[u.first]) {
                dist[u.first] = cand;
                Q.push(ii(-dist[u.first], u.first));
            }
        }
    }
    fill(res, res + Maxs, -1);
    res[1] = 0; seq[slen++] = 1;
    for (int i = 0, j; i < slen; i = j) {
        j = i;
        while (j < slen && res[seq[i]] == res[seq[j]] && lst[seq[i]] == lst[seq[j]]) j++;
        for (int l = 0; l < Maxd; l++)
            rec[l].clear();
        for (int l = i; l < j; l++) {
            int v = seq[l];
            for (int d = 0; d < Maxd; d++)
                for (int z = 0; z < gneigh[v][d].size(); z++)
                    rec[d].push_back(gneigh[v][d][z]);
        }
        for (int d = 0; d < Maxd; d++) {
            int nres = (ll(res[seq[i]]) * 10ll + ll(d)) % mod;
            for (int z = 0; z < rec[d].size(); z++) {
                int u = rec[d][z];
                if (res[u] == -1) {
                    res[u] = nres;
                    lst[u] = d;
                    seq[slen++] = u;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
        printf("%d\n", res[i]);
    return 0;
}