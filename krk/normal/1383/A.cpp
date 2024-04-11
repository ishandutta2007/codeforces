#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 20;

int T;
int n;
char A[Maxn], B[Maxn];
vector <int> neigh[Maxl];
bool tk[Maxl];

void Fill(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        Fill(neigh[v][i]);
}

int Solve()
{
    for (int i = 0; i < Maxl; i++) {
        neigh[i].clear();
        tk[i] = false;
    }
    for (int i = 0; i < n; i++)
        if (A[i] > B[i]) return -1;
        else {
            int a = A[i] - 'a', b = B[i] - 'a';
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
    int res = 0;
    for (int i = 0; i < Maxl; i++) if (!neigh[i].empty()) {
        res++;
        if (!tk[i]) { Fill(i); res--; }
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        printf("%d\n", Solve());
    }
    return 0;
}