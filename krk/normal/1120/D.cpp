#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 4000000000000000000ll;

int n;
int c[Maxn];
vector <int> neigh[Maxn];
ll dp[Maxn][2];
int mycnt[Maxn];
ll myzer[Maxn], mybest[Maxn];
bool tk[Maxn][2];
bool mark[Maxn];

void Traverse1(int v, int p = 0)
{
    ll zer = 0;
    ll best = -Inf;
    int cnt = 0;
    if (neigh[v].size() - (p != 0) == 0) {
        dp[v][0] = c[v]; dp[v][1] = 0;
        return;
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        zer += dp[u][0];
        if (dp[u][0] - dp[u][1] > best) { best = dp[u][0] - dp[u][1]; cnt = 0; }
        if (dp[u][0] - dp[u][1] == best) cnt++;
    }
    mycnt[v] = cnt;
    myzer[v] = zer;
    mybest[v] = best;
    dp[v][1] = zer - best;
    dp[v][0] = min(zer, ll(c[v]) + zer - best);
}

void Traverse2(int v, int p, int f)
{
    if (tk[v][f]) return;
    tk[v][f] = true;
    if (c[v] == 0) mark[v] = true;
    if (f == 0) {
        if (neigh[v].size() - (p != 0) == 0)
            mark[v] = true;
        else {
            if (myzer[v] <= ll(c[v]) + myzer[v] - mybest[v]) {
                for (int i = 0; i < neigh[v].size(); i++) {
                    int u = neigh[v][i];
                    if (u == p) continue;
                    Traverse2(u, v, 0);
                }
            }
            if (ll(c[v]) + myzer[v] - mybest[v] <= myzer[v]) {
                mark[v] = true;
                for (int i = 0; i < neigh[v].size(); i++) {
                    int u = neigh[v][i];
                    if (u == p) continue;
                    if (dp[u][0] - dp[u][1] == mybest[v]) {
                        Traverse2(u, v, 1);
                        if (mycnt[v] > 1) Traverse2(u, v, 0);
                    } else Traverse2(u, v, 0);
                }
            }
        }
    } else {
        if (neigh[v].size() - (p != 0) == 0) return;
        if (myzer[v] <= myzer[v] - mybest[v]) {
            for (int i = 0; i < neigh[v].size(); i++) {
                int u = neigh[v][i];
                if (u == p) continue;
                Traverse2(u, v, 0);
            }
        }
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            if (dp[u][0] - dp[u][1] == mybest[v]) {
                Traverse2(u, v, 1);
                if (mycnt[v] > 1) Traverse2(u, v, 0);
            } else Traverse2(u, v, 0);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse1(1);
    Traverse2(1, 0, 0);
    vector <int> seq;
    for (int i = 1; i <= n; i++) if (mark[i])
        seq.push_back(i);
    printf("%I64d %d\n", dp[1][0], int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    return 0;
}