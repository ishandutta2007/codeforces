#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int best[Maxn][2];
int res;

void Traverse(int v, int p)
{
    int ch = int(neigh[v].size()) - (p != 0);
    vector <int> seq;
    seq.push_back(0);
    seq.push_back(0);
    vector <int> seq2;
    seq2.push_back(0);
    seq2.push_back(0);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        best[v][1] = max(best[v][1], best[u][0]);
        best[v][0] = max(best[v][0], max(best[u][0], best[u][1]));
        seq.push_back(best[u][0]);
        seq2.push_back(max(best[u][0], best[u][1]) - 1);
    }
    best[v][1]++;
    best[v][0] += ch - 1;
    sort(seq.rbegin(), seq.rend());
    res = max(res, 1 + seq[0] + seq[1]);
    sort(seq2.rbegin(), seq2.rend());
    res = max(res, int(neigh[v].size()) + seq2[0] + seq2[1]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    printf("%d\n", res);
    return 0;
}