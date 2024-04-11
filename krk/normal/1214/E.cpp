#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 21;

int n;
int d[Maxn];
int seq[Maxn];
int L[Maxn];
int P[Maxn][Maxm];
int lw;

bool Less(const int &a, const int &b)
{
    return d[a] > d[b];
}

void Connect(int v, int p)
{
    printf("%d %d\n", v, p);
    L[v] = L[p] + 1;
    P[v][0] = p;
    for (int j = 1; j < Maxm; j++)
        P[v][j] = P[P[v][j - 1]][j - 1];
    if (lw == 0 || L[lw] < L[v]) lw = v;
}

int getInLevel(int lvl)
{
    int v = lw;
    int up = L[v] - lvl;
    assert(up >= 0);
    for (int i = Maxm - 1; i >= 0; i--) if (1 << i <= up) {
        up -= 1 << i;
        v = P[v][i];
    }
    return v;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        seq[i] = i;
    }
    sort(seq, seq + n, Less);
    lw = 2 * seq[0] + 1;
    for (int i = 1; i < n; i++)
        Connect(2 * seq[i] + 1, 2 * seq[i - 1] + 1);
    for (int i = 0; i < n; i++) {
        int v = 2 * seq[i] + 1;
        int u = getInLevel(L[v] + d[seq[i]] - 1);
        Connect(v + 1, u);
    }
    return 0;
}