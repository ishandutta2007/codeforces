#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;
const int Maxm = 19;

int n;
vector <int> neigh[Maxn];
int best[Maxn][2];
int mx;
int A[Maxn][Maxm], B[Maxn][Maxm];
map <int, int> M[Maxn];
vector <ii> V[Maxn];

void updateMax(int X[][Maxm], int l, int r, int val)
{
    for (int i = Maxm - 1; i >= 0; i--)
        if (l + (1 << i) <= r + 1) {
            X[l][i] = max(X[l][i], val);
            l += 1 << i;
        }
}

void precMax(int X[][Maxm])
{
    for (int j = Maxm - 1; j > 0; j--)
        for (int i = 0; i + (1 << j) <= n + 1; i++) {
            X[i][j - 1] = max(X[i][j - 1], X[i][j]);
            int ni = i + (1 << j - 1);
            X[ni][j - 1] = max(X[ni][j - 1], X[i][j]);
        }
}

void Add(map <int, int> &M, int ind)
{
    auto it = M.find(ind);
    if (it == M.end()) M.insert(make_pair(ind, 1));
    else it->second++;
}

void addBest(int best[], int val)
{
    if (val > best[0]) best[1] = best[0], best[0] = val;
    else if (val > best[1]) best[1] = val;
}

int getBest(int best[], int val)
{
    return best[0] == val? best[1]: best[0];
}

void Traverse1(int v, int p)
{
    mx = max(mx, int(neigh[v].size()) + 1);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        int got = best[u][0] + 1;
        Add(M[v], got);
        addBest(best[v], got);
    }
}

void Traverse2(int v, int p, int tp)
{
    tp++;
    if (v != 1) Add(M[v], tp);
    V[v].resize(M[v].size());
    int pnt = 0;
    for (auto it: M[v])
        V[v][pnt++] = it;
    // one
    int sum = 0;
    for (int i = int(V[v].size()) - 1; i >= 0; i--) {
        sum += V[v][i].second;
        int lim = i > 0? V[v][i - 1].first: -1;
        updateMax(B, lim + 1, V[v][i].first, sum);
        updateMax(A, lim + 1, V[v][i].first, sum);
        updateMax(A, lim + 1, lim + 1, sum + 1);
    }
    // two
    if (v != 1) {
        int ind1 = lower_bound(V[v].begin(), V[v].end(), ii(tp, 0)) - V[v].begin();
        int ind2 = lower_bound(V[p].begin(), V[p].end(), ii(best[v][0] + 1, 0)) - V[p].begin();
        V[v][ind1].second--; V[p][ind2].second--;
        sum = 0;
        int i = int(V[v].size()) - 1, j = int(V[p].size()) - 1;
        while (i >= 0 || j >= 0) {
            int from;
            if (i >= 0 && (j < 0 || V[v][i].first > V[p][j].first)) {
                from = V[v][i].first; sum += V[v][i].second; i--;
            } else if (j >= 0 && (i < 0 || V[p][j].first > V[v][i].first)) {
                from = V[p][j].first; sum += V[p][j].second; j--;
            } else {
                from = V[v][i].first; sum += V[v][i].second + V[p][j].second; i--; j--;
            }
            int lim = max((i >= 0? V[v][i].first: 0), (j >= 0? V[p][j].first: 0));
            updateMax(B, lim + 1, from, sum);
        }
        V[v][ind1].second++; V[p][ind2].second++;
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (p == u) continue;
        Traverse2(u, v, max(tp, getBest(best[v], best[u][0] + 1)));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse1(1, 0);
    Traverse2(1, 0, -1);
    precMax(A);
    precMax(B);
    printf("%d", mx);
    for (int i = 2; i <= n; i++) {
        int res = 1;
        if (i % 2 == 0) res = max(res, B[i / 2][0]);
        else res = max(res, A[(i + 1) / 2][0]);
        printf(" %d", res);
    }
    printf("\n");
    return 0;
}