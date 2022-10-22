#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxd = 3;

int T;
int n, m;
int all[Maxn][Maxd];
bool tk[Maxn];
set <int> S[Maxn];
map <ii, vector <int> > M;
queue <int> Q;

void Rem(int x, int ind)
{
    S[x].erase(ind);
    if (S[x].size() == 1) Q.push(x);
}

void Add(int ind, int v)
{
    vector <int> lft;
    for (int i = 0; i < Maxd; i++)
        if (all[ind][i] != v)
            lft.push_back(all[ind][i]);
    if (lft[0] > lft[1]) swap(lft[0], lft[1]);
    M[ii(lft[0], lft[1])].push_back(v);
}

void Print(int a, int b)
{
    ii p = ii(min(a, b), max(a, b));
    auto it = M.find(p);
    if (it != M.end() && it->second.size() > 0) {
        int ind = it->second.back(); it->second.pop_back();
        Print(a, ind);
        printf(" %d", ind);
        Print(ind, b);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n); m = n - 2;
        for (int i = 1; i <= n; i++) {
            S[i].clear();
            tk[i] = false;
        }
        M.clear();
        vector <int> seq, lft;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < Maxd; j++) {
                scanf("%d", &all[i][j]);
                S[all[i][j]].insert(i);
                if (S[all[i][j]].size() == 1)
                    Q.push(all[i][j]);
            }
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            if (S[v].size() != 1) continue;
            int ind = *S[v].begin();
            tk[v] = true;
            Add(ind, v);
            seq.push_back(ind);
            for (int j = 0; j < Maxd; j++) {
                int u = all[ind][j];
                Rem(u, ind);
            }
        }
        for (int i = 1; i <= n; i++) if (!tk[i])
            lft.push_back(i);
        assert(lft.size() == 2);
        printf("%d", lft[0]);
        Print(lft[0], lft[1]);
        printf(" %d", lft[1]);
        Print(lft[1], lft[0]);
        printf("\n");
        for (int i = 0; i < seq.size(); i++)
            printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    }
    return 0;
}