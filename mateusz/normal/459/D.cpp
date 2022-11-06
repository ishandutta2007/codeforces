#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>
#include <queue>
#define LD long double
#define LL long long
#define MP make_pair
#define ff first
#define ss second
#define PB push_back
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;
const int N = 1000005, czapa = 1048576;
int n;
pair<int, int>prz[N];
int tab[N];
int zlicz[N], ile[N];
int drz[2*czapa];
void insert(int poz)
{
  poz += czapa;
  while(poz >= 1)
  {
    drz[poz] ++;
    poz >>= 1;
  }
}
int query(int poza, int pozb)
{
  poza += czapa;
  pozb += czapa;
  int ret = drz[poza];
  if(poza != pozb)ret += drz[pozb];
  while(poza/2 != pozb/2)
  {
    if(poza % 2 == 0)
      ret += drz[poza+1];
    if(pozb % 2 == 1)
      ret += drz[pozb-1];
    poza >>= 1;
    pozb >>= 1;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>prz[i].ff;
    prz[i].ss = i;
  }
  sort(prz+1, prz+1+n);
  int in = 0;
  for(int i=1; i<=n; i++)
  {
    if(prz[i].ff != prz[i-1].ff)
      in++;
    tab[prz[i].ss] = in;
  }
  for(int i=n; i>=1; i--)
  {
    zlicz[tab[i]]++;
    ile[i] = zlicz[tab[i]];
  }
    for(int i=1; i<=n; i++)
    zlicz[i] = 0;
  LL wynik = 0;
  for(int i=1; i<=n; i++)
  {
    zlicz[tab[i]]++;
    insert(zlicz[tab[i]]);
    if(i < n)
    {
      wynik += query(ile[i+1]+1, n+1);     
    }
  }
  cout<<wynik;
  return 0;
}