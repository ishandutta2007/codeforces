#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1500;

int n, m, board[Maxn][Maxn];
ll best[Maxn];

int main()
{
    int i, j;
    ll ans;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
       for (j = 0; j < m; j++)
          scanf("%d", &board[i][j]);
    for (i = 0; i < n; i++)
       for (j = 1; j < m; j++)
          board[i][j] += board[i][j-1];
    for (j = 0; j < m; j++) best[j] = board[0][j];
    for (j = m-2; j >= 0; j--)
       if (best[j+1] > best[j]) best[j] = best[j+1];
    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
              best[m-1] = best[m-2] + board[i][m-1];
              for (j = m-2; j >= 1; j--)
                 best[j] = max(best[j-1] + board[i][j], best[j+1]);
        } else {
               best[0] = best[1] + board[i][0];
               for (j = 1; j < m-1; j++)
                  best[j] = max(best[j+1] + board[i][j], best[j-1]);
        }
    }
    if ((n-1) % 2 == 1) ans = best[0];
    else ans = best[m-1];
    for (j = 1; j < m-1; j++)
       if (best[j] > ans) ans = best[j];
    cout << ans << endl;
    return 0;
}