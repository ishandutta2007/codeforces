#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int P[Maxn];
ld fal[Maxn], sum[Maxn];
ld cur;

ld Read()
{
    double x; scanf("%lf", &x);
    return x;
}

void Traverse(int v)
{
    if (v == 0) cur += 1.0l - fal[v];
    else {
        cur += fal[P[v]] * (1.0l - fal[v]);
        sum[P[v]] += 1.0l - fal[v];
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v]) continue;
        P[u] = v;
        Traverse(u);
    }
}

void Update(int v, ld mult)
{
    if (v == 0) cur += mult * (1.0l - fal[v]);
    else {
        cur += mult * fal[P[v]] * (1.0l - fal[v]);
        sum[P[v]] += mult * (1.0l - fal[v]);
    }
    cur += mult * fal[v] * sum[v];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        fal[i] = Read();
    for (int i = 0; i + 1 < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    P[0] = -1; Traverse(0);
    int q; scanf("%d", &q);
    while (q--) {
        int v; scanf("%d", &v);
        ld val = Read();
        Update(v, -1);
        fal[v] = val;
        Update(v, 1);
        printf("%.5lf\n", double(cur));
    }
    return 0;
}