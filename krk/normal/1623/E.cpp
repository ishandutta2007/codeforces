#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
char c[Maxn];
int L[Maxn], R[Maxn];
char str[Maxn];
bool nd[Maxn];
int pnt;

void Write(int v)
{
    if (v == 0) return;
    Write(L[v]);
    str[pnt++] = c[v];
    Write(R[v]);
}

bool Solve(int v, int lvl, bool forb)
{
    if (v == 0) return false;
    bool got = Solve(L[v], lvl + 1, forb);
    int myind = pnt++;
    if (got) {
        printf("%c%c", c[v], c[v]);
        Solve(R[v], 1, false);
        return true;
    }
    if (nd[myind] && !forb && lvl <= k) {
        k -= lvl;
        printf("%c%c", c[v], c[v]);
        Solve(R[v], 1, false);
        return true;
    }
    printf("%c", c[v]);
    Solve(R[v], lvl + 1, true);
    return false;
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", c + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &L[i], &R[i]);
    Write(1);
    nd[pnt - 1] = false;
    for (int i = pnt - 2; i >= 0; i--)
        if (str[i] > str[i + 1]) nd[i] = false;
        else if (str[i] == str[i + 1]) nd[i] = nd[i + 1];
        else nd[i] = true;
    pnt = 0;
    Solve(1, 1, false);
    printf("\n");
    return 0;
}