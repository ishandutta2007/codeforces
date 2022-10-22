#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 20;

int n, l;
ll S;
ll W[Maxn];
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
int my[Maxn];
int res;

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v][0]) continue;
        L[u] = L[v] + 1; W[u] += W[v]; P[u][0] = v;
        Traverse(u);
    }
}

int Solve(int v)
{
    vector <int> seq;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v][0] == u) continue;
        int got = Solve(u);
        if (got >= L[v]) res++;
        else seq.push_back(got);
    }
    sort(seq.begin(), seq.end());
    if (seq.empty()) return my[v];
    res += int(seq.size()) - 1;
    return seq[0];
}

int main()
{
    scanf("%d %d %I64d", &n, &l, &S);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &W[i]);
        if (W[i] > S) { printf("-1\n"); return 0; }
    }
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
        neigh[i].push_back(p);
    }
    L[1] = 1; Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    for (int i = 1; i <= n; i++)
        if (L[i] <= l && W[i] <= S) my[i] = 0;
        else {
            int v = i;
            for (int j = Maxm - 1; j >= 0; j--) if ((1 << j) <= L[v]) {
                int u = P[v][j];
                if (L[i] - L[u] <= l && W[i] - W[u] <= S)
                    v = u;
            }
            my[i] = L[v];
        }
    Solve(1); res++;
    printf("%d\n", res);
    return 0;
}