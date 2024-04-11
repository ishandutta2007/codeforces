#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 105;

int n, m;
vector <int> neigh[Maxn];
bool taken[Maxn];
int res;

int getSize(int v, bool &loop)
{
    if (taken[v]) return 0;
    taken[v] = true;
    if (neigh[v].size() < 2) loop = false;
    int res = 1;
    for (int i = 0; i < neigh[v].size(); i++) res += getSize(neigh[v][i], loop);
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b); neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        bool loop = true;
        int group = getSize(i, loop);
        if (loop && group % 2) res++;
    }
    res += (n - res) % 2;
    printf("%d\n", res);
    return 0;
}