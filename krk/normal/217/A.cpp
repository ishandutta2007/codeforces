#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n;
vector <int> byx[Maxn];
bool taken[Maxn];
int comp;

bool isEdge(int a, int b)
{
    int i = 0, j = 0;
    while (i < byx[a].size() && j < byx[b].size())
        if (byx[a][i] < byx[b][j]) i++;
        else if (byx[a][i] > byx[b][j]) j++;
        else return true;
    return false;
}

void Fill(int v)
{
    taken[v] = true;
    for (int i = 0; i < Maxn; i++) if (!byx[i].empty() && !taken[i])
        if (isEdge(v, i)) Fill(i);
}

int main()
{
    scanf("%d", &n);
    while (n--) {
        int x, y; scanf("%d %d", &x, &y);
        byx[x].push_back(y);
    }
    for (int i = 0; i < Maxn; i++) sort(byx[i].begin(), byx[i].end());
    for (int i = 0; i < Maxn; i++) if (!byx[i].empty() && !taken[i]) {
        comp++;
        Fill(i);
    }
    printf("%d\n", comp - 1);
    return 0;
}