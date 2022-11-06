#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
using namespace std;
int n,m;
pair<int,pair<int,int> > kr[300005];
pair<int,int> S[300005];
int size;
int wynik;
int wyn[300005];
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d%d",&kr[i].ss.ff,&kr[i].ss.ss,&kr[i].ff);
  }
  sort(kr+1,kr+1+m);
  
  for(int i=1;i<=m;i++)
  {
    
    int a=kr[i].ss.ff;
    int b=kr[i].ss.ss;
    
    S[++size]=MP(b,wyn[a]+1);
//     S[++size]=MP(a,wyn[b]+1);
    wynik=max(wynik,wyn[a]+1);
//     wynik=max(wynik,wyn[b]+1);
    if(kr[i].ff!=kr[i+1].ff)
    {
      for(int j=1;j<=size;j++)
      {
    int gdzie=S[j].ff;
    int ile = S[j].ss;
    wyn[gdzie]=max(wyn[gdzie],ile);
      }
      size=0;
    }
  }
  
  printf("%d",wynik);
  
  return 0;
}