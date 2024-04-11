#include <bits/stdc++.h>
using namespace std;

const int Maxn = 32;

int T;
int n, m;
int tot;
map <int, int> best[Maxn + Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        tot = n * m;
        for (int i = 0; i < Maxn + Maxn; i++)
            best[i].clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int a; scanf("%d", &a);
                int ind = i + j;
                int oth = n - 1 + m - 1 - ind;
                if (ind == oth) tot--;
                else best[min(ind, oth)][a]++;
            }
        for (int i = 0; i < Maxn + Maxn; i++) {
            int mx = 0;
            for (auto p: best[i])
                mx = max(mx, p.second);
            tot -= mx;
        }
        printf("%d\n", tot);
    }
    return 0;
}