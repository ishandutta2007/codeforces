#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
vector <ii> res;
int mx = 0;

void Write(int a, int b)
{
    res.push_back(ii(a, b));
}

void Traverse(int v, int p, int cur)
{
    Write(v, cur);
    int i = 0;
    while (neigh[v][i] != p) i++;
    neigh[v].erase(neigh[v].begin() + i);
    for (int i = cur + 1; i <= mx && !neigh[v].empty(); i++) {
        int u = neigh[v].back(); neigh[v].pop_back();
        Traverse(u, v, i);
        Write(v, i);
    }
    int nxt = cur - 1 - neigh[v].size();
    Write(v, nxt);
    for (int i = nxt + 1; !neigh[v].empty(); i++) {
        int u = neigh[v].back(); neigh[v].pop_back();
        Traverse(u, v, i);
        Write(v, i);
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
    for (int i = 1; i <= n; i++)
        mx = max(mx, int(neigh[i].size()));
    Write(1, 0);
    for (int i = 0; i < neigh[1].size(); i++) {
        int u = neigh[1][i];
        Traverse(u, 1, i + 1);
        Write(1, i + 1);
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}