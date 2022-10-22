#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxm = 215;
const int lim = 101;
const int nil = 105;

int n;
vector <int> ind[Maxn];
char res[Maxn];
bool dp[Maxn][Maxm];
ii par[Maxn][Maxm];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        ind[a].push_back(i);
    }
    dp[0][nil] = true;
    for (int i = 0; i < lim; i++)
        for (int d = 0; d < Maxm; d++) if (dp[i][d])
            for (int f = 0; f <= ind[i].size(); f++) {
                int nd = d + int(f == 1) - int(f + 1 == ind[i].size());
                dp[i + 1][nd] = true;
                par[i + 1][nd] = ii(f, int(ind[i].size()) - f);
            }
    if (!dp[lim][nil]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int r = lim, c = nil;
    while (r > 0) {
        ii tk = par[r][c];
        r--;
        for (int i = 0; i < tk.first; i++)
            res[ind[r][i]] = 'A';
        for (int i = tk.first; i < ind[r].size(); i++)
            res[ind[r][i]] = 'B';
        c += int(tk.second == 1) - int(tk.first == 1);
    }
    res[n] = '\0';
    printf("%s\n", res);
    return 0;
}