#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool b[1000001];
int c[1000001], len, Left;
long long n, m;
map <long long, vector<long long> > events;

inline void work(long long n, long long step){
     //cerr << n << " " << step << endl;
     if (!step || n == 1) 
     {
          printf("%I64d ", n);
          --Left;
          return;
     }
     vector<long long> &a = events[n];
     for (long long i = 0; i < a.size(); i++)
          {
               work(a[i], step - 1);
               if (!Left) return;
          }
}

inline void soso(long long now){
     events[now].clear();
     vector<long long> &a = events[now];
     for (long long i = 1; i * i <= now; i++)
          if (!(now % i)) 
          {
               a.push_back(i);
               if (i * i != now) a.push_back(now / i);
          }
     sort(a.begin(), a.end());
}

int main(){
     Left = 100000;
     scanf("%I64d%I64d", &n, &m);
     events.clear();
     for (long long i = 1; i * i <= n; i++) 
          if (!(n % i)) soso(i), soso(n / i);
     if (m >= 100000) 
     {
          if (n == 1) printf("1\n");
          else for (int i = 1; i <= 100000; i++) printf("1 ");
     }
     else
     work(n, m);
}