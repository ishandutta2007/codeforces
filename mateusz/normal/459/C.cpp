#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
#include <algorithm>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
using namespace std;
const int N = 1005, MOD = 1000000007;
int n, k, d;
int gdzie[N][N];
queue<int>zbior2[N], zbior[N];

int main()
{
  scanf("%d%d%d",&n,&k,&d);
  if(k >= n)
  {
    for(int i=1; i<=d; i++)
    {
      for(int j=1; j<=n; j++)
    printf("%d ", j);
      printf("\n");
    }
    return 0;
  }
  
  for(int i=1; i<=n; i++)
  {
    gdzie[1][i] = i%k+1;
    zbior[i%k+1].push(i);
  }
  for(int i=2; i<=d; i++)
  {
    int wsk = 1;
    int G = 1;
    for(int j=1; j<=n; j++)
    {
      while(!zbior[j].empty())
      {
    int w = zbior[j].front();
    zbior[j].pop();
    zbior2[G++].push(w);
    if(G > k)G = 1;
      }
    }
/*    for(int j=1; j<=n; j++)
    {
      while(zbior[wsk].empty())
      {
    wsk++;
    if(wsk > n)wsk = 1;
      }
      int w = zbior[wsk].front();
      zbior[wsk].pop();
      zbior2[G].push(w);
      if(j % k == 0)G++;
      wsk++;
      if(wsk > n)wsk = 1;
    }    */  
    for(int j=1; j<=k; j++)
    {
      while(!zbior[j].empty())zbior[j].pop();
     
      while(!zbior2[j].empty())
      {
    int w = zbior2[j].front();
    zbior2[j].pop();
    zbior[j].push(w);
    gdzie[i][w] = j;
      }
    }
  }
  set<int>S;
  for(int i=1; i<=n; i++)
  {
    LL hasz = 0;
    for(int j=1; j<=d; j++)
    {
      hasz = (hasz*1013 + gdzie[j][i])%MOD;
    }
    if(S.find(hasz) != S.end())
    {
      printf("-1");
      return 0;
    }
    S.insert(hasz);
  }
  for(int i=1; i<=d; i++)
  {
    for(int j=1; j<=n; j++)
    {
      printf("%d ", gdzie[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}