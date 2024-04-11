#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;

int n, d, k;
vector <ii> res;
vector <int> neigh[Maxn];
int nxt;

void Add(int a, int b)
{
    res.push_back(ii(a, b));
    neigh[a].push_back(b);
    neigh[b].push_back(a);
}

void Gen(int v, int lvl)
{
    if (lvl == 0) return;
    while (nxt <= n && neigh[v].size() < k) {
        Add(v, nxt); nxt++;
        Gen(nxt - 1, lvl - 1);
    }
}

int main()
{
    scanf("%d %d %d", &n, &d, &k);
    if (d > n - 1) { printf("NO\n"); return 0; }
    if (n >= 3 && d == 1) { printf("NO\n"); return 0; }
    if (d >= 2 && k < 2) { printf("NO\n"); return 0; }
    for (int i = 1; i <= d; i++)
        Add(i, i + 1);
    nxt = d + 2;
    for (int i = 2; i <= d; i++) {
        int tk = min(i - 1, d + 1 - i);
        Gen(i, tk);
    }
    if (nxt <= n) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < res.size(); i++)
            printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}