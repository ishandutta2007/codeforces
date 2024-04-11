#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
int cnt[2];
int mx;

void Get(int v, int p, int lvl)
{
    cnt[lvl % 2]++;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Get(u, v, lvl + 1);
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
    Get(1, 0, 0);
    printf("%d\n", min(cnt[0], cnt[1]) - 1);
    return 0;
}