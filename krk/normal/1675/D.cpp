#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
int root;
vector <vector <int> > res;

void Solve(int v, vector <int> &seq)
{
    seq.push_back(v);
    if (neigh[v].empty()) res.push_back(seq);
    else {
        Solve(neigh[v][0], seq);
        for (int i = 1; i < neigh[v].size(); i++) {
            vector <int> tmp;
            Solve(neigh[v][i], tmp);
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 1; i <= n; i++) {
            int p; scanf("%d", &p);
            if (p != i) neigh[p].push_back(i);
            else root = i;
        }
        res.clear();
        vector <int> tmp;
        Solve(root, tmp);
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++) {
            printf("%d\n", int(res[i].size()));
            for (int j = 0; j < res[i].size(); j++)
                printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
        }
    }
    return 0;
}