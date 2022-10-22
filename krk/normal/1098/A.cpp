#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Inf = 1000000007;

int n;
vector <int> neigh[Maxn];
int s[Maxn];
ll res;
bool mistake;

void Traverse(int v, int par)
{
    int mn = Inf;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        mn = min(mn, s[u]);
    }
    if (s[v] != -1) {
        res += s[v] - par;
        for (int i = 0; i < neigh[v].size(); i++)
            Traverse(neigh[v][i], s[v]);
    } else {
        if (mn == Inf) mn = par;
        if (par > mn) { mistake = true; return; }
        s[v] = mn;
        res += s[v] - par;
        for (int i = 0; i < neigh[v].size(); i++)
            Traverse(neigh[v][i], s[v]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    Traverse(1, 0);
    if (mistake) printf("-1\n");
    else printf("%I64d\n", res);
    return 0;
}