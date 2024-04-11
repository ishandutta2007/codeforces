#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1000005;
const int Maxl = 26;

struct node {
    int neigh[Maxl];
    node() { fill(neigh, neigh + Maxl, 0); }
};

vector <node> V;
int n;
int hold[Maxn];
int cur;
int k;
int res[Maxn];

void Traverse(int v, int cost, int sub)
{
    if (hold[v]) {
        cur++;
        cost = min(cost, cur - sub);
        res[hold[v]] = cost;
    }
    for (int i = 0; i < Maxl; i++)
        if (V[v].neigh[i])
            Traverse(V[v].neigh[i], cost + 1, max(sub, cur - cost - 1));
}

int main()
{
    V.push_back(node());
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p; char ch; scanf("%d %c", &p, &ch);
        V[p].neigh[ch - 'a'] = i;
        V.push_back(node());
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        int a; scanf("%d", &a);
        hold[a] = i;
    }
    Traverse(0, 0, 0);
    for (int i = 1; i <= k; i++)
        printf("%d%c", res[i], i + 1 <= k? ' ': '\n');
    return 0;
}