#include <cstdio>
#include <map>
using namespace std;

const int Maxd = 5;
const int Maxn = 100005;

int n, m, k;
int has[Maxn][Maxd];
map <int, int> M[Maxd];
int res = -1;
int ans[Maxd];

int getCost()
{
    int res = 0;
    for (int i = 0; i < m; i++)
        if (!M[i].empty()) { res += M[i].rbegin()->first; res = min(res, k + 1); }
    return res;
}

void Record()
{
    for (int i = 0; i < m; i++)
        ans[i] = M[i].empty()? 0: M[i].rbegin()->first;
}

void Add(int v)
{
    for (int i = 0; i < m; i++)
        M[i][has[v][i]]++;
}

void Rem(int v)
{
    for (int i = 0; i < m; i++)
        if (--M[i][has[v][i]] == 0) M[i].erase(has[v][i]);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &has[i][j]);
    for (int j = 0; j < m; j++)
        has[n][j] = k + 1;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (getCost() <= k) { Add(j); j++; }
        Rem(j - 1);
        if (j - i - 1 > res) { res = j - i - 1; Record(); }
        Add(j - 1);
        Rem(i);
    }
    for (int i = 0; i < m; i++)
        printf("%d%c", ans[i], i + 1 < m? ' ': '\n');
    return 0;
}