#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int A[Maxn], B[Maxn];
int a, b;
int col[Maxn];
int res[Maxn];
vector <ii> neigh[Maxn];

bool Traverse(int v, int c)
{
    if (col[v] != -1) return col[v] == c;
    col[v] = c;
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Traverse(neigh[v][i].first, (c ^ neigh[v][i].second)))
            return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        a--; b--;
        A[i] = a; B[i] = b;
        if (a > b) swap(a, b);
        int col = int(a % 2 == b % 2);
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        neigh[a].push_back(ii(b, col));
        neigh[b].push_back(ii(a, col));
    }
    neigh[0].push_back(ii(n, 0));
    neigh[n].push_back(ii(0, 0));
    fill(col, col + n + 1, -1);
    for (int i = 0; i <= n; i++) if (col[i] == -1)
        if (!Traverse(i, 0)) { printf("-1\n"); return 0; }
    for (int i = n; i > 0; i--)
        col[i] ^= col[i - 1];
    int st = 0;
    for (int i = 0; i < 2 * n; i++) {
        res[i] = st % 2;
        if (i % 2 == 0 && col[i / 2 + 1]) st++;
        st++;
    }
    for (int i = 0; i < n; i++)
        printf("%d %d\n", res[A[i]] + 1, res[B[i]] + 1);
    return 0;
}