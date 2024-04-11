#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a[100001];
vector<int> e[100001];
int n, m, K, w[100001][2], c[200001], W[100001];
const int P = 1000000007;
long long dist[100001];
bool b[100001];

int main(){
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);
     scanf("%d%d%d", &n, &m, &K);
     for (int i = 1; i <= n; i++) a[i].clear(), e[i].clear();
     for (int i = 1; i <= m; i++)
     {
          int x, y, z;
          scanf("%d%d%d", &x, &y, &z);
          a[x].push_back(y); e[x].push_back(z);
          a[y].push_back(x); e[y].push_back(z);
     }
     memset(dist, 127, sizeof(dist));
     int ans = 0;
     for (int i = 1; i <= K; i++) 
     {
          scanf("%d%d", &w[i][0], &w[i][1]);
          dist[w[i][0]] = min(dist[w[i][0]], (long long)w[i][1]);
          if (++W[w[i][0]] > 1) ++ans;
     }
     int k = 0;
     memset(b, false, sizeof(b));
     dist[1] = 0;
     for (int i = 1; i <= n; i++) 
          if (dist[i] < 1LL << 50LL) c[++k] = i, b[i] = true;
     for (int l = 0; l != k;)
     {
          if (++l > 200000) l = 1;
          int m = c[l];
          b[m] = false;
          for (int i = 0; i < a[m].size(); i++) 
               if (dist[m] + e[m][i] < dist[a[m][i]])
               {
                    dist[a[m][i]] = dist[m] + e[m][i];
                    if (!b[a[m][i]]) 
                    {
                         b[a[m][i]] = true;
                         if (++k > 200000) k = 1;
                         c[k] = a[m][i];
                    }
               }
     }
     for (int i = 1; i <= n; i++) 
          if (W[i])
          {
               bool ok = true;
               for (int j = 0; j < a[i].size() && ok; j++)
                    if (dist[a[i][j]] + e[i][j] == dist[i]) ok = false;
               if (!ok) ++ans;
          }
     printf("%d\n", ans);
}