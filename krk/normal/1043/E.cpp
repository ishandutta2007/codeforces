#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;

int n, m;
int X[Maxn], Y[Maxn];
ll ysum;
vector <int> neigh[Maxn];
int C[Maxn];
ll sum[Maxn];

int Best(int a, int b)
{
    return min(X[a] + Y[b], X[b] + Y[a]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        ysum += Y[i];
        C[i] = X[i] - Y[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    sort(C + 1, C + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + C[i];
    for (int i = 1; i <= n; i++) {
        ll res = ll(X[i]) * n + ysum;
        ll my = Y[i] - X[i];
        int ind = lower_bound(C + 1, C + n + 1, -my) - C - 1;
        res += my * ll(ind) + sum[ind];
        res -= Best(i, i);
        for (int j = 0; j < neigh[i].size(); j++)
            res -= Best(i, neigh[i][j]);
        printf("%I64d%c", res, i + 1 <= n? ' ': '\n');
    }
    return 0;
}