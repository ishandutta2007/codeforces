#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 500005;

int q;
int n, k;
vector <ii> neigh[Maxn];
ll dp[Maxn][2];

void Traverse(int v, int p = 0)
{
    vector <ll> seq;
    ll tot = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        Traverse(u.first, v);
        tot += dp[u.first][0];
        ll gv = dp[u.first][1] + u.second - dp[u.first][0];
        if (gv > 0) seq.push_back(gv);
    }
    sort(seq.rbegin(), seq.rend());
    int tk = min(k - 1, int(seq.size()));
    for (int i = 0; i < tk; i++)
        tot += seq[i];
    dp[v][1] = tot;
    if (tk < seq.size()) tot += seq[tk];
    dp[v][0] = tot;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b, c; scanf("%d %d %d", &a, &b, &c);
            neigh[a].push_back(ii(b, c));
            neigh[b].push_back(ii(a, c));
        }
        Traverse(1);
        printf("%I64d\n", dp[1][0]);
    }
    return 0;
}