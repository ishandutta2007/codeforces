#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m;
int typ[Maxn], A[Maxn], B[Maxn];
vector <int> neigh[Maxn];
int col[Maxn];
int in[Maxn];
vector <int> seq;
int pos[Maxn];

bool Traverse(int v, int c)
{
    if (col[v]) return col[v] == c;
    col[v] = c;
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Traverse(neigh[v][i], -c)) return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &typ[i], &A[i], &B[i]);
        neigh[A[i]].push_back(B[i]);
        neigh[B[i]].push_back(A[i]);
    }
    for (int i = 1; i <= n; i++) if (!col[i])
        if (!Traverse(i, 1)) {
            printf("NO\n");
            return 0;
        }
    for (int i = 1; i <= n; i++)
        neigh[i].clear();
    for (int i = 0; i < m; i++) {
        if (col[A[i]] == 1) swap(A[i], B[i]);
        if (typ[i] == 1) {
            neigh[A[i]].push_back(B[i]);
            in[B[i]]++;
        } else {
            neigh[B[i]].push_back(A[i]);
            in[A[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) if (in[i] == 0)
        seq.push_back(i);
    for (int z = 0; z < seq.size(); z++) {
        int v = seq[z];
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (--in[u] == 0) seq.push_back(u);
        }
    }
    if (seq.size() < n) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i < seq.size(); i++)
        pos[seq[i]] = i;
    for (int i = 1; i <= n; i++)
        printf("%c %d\n", col[i] == -1? 'L': 'R', pos[i]);
    return 0;
}