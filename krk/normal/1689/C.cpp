#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n;
vector <int> neigh[Maxn];
int cnt[Maxn], sav[Maxn];

void Solve(int v, int p = 0)
{
    if (p)
        neigh[v].erase(find(neigh[v].begin(), neigh[v].end(), p));
    if (neigh[v].empty()) { cnt[v] = 1; sav[v] = 0; return; }
    if (neigh[v].size() == 1) {
        int a = neigh[v][0];
        Solve(a, v);
        cnt[v] = cnt[a] + 1; sav[v] = cnt[a] - 1; return;
    }
    int a = neigh[v][0], b = neigh[v][1];
    Solve(a, v); Solve(b, v);
    cnt[v] = cnt[a] + cnt[b] + 1;
    sav[v] = max(cnt[a] - 1 + sav[b], cnt[b] - 1 + sav[a]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Solve(1);
        printf("%d\n", sav[1]);
    }
    return 0;
}