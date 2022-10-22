#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 305;

int n;
int dist[Maxn][Maxn];
int k;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
       for (int j = 1; j <= n; j++) cin >> dist[i][j];
    cin >> k;
    while (k--) {
          int a, b, c; cin >> a >> b >> c;
          if (c < dist[a][b]) {
                dist[a][b] = dist[b][a] = c;
                for (int i = 1; i <= n; i++)
                   for (int j = 1; j <= n; j++)
                      dist[i][j] = min(dist[i][j], 
                                       min(dist[i][a] + c + dist[b][j], dist[i][b] + c + dist[a][j]));
          }
          long long res = 0;
          for (int i = 1; i <= n; i++)
             for (int j = i + 1; j <= n; j++)
                res += (long long) dist[i][j];
          cout << res;
          if (k) cout << " ";
    }
    cout << endl;
    return 0;
}