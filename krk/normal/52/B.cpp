#include <cstdio>
#include <iostream>
using namespace std;

const int Maxn = 1001, Maxm = 1001;

char map[Maxn][Maxm];
int n, m, infor[Maxn][Maxm], infoc[Maxn][Maxm];

int main()
{
    unsigned long long ans = 0;
    int i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        scanf("%s", map[i]);
        for (j = 1; j <= m; j++)
           if (map[i][j-1] == '.') {
                         infor[i][j] = infor[i][j-1];
                         infoc[i][j] = infoc[i-1][j];
           } else {
                  infor[i][j] = infor[i][j-1] + 1;
                  infoc[i][j] = infoc[i-1][j] + 1;
           }
    }
    for (i = 1; i <= n; i++)
       for (j = 1; j <= m; j++) 
          if (map[i][j-1] == '*')
             ans += (infor[i][j-1] + infor[i][m] - infor[i][j]) * 
                    (infoc[i-1][j] + infoc[n][j] - infoc[i][j]);
    cout << ans << endl;
    return 0;
}