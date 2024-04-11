#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
int L[Maxn], R[Maxn];
int res;

ll Solve(int v)
{
    ll got = 0;
    for (int i = 0; i < neigh[v].size(); i++)
        got += Solve(neigh[v][i]);
    if (got < L[v]) {
        res++;
        got = R[v];
    } else got = min(got, ll(R[v]));
    return got;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 2; i <= n; i++) {
            int p; scanf("%d", &p);
            neigh[p].push_back(i);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &L[i], &R[i]);
        res = 0;
        Solve(1);
        printf("%d\n", res);
    }
    return 0;
}