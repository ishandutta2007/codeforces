#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 605;

int n, m, mod;
vector <int> neigh[Maxn], rneigh[Maxn];
vector <int> seq;
bool tk[Maxn];
int ways[Maxn];
int M[Maxn][Maxn];
int N;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

void topSort(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < rneigh[v].size(); i++)
        topSort(rneigh[v][i]);
    seq.push_back(v);
}

void Swap(int r1, int r2, int &mult)
{
    mult = ll(mult) * (mod - 1) % mod;
    for (int j = 0; j < N; j++)
        swap(M[r1][j], M[r2][j]);
}

void Sub(int r1, int r2, int c, int &mult)
{
    int m = ll(M[r1][c]) * Inv(M[r2][c]) % mod;
    mult = ll(mult) * Inv(m) % mod;
    for (int j = c; j < N; j++)
        M[r2][j] = (ll(M[r2][j]) * m % mod - M[r1][j] + mod) % mod;
}

int getDeterminant()
{
    int res = 1;
    int mult = 1;
    for (int j = 0; j < N; j++) {
        int i = j;
        while (i < N && M[i][j] == 0) i++;
        if (i >= N) return 0;
        if (j != i) Swap(i, j, mult);
        for (i++; i < N; i++) if (M[i][j])
            Sub(j, i, j, mult);
        res = ll(res) * M[j][j] % mod;
    }
    return ll(res) * mult % mod;
}

int main()
{
    scanf("%d %d %d", &n, &m, &mod);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        rneigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!tk[i])
        topSort(i);
    for (int i = 1; i <= n; i++) if (rneigh[i].empty()) {
        fill(ways + 1, ways + n + 1, 0);
        ways[i] = 1;
        for (int j = 0; j < seq.size(); j++) {
            int v = seq[j];
            for (int z = 0; z < neigh[v].size(); z++) {
                int u = neigh[v][z];
                ways[u] = (ways[u] + ways[v]) % mod;
            }
        }
        int pnt = 0;
        for (int v = 1; v <= n; v++) if (neigh[v].empty())
            M[N][pnt++] = ways[v];
        N++;
    }
    printf("%d\n", getDeterminant());
    return 0;
}