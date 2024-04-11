#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
     int in, out, w, s, v;
     bool operator < (const node &A) const{
          if (in != A.in) return in < A.in;
          return out > A.out;
     }
} a[501];
int f[501][1001], n, m, v[1001];
vector<int> e[1001];

int read(){
     char ch;
     for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
     int cnt = 0;
     for (; ch >= '0' && ch <= '9'; ch = getchar())
          cnt = cnt * 10 + ch - '0';
     return cnt;
}

int main(){
   //  freopen("d.in", "r", stdin);
   //  freopen("d.out", "w", stdout);
     n = read(); m = read();
     a[0].in = 0; a[0].out = n << 1; a[0].w = 0; a[0].s = m; a[0].v = 0;
     for (int i = 1; i <= n; i++) 
          a[i].in = read(), a[i].out = read(), a[i].w = read(), a[i].s = read(), a[i].v = read();
     sort(a, a + n + 1);
     for (int i = 0; i <= n << 1; i++) e[i].clear();
     for (int i = 1; i <= n; i++) e[a[i].in].push_back(i);
     memset(f, 0, sizeof(f));
     for (int i = n; i >= 0; --i)
     {
          for (int j = a[i].w; j <= m && j <= a[i].w + a[i].s; j++) 
          {
               memset(v, 0, sizeof(v));
               for (int x = a[i].in; x < a[i].out; x++)
               {
                    v[x + 1] = max(v[x + 1], v[x]);
                    for (int k = 0; k < e[x].size(); k++)
                    {
                         int l = e[x][k];
                         if (a[l].out > a[i].out || l == i) continue;
                         v[a[l].out] = max(v[a[l].out], v[x] + f[l][j - a[i].w]);
                    }
               }
               f[i][j] = v[a[i].out] + a[i].v;
          }
          for (int j = 1; j <= m; j++) f[i][j] = max(f[i][j], f[i][j - 1]);
     }
     printf("%d\n", f[0][m]);
}