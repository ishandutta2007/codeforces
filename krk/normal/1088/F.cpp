#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const ll Inf = 1000000000000000000ll;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
int seq[Maxn], slen;
int root;
ll res;

void Traverse(int v, int p)
{
    if (v != root) {
        ll add = Inf;
        int i = 0;
        for (i = 0; 1 << i <= slen; i++)
            add = min(add, ll(1 + i) * seq[slen - (1 << i)]);
        add = min(add, ll(1 + i) * seq[0]);
        res += add;
    }
    seq[slen++] = a[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
    }
    slen--;
}

int main()
{
    scanf("%d", &n);
    root = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        res += a[i];
        if (a[i] < a[root]) root = i;
    }
    res -= a[root];
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(root, 0);
    printf("%I64d\n", res);
    return 0;
}