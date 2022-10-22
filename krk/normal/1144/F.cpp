#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n, m;
int A[Maxn], B[Maxn];
vector <int> neigh[Maxn];
int col[Maxn];

bool Traverse(int v, int c)
{
    if (col[v] != 0) return col[v] == c;
    col[v] = c;
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Traverse(neigh[v][i], -c)) return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
        A[i] = a; B[i] = b;
    }
    if (!Traverse(1, 1)) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < m; i++)
            if (col[A[i]] == 1) printf("1");
            else printf("0");
        printf("\n");
    }
    return 0;
}