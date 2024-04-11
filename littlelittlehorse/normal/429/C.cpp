#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

struct node{
       node *next;
       vector<int> where;
} *first[25];
vector<int> v[25], use;
int cnt, n, a[25], amount[25], c[25], q[25];
vector< vector<int> > b1, b2;
set<vector<int> > events;

inline void makelist(int x, vector<int> y){
       node *now = new node;
       now->where = y;
       now->next = first[x];
       first[x] = now;
}

inline void soso(int step, int sum, int raise){
       if (step == cnt + 1) 
       {
          int status = 0;
          if (sum && amount[sum + 1] && raise > 1) 
          {
                  makelist(sum, use);
          }
          return;
       }
       for (int i = 0; i <= amount[c[step]]; i++)
           if (i * c[step] + sum > n) break;
           else use[c[step]] = i, soso(step + 1, sum + i * c[step], raise + i);
}

int main(){
    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] < a[j]) swap(a[i], a[j]);
    memset(amount, 0, sizeof(amount));
    for (int i = 1; i <= n; i++) amount[a[i]]++;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (i == 1 || a[i] != a[i - 1]) c[++cnt] = a[i];
    memset(first, 0, sizeof(first));
    use.clear();
    for (int i = 1; i <= n + 1; i++) use.push_back(0);
    soso(1, 0, 0);
    b1.clear(); b2.clear();
    vector<int> w;
    for (int i = 1; i <= n + 1; i++) w.push_back(0);
    b1.push_back(w);
    for (int i = n; i >= 1; --i)
    {
        events.clear();
       // printf("%d %d\n", a[i], b1.size());
        if (a[i] == 1) b1[0][1]++;
        else
        {
            b2.clear();
            for (int j = 0; j < b1.size(); j++)
            {
                memset(q, 0, sizeof(q));
                  //  printf("R %d\n", a[i] - 1);
                for (node *x = first[a[i] - 1]; x; x = x->next)
                {
                //    printf("haha\n");
                    bool ok = true;
                    for (int k = 1; k <= n; ++k)
                        if ((x->where)[k] > b1[j][k])
                        {
                     //      printf("TT %d\n", k);
                           ok = false;
                           break;
                        }
                    if (ok)
                    {
                           vector<int> w;
                           w.push_back(0);
                           for (int k = 1; k <= n; k++)
                               w.push_back(b1[j][k] -(x->where)[k]);
                           w[a[i]]++;
                          // for (int k = 1; k <= n; k++) printf("%d ", w[k]);
                         //  printf("\n");
                           if (events.find(w) == events.end()) 
                          events.insert(w), b2.push_back(w);
                    }
                }
            }
            b1 = b2;
        }
    }
 //   printf("%d\n", b1.size());
    for (int i = 0; i < b1.size(); i++)
        if (b1[i][a[1]] == 1)
        {
           bool ok = true;
           for (int j = 1; j <= n; j++)
               if (j != a[1] && b1[i][j])
               {
                  ok = false;
                  break;
               }
           if (ok)
           {
            printf("YES\n");
            return 0;
            }
        }
    printf("NO\n");
}