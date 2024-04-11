#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;

int n;
int P[Maxn];
int A[Maxn];
ll v00[Maxm], v01[Maxm], v11[Maxm];

void Union(int v)
{
    v00[v] = v00[2 * v] + v00[2 * v + 1];
    v11[v] = v11[2 * v] + v11[2 * v + 1];
    v01[v] = max(max(v01[2 * v] + v11[2 * v + 1],
                     v00[2 * v] + v01[2 * v + 1]),
                 v00[2 * v] + v11[2 * v + 1]);
}

void Create(int v, int l, int r)
{
    if (l == r) { v00[v] = v01[v] = 0; v11[v] = A[l]; }
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) { v01[v] = v11[v] = 0; v00[v] = A[l]; }
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        Union(v);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &P[i]);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        A[P[i]] = x;
        sum += x;
    }
    Create(1, 1, n);
    ll res = sum;
    for (int i = 1; i < n; i++) {
        Update(1, 1, n, P[i]);
        ll mx = max(max(v00[1], v01[1]), v11[1]);
        res = min(res, sum - mx);
    }
    printf("%I64d\n", res);
    return 0;
}