#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 300005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
int cnt1[Maxn], cnt2[Maxn];
int res;

void Traverse1(int v, int p = 0)
{
    if (a[v] == 1) cnt1[v]++;
    else if (a[v] == 2) cnt2[v]++;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        cnt1[v] += cnt1[u]; cnt2[v] += cnt2[u];
    }
}

void Traverse2(int v, int p = 0)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse2(u, v);
        if ((cnt1[u] > 0) + (cnt2[u] > 0) < 2 &&
            (cnt1[1] - cnt1[u] > 0) + (cnt2[1] - cnt2[u] > 0) < 2)
            res++;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse1(1);
    Traverse2(1);
    printf("%d\n", res);
    return 0;
}