#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n, m;
char B[Maxn][Maxn];
int par[Maxn], siz[Maxn];
vector <int> neigh[Maxn];
int in[Maxn];
int comp;
int myval[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a; comp--;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++)
        par[i] = i, siz[i] = 1;
    comp = n + m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf(" %c", &B[i][j]);
            if (B[i][j] == '=') unionSet(i, n + j);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] == '>') {
                neigh[getPar(n + j)].push_back(getPar(i));
                in[getPar(i)]++;
            }
            else if (B[i][j] == '<') {
                neigh[getPar(i)].push_back(getPar(n + j));
                in[getPar(n + j)]++;
            }
    vector <int> seq;
    for (int i = 0; i < n + m; i++) if (getPar(i) == i && in[i] == 0) {
        seq.push_back(i);
        myval[i] = 1;
    }
    for (int i = 0; i < seq.size(); i++) {
        int v = seq[i];
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j];
            if (--in[u] == 0) { seq.push_back(u); myval[u] = myval[v] + 1; }
        }
    }
    if (seq.size() != comp) { printf("No\n"); return 0; }
    printf("Yes\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", myval[getPar(i)], i + 1 < n? ' ': '\n');
    for (int i = 0; i < m; i++)
        printf("%d%c", myval[getPar(n + i)], i + 1 < m? ' ': '\n');
    return 0;
}