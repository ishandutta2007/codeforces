#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int t;
int n;
vector <int> neigh[Maxn];
int A[Maxn], alen;
int B[Maxn], blen;
bool my[Maxn], his[Maxn];
int lvl[Maxn];

void Read(int A[], int &alen, bool my[])
{
    scanf("%d", &alen);
    for (int i = 0; i < alen; i++) {
        scanf("%d", &A[i]);
        my[A[i]] = true;
    }
}

void Traverse(int v, int p, int lv)
{
    lvl[v] = lv;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, lv + 1);
    }
}

int askMy(int v)
{
    printf("A %d\n", v); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int askHis(int v)
{
    printf("B %d\n", v); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Print(int v)
{
    printf("C %d\n", v); fflush(stdout);
}

int Get(int v, int p)
{
    if (my[v]) return v;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        int got = Get(u, v);
        if (got != -1) return got;
    }
    return -1;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            my[i] = his[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Read(A, alen, my);
        Read(B, blen, his);
        int r = A[0];
        for (int i = 1; i < alen; i++)
            if (lvl[A[i]] < lvl[r]) r = A[i];
        int u = askMy(r);
        if (his[u]) { Print(r); continue; }
        int v = askHis(B[0]);
        if (my[v]) { Print(v); continue; }
        if (lvl[v] < lvl[r]) { Print(-1); continue; }
        int a = Get(v, 0);
        int b = askMy(a);
        if (his[b]) { Print(a); continue; }
        Print(-1);
    }
    return 0;
}