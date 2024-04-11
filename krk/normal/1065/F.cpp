#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxm = 20;

int n, k;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int id[Maxn];
int mypar[Maxn];
ii best[Maxn][Maxm];
vector <ii> V;
int carry[Maxn], has[Maxn];
int seq[Maxn], slen;

void Traverse(int v)
{
    lef[v] = cur + 1;
    if (v != 1 && neigh[v].empty()) {
        int ind = max(0, slen - k);
        id[v] = ++cur;
        mypar[v] = seq[ind];
        best[id[v]][0] = ii(slen, v);
        V.push_back(ii(slen, v));
    }
    seq[slen++] = v;
    for (int i = 0; i < neigh[v].size(); i++)
        Traverse(neigh[v][i]);
    slen--;
    rig[v] = cur;
}

int Solve(int v)
{
    int res = 0;
    for (int i = 0; i < neigh[v].size(); i++)
        res = max(res, Solve(neigh[v][i]));
    return res + has[v];
}

ii getBest(int l, int r)
{
    ii res = ii(Maxn, Maxn);
    for (int i = Maxm - 1; i >= 0; i--) if (l + (1 << i) <= r + 1) {
        res = min(res, best[l][i]);
        l += 1 << i;
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i + (1 << j) <= cur + 1; i++)
            best[i][j] = min(best[i][j - 1], best[i + (1 << j - 1)][j - 1]);
    sort(V.rbegin(), V.rend());
    for (int i = 0; i < V.size(); i++) {
        int v = V[i].second;
        carry[v]++;
        int u = getBest(lef[mypar[v]], rig[mypar[v]]).second;
        if (v == u) has[mypar[v]] += carry[v];
        else carry[u] += carry[v];
    }
    cout << Solve(1) << endl;
    return 0;
}