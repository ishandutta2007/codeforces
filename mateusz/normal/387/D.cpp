#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define DEBUG(x) cout<<#x<<" "<<(x)<<endl;
#define INF 1000000000
#define MAX_N 1000005
using namespace std;

bool odw[1005];
int skoj[1005];
int n,m;
int self[1005];
pair<int,int>kr[1005];
int stwy[1005],stwe[1005];
vector<int>V[1005];
bool DFS(int w)
{
//   DEBUG(w);
  odw[w]=1;
  for(int i=0;i<V[w].size();i++)
  {
    int u=V[w][i];
//     cout<<u<<" "<<skoj[u]<<endl;
    if(skoj[u]==0||(odw[skoj[u]]==0&&DFS(skoj[u])==1))
    {
      skoj[w]=u;
      skoj[u]=w;
      return 1;
    }
  }
  return 0;
}


int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d",&kr[i].ff,&kr[i].ss);
//     V[kr[i].ff].PB(MP(kr[i].ss,i));
    stwy[kr[i].ff]++;
    stwe[kr[i].ss]++;
    if(kr[i].ff==kr[i].ss)self[kr[i].ff]=1;
  }
  int mx=1000000;
  for(int i=1;i<=n;i++)
  {
//     DEBUG(i);
    int w=i;
    int wynik=0;
    wynik=n-stwy[i]+n-stwe[i];
//     DEBUG(wynik);
    if(self[i]==0)wynik--;  
//     DEBUG(wynik);
    for(int j=1;j<=2*n;j++)
    {
      skoj[j]=0;
      V[j].clear();
    }
    int ile=0;
    for(int j=1;j<=m;j++)
    {
      if(!(kr[j].ff==i||kr[j].ss==i))
      {
    ile++;
    V[kr[j].ff].PB(kr[j].ss+n);
      }
    }
//     DEBUG(ile);
    int sk=0;
    int jest=1;
    while(1)
    {
//       DEBUG(sk);
      if(jest==0)
    break;
      jest=0;
      for(int j=1;j<=n;j++)
      {
    odw[j]=0;
      }
      
      for(int j=1;j<=n;j++)
      {
    if((skoj[j]==0&&odw[j]==0)&&DFS(j))
    {
      sk++;
      jest=1;
      break;
      
    }
      }
      
    }
//     DEBUG(sk);
//     cout<<ile-sk<<endl;
    wynik+=(n-1-sk)+(ile-sk);
//     DEBUG(wynik);
    mx=min(mx,wynik);
  }
  printf("%d",mx);
  return 0;
}