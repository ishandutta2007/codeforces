#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 100001;

vector <int> neigh[Maxn], w[Maxn];
ll res[Maxn], cyc[Maxn];

void Calc(int v, int p)
{
     for (int i = 0; i < neigh[v].size(); i++)
        if (neigh[v][i] == p) {
                        neigh[v].erase(neigh[v].begin()+i);
                        w[v].erase(w[v].begin()+i);
                        i--;
        } else Calc(neigh[v][i], v);
     cyc[v] = 0;
     for (int i = 0; i < neigh[v].size(); i++)
        cyc[v] += cyc[neigh[v][i]] + 2 * w[v][i];
     res[v] = cyc[v];
     for (int i = 0; i < neigh[v].size(); i++) {
         ll newnum = cyc[v] - w[v][i] - cyc[neigh[v][i]] + res[neigh[v][i]];
         if (newnum < res[v]) res[v] = newnum;
     }
}

int main()
{
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(b); w[a].push_back(c);
        neigh[b].push_back(a); w[b].push_back(c);
    }
    Calc(1, 0);
    printf("%I64d\n", res[1]);
    return 0;
}