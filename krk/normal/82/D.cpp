#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int Inf = 2000000000;
const int Maxn = 1005;

int n;
int a[Maxn];
int best[Maxn][Maxn];
pair <int, int> p[Maxn][Maxn];
int from[Maxn][Maxn];
stack <pair <int, int> > res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    fill((int*)best, (int*)best + Maxn * Maxn, Inf);
    best[0][0] = 0;
    for (int i = 2; i < n + 2; i += 2)
       for (int j = 0; j <= i - 2; j++)
          if (best[i - 2][j] < Inf) {
                     int cand = best[i - 2][j] + max(a[j], a[i - 1]);
                     if (cand < best[i][i]) {
                              best[i][i] = cand; 
                              p[i][i] = make_pair(j + 1, i); 
                              from[i][i] = j;
                     }
                     cand = best[i - 2][j] + max(a[j], a[i]);
                     if (cand < best[i][i - 1]) {
                              best[i][i - 1] = cand; 
                              p[i][i - 1] = make_pair(j + 1, i + 1);
                              from[i][i - 1] = j;
                     }
                     cand = best[i - 2][j] + max(a[i - 1], a[i]);
                     if (cand < best[i][j]) {
                              best[i][j] = cand; 
                              p[i][j] = make_pair(i, i + 1);
                              from[i][j] = j;
                     }
          }
    int i = n + 1, j = n + 1;
    if (n % 2 == 0) { i--; j--; }
    cout << best[i][j] << endl;
    while (i > 0) {
          res.push(p[i][j]);
          j = from[i][j];
          i -= 2;
    }
    while (!res.empty()) {
          pair <int, int> p = res.top(); res.pop();
          cout << p.first;
          if (p.second <= n) cout << " " << p.second; 
          cout << endl;
    }
    return 0;
}