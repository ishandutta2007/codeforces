#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 1000000007;

int n, k;
vector <ii> neigh[Maxn];
ii best[Maxn][3];
int dp[Maxn];

void addBest(ii best[], ii val)
{
    if (val > best[0]) best[2] = best[1], best[1] = best[0], best[0] = val;
    else if (val > best[1]) best[2] = best[1], best[1] = val;
    else if (val > best[2]) best[2] = val;
}

int getBest(ii best[], int x)
{
    if (best[0].second != x) return best[0].first;
    return best[1].first;
}

void Traverse(int v, int p)
{
    fill(best[v], best[v] + 3, ii(0, v));
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        Traverse(u.first, v);
        addBest(best[v], ii(best[u.first][0].first + u.second, u.first));
    }
}

int solveTaken(int v, int p, int D)
{
    if (dp[v]) return dp[v];
    if (best[v][1].first > D) { dp[v] = Inf; return dp[v]; }
    dp[v] = best[v][0].first <= D? 1: 1 + solveTaken(best[v][0].second, v, D);
    return dp[v]; 
}

int Solve(int v, int p, int tp, int D)
{
    int res = Maxn;
    if (tp > D) return res;
    // don't take
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        res = min(res, Solve(u.first, v, max(tp, getBest(best[v], u.first)) + u.second, D));
    }
    // take
    if (best[v][2].first <= D) {
        if (best[v][1].first > D) res = min(res, 1 + solveTaken(best[v][0].second, v, D) + solveTaken(best[v][1].second, v, D));
        else if (best[v][0].first > D) res = min(res, 1 + solveTaken(best[v][0].second, v, D));
        else res = min(res, 1);
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    Traverse(1, 0);
    int lef = 0, rig = Inf;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        fill(dp, dp + n + 1, 0);
        if (Solve(1, 0, 0, mid) <= k)
            rig = mid - 1;
        else lef = mid + 1;
    }
    cout << lef << endl;
    return 0;
}