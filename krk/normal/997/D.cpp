#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 8005;
const int Maxm = 76;
const int mod = 998244353;

int C[Maxm][Maxm];
int n1, n2, k;
vector <int> neigh[Maxn];
int my[Maxn][Maxm];
int ways[Maxn][Maxm];
int mem[Maxn][Maxm];
int A[Maxm], B[Maxm];

void Add(int A[], int B[], int delt)
{
    for (int i = 0, j = 2; j <= k; i += 2, j += 2) {
        A[j] = (A[j] + B[i] * delt) % mod;
        if (A[j] < 0) A[j] += mod;
    }
}

void Comp(int A[], int B[])
{
    fill(A, A + k + 1, 0); A[0] = 1;
    for (int i = 0; i <= k; i += 2)
        for (int j = 2; i + j <= k; j += 2)
            A[i + j] = (A[i + j] + ll(A[i]) * B[j]) % mod;
}

void Traverse1(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        Add(my[v], ways[u], 1);
    }
    Comp(ways[v], my[v]);
}

void Traverse2(int v, int p, int C[])
{
    Comp(ways[v], my[v]);
    for (int i = 0; i <= k; i += 2)
        mem[v][i] = my[v][i];
    for (int i = 0; i <= k; i += 2)
        C[i] = (C[i] + ways[v][i]) % mod;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        for (int j = 0; j <= k; j += 2)
            my[v][j] = mem[v][j];
        Add(my[v], ways[u], -1);
        Comp(ways[v], my[v]);
        Add(my[u], ways[v], 1);
        Traverse2(u, v, C);
    }
}

int main()
{
    for (int i = 0; i < Maxm; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d %d %d", &n1, &n2, &k);
    for (int i = 0; i < n1 + n2 - 2; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (i >= n1 - 1) {
            a += n1;
            b += n1;
        }
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse1(1, 0);
    Traverse2(1, 0, A);
    Traverse1(n1 + 1, 0);
    Traverse2(n1 + 1, 0, B);
    int res = 0;
    for (int i = 0; i <= k; i++)
        res = (res + ll(A[i]) * B[k - i] % mod * C[k][i]) % mod;
    cout << res << endl;
    return 0;
}