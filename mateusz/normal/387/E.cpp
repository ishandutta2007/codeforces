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
#define INF 1000000001
#define MAX_N 1000005
using namespace std;
const int czapa=1048576;
int drz[2*czapa+1];
int tab[2*MAX_N];
int gdzie[2*MAX_N];
int per[2*MAX_N];
int drz2[2*czapa+1];

int ciag[MAX_N];
int n,m;
LL wynik;

void wrzuc2(int poz)
{
  poz+=czapa;
  drz2[poz]++;
  poz>>=1;
  while(poz>=1)
  {
    drz2[poz]++;
    poz>>=1;
  }
}
int szukaj2(int poza,int pozb)
{
  poza+=czapa;
  pozb+=czapa;
  int ret=drz2[poza];
  if(poza!=pozb)ret+=drz2[pozb];
  while(poza/2!=pozb/2)
  {
    if(poza%2==0)
      ret+=drz2[poza+1];
    if(pozb%2==1)
      ret+=drz2[pozb-1];
    poza>>=1;
    pozb>>=1;
  }
  return ret;
}

void wrzuc(int poz,int w)
{
  poz+=czapa;
  drz[poz]=w;
  poz>>=1;
  while(poz>=1)
  {
    drz[poz]=min(drz[poz*2],drz[poz*2+1]);
    poz>>=1;
  }
}
int szukaj(int poza,int pozb)
{
  poza+=czapa;
  pozb+=czapa;
  int ret=min(drz[poza],drz[pozb]);
  while(poza/2!=pozb/2)
  {
    if(poza%2==0)
      ret=min(drz[poza+1],ret);
    if(pozb%2==1)
      ret=min(ret,drz[pozb-1]);
    poza>>=1;
    pozb>>=1;
  }
  return ret;
}
LL rozwaz(int P,int K)
{
  if(K<P)return 0;
  LL ret=0;
  int m=szukaj(P,K);
  if(m==INF)return 0;
  
  if(gdzie[m]>=1)
  {
    return rozwaz(P,ciag[m]-1)+rozwaz(ciag[m]+1,K);
  }
  else
  {
    ret=K-P+1-szukaj2(P,K);
    wrzuc2(ciag[m]);
    wrzuc(ciag[m],INF);
    return ret+rozwaz(P,K);
  }
  
 
}

int main()
{
  for(int i=1;i<=2*czapa;i++)drz[i]=INF;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&tab[i]);
    ciag[tab[i]]=i;
    wrzuc(i,tab[i]);
  }
  
  for(int i=1;i<=m;i++)
  {
    scanf("%d",&per[i]);
    
    gdzie[per[i]]=i;
    
  }
  
  wynik=rozwaz(1,n);
  printf("%lld",wynik);
  
  return 0;
}