#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
int res[Maxn];
set <int> S;

bool Solve(int c)
{
    int v = 1;
    while (v <= n && res[v] > 0) v++;
    if (v > n) return false;
    S.clear(); S.insert(v); res[v] = c;
    for (int i = v + 1; i <= n; i++) {
        int hit = 0;
        for (int j = 0; j < neigh[i].size(); j++)
            hit += S.find(neigh[i][j]) != S.end();
        if (hit < S.size())
            if (hit > 0) return false;
            else if (res[i] > 0 && res[i] != c) return false;
            else { S.insert(i); res[i] = c; }
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= 3; i++)
        if (!Solve(i)) { printf("-1\n"); return 0; }
    for (int i = 1; i <= n; i++)
        if (res[i] == 0) { printf("-1\n"); return 0; }
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}