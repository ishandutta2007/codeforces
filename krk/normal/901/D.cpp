#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
ll C[Maxn];
int A[Maxn], B[Maxn];
vector <ii> neigh[Maxn];
int col[Maxn];
ll sum[Maxn];
vector <ii> tneigh[Maxn];
int spec;
ll res[Maxn];

void Construct(int v, int p, int c)
{
    col[v] = c;
    sum[col[v]] += C[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        if (!col[u.first]) {
            tneigh[v].push_back(u);
            Construct(u.first, v, 3 - c);
        } else if (col[u.first] == col[v])
            spec = u.second;
    }
}

ll Rem(int v)
{
    for (int i = 0; i < tneigh[v].size(); i++) {
        ii u = tneigh[v][i];
        ll got = Rem(u.first);
        res[u.second] = got;
        C[v] -= got;
    }
    return C[v];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &C[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &A[i], &B[i]);
        neigh[A[i]].push_back(ii(B[i], i));
        neigh[B[i]].push_back(ii(A[i], i));
    }
    Construct(1, 0, 1);
    if (!spec && sum[1] != sum[2]) {
        printf("NO\n");
        return 0;
    }
    if (spec) {
        int ind = col[A[spec]];
        res[spec] = (sum[ind] - sum[3 - ind]) / 2;
        C[A[spec]] -= res[spec];
        C[B[spec]] -= res[spec];
    }
    assert(Rem(1) == 0);
    printf("YES\n");
    for (int i = 1; i <= m; i++)
        printf("%I64d\n", res[i]);
    return 0;
}