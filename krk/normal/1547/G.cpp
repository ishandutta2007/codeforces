#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int T;
int n, m;
int A[Maxn], B[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];
int in[Maxn];
int res[Maxn];

void Traverse(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        Traverse(neigh[v][i]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            tk[i] = false;
            in[i] = 0;
            res[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &A[i], &B[i]);
            neigh[A[i]].push_back(B[i]);
        }
        Traverse(1);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < m; i++) if (tk[A[i]] && tk[B[i]]) {
            neigh[A[i]].push_back(B[i]);
            in[B[i]]++;
        }
        res[1] = 1;
        vector <int> seq;
        for (int i = 1; i <= n; i++) if (tk[i] && in[i] == 0)
            seq.push_back(i);
        for (int i = 0; i < seq.size(); i++) {
            int v = seq[i];
            for (int j = 0; j < neigh[v].size(); j++) {
                int u = neigh[v][j];
                res[u] = min(2, res[u] + res[v]);
                if (--in[u] == 0) seq.push_back(u);
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", in[i] > 0? -1: res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}