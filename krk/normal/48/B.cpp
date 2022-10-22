#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 51;

int n, m, trees[Maxn][Maxn], a, b;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
       for (int j = 1; j <= m; j++) {
           cin >> trees[i][j];
           trees[i][j] += trees[i-1][j] + trees[i][j-1] - trees[i-1][j-1];
       }
    cin >> a >> b;
    int best = n * m;
    for (int i = 1; i <= n; i++)
       for (int j = 1; j <= m; j++) {
           if (i >= a && j >= b)
              best = min(best, trees[i][j] - trees[i-a][j] - trees[i][j-b] + trees[i-a][j-b]);
           if (i >= b && j >= a)
              best = min(best, trees[i][j] - trees[i-b][j] - trees[i][j-a] + trees[i-b][j-a]);
       }
    cout << best << endl;
    return 0;
}