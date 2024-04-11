#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;
const int Maxm = 500005;
const int Maxk = 21;

int n, q;
int A[Maxm], B[Maxm], C[Maxm];
int par[Maxn], siz[Maxn];
vector <ii> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int col[Maxn], L[Maxn], P[Maxn][Maxk];
int BIT[Maxn];
vector <int> seq;
bool res[Maxm];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

void addBIT(int x, int val)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i] += val;
}

int getBIT(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Traverse(int v)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == P[v][0]) continue;
        col[u.first] = (col[v] + u.second) % 2;
        L[u.first] = L[v] + 1;
        P[u.first][0] = v;
        Traverse(u.first);
    }
    rig[v] = cur;
}

int getLCA(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxk - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b])
            a = P[a][i];
    if (a == b) return a;
    for (int i = Maxk - 1; i >= 0; i--)
        if (P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        if (unionSet(A[i], B[i])) {
            res[i] = true;
            neigh[A[i]].push_back(ii(B[i], C[i]));
            neigh[B[i]].push_back(ii(A[i], C[i]));
        } else seq.push_back(i);
    }
    for (int i = 1; i <= n; i++) if (L[i] == 0) {
        L[i] = 1;
        Traverse(i);
    }
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i];
        if (C[ind] != (col[A[ind]] + col[B[ind]]) % 2) {
            int lca = getLCA(A[ind], B[ind]);
            if (getBIT(lef[A[ind]]) + getBIT(lef[B[ind]]) - 2 * getBIT(lef[lca]) == 0) {
                res[ind] = true;
                int a = A[ind], b = B[ind];
                while (a != b) {
                    if (L[a] < L[b]) swap(a, b);
                    addBIT(lef[a], 1);
                    addBIT(rig[a] + 1, -1);
                    a = P[a][0];
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
        printf("%s\n", res[i]? "YES": "NO");
    return 0;
}