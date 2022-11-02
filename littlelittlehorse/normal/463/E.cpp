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
     node *next;
     int where;
} a[200001], *first[100001];
int cnt, n, Q, v[100001], l, dist[100001], c[2000001], father[100001], prime[10001], len, ans[100001];
vector<int> factor[2000001], value[100001];
bool b[10001], appear[2000001];

int read(){
     char ch;
     for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
     int cnt = 0;
     for (; ch >= '0' && ch <= '9'; ch = getchar()) cnt = cnt * 10 + ch - '0';
     return cnt;
}

inline void makelist(int x, int y){
     a[++l].where = y; a[l].next = first[x];
     first[x] = &a[l];
}

inline void calc(vector<int> &a, int value){
     a.clear();
     for (int i = 1; prime[i] * prime[i] <= value; i++)
          if (!(value % prime[i])) 
          {
               a.push_back(prime[i]);
               for (; !(value % prime[i]); ) value /= prime[i];
          }
     if (value != 1) a.push_back(value);
}

inline void soso(int now){
     ans[now] = -1;
     for (int i = 0; i < value[now].size(); i++)
     {
          if (factor[value[now][i]].size())
          {
               int where = factor[value[now][i]].back();
               if (dist[where] > dist[ans[now]]) ans[now] = where;
          }
          factor[value[now][i]].push_back(now);
     }
     for (node *x = first[now]; x; x = x->next)
          if (dist[x->where] == dist[now] + 1) soso(x->where);
     for (int i = 0; i < value[now].size(); i++)
          factor[value[now][i]].pop_back();
}

inline void work(int now){
     cnt = 0;
     for (int i = father[now]; i; i = father[i])
          for (int j = 0; j < value[i].size(); j++)
               if (factor[value[i][j]].empty()) 
                    factor[value[i][j]].push_back(i), c[++cnt] = value[i][j], appear[c[cnt]] = true;
     soso(now);
     for (int i = 1; i <= cnt; i++) appear[c[i]] = false, factor[c[i]].clear();
}

int main(){
     //freopen("e.in", "r", stdin);
     //freopen("e.out", "w", stdout);
     memset(b, false, sizeof(b)); b[1] = true;
     len = 0;
     for (int i = 2; i <= 10000; i++)
     {
          if (!b[i]) prime[++len] = i;
          for (int j = 1; j <= len; j++)
               if (prime[j] * i > 10000) break;
               else
               {
                    b[prime[j] * i] = true;
                    if (!(i % prime[j])) break;
               }
     }
     n = read(); Q = read();
     for (int i = 1; i <= n; i++) 
     {
          v[i] = read();
          calc(value[i], v[i]);
     }
     memset(first, 0, sizeof(first)); l = 0;
     for (int i = 1; i < n; i++)
     {
          int x, y;
          x = read(); y = read();
          makelist(x, y); makelist(y, x);
     }
     memset(dist, 0, sizeof(dist)); c[1] = 1; dist[1] = 1;
     memset(father, 0, sizeof(father));
     for (int k = 1, l = 1; l <= k; l++)
     {
          int m = c[l];
          for (node *x = first[m]; x; x = x->next)
               if (!dist[x->where]) dist[x->where] = dist[m] + 1, father[x->where] = m,
                                    c[++k] = x->where;
     }
     for (int i = 1; i <= 2000000; i++) factor[i].clear(), appear[i] = false;
     work(1);
     for (;Q--;)
     {
          int type;
          type = read();
          if (type == 1) 
          {
               int x;
               x = read();
               printf("%d\n", ans[x]);
          }
          else
          {
               int x, y;
               x = read(); y = read();
               calc(value[x], y);
               work(x);
          }
     }
}