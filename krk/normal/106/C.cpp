#include <iostream>
using namespace std;

const int Maxn = 1005;
const int Maxm = 15;

int n, m, c, e;
int canmake[Maxm], cost[Maxm], earn[Maxm];
int best[Maxn];

int main()
{
    cin >> n >> m >> c >> e;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b >> cost[i] >> earn[i];
        canmake[i] = a / b;
    }
    for (int i = 0; i + c <= n; i++)
       best[i + c] = max(best[i + c], best[i] + e);
    for (int i = 0; i < m; i++)
       for (int j = n; j >= 0; j--)
          for (int l = 1; l <= canmake[i] && j - l * cost[i] >= 0; l++)
             best[j] = max(best[j], best[j - l * cost[i]] + l * earn[i]);
    cout << best[n] << endl;
    return 0;
}