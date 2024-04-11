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
const int N = 300005;
const int czapa = 524288;
int n, x;
class Mod
{
public:
  int w;
  const static int M = 1000007;
  Mod (int _w = 0): w(_w%M) {}
  bool operator == (Mod const &B) const
  {
    return w == B.w;
  }
  bool operator != (Mod const &B) const
  {
    return w != B.w;
  }
  
  Mod operator + (Mod const &B) const
  {
    return (w + B.w)%M;
  }
  Mod operator - (Mod const &B) const
  {
    return ((w - B.w)+M)%M;
  }
  Mod operator * (Mod const &B) const
  {
    return (LL)w * B.w % M;
  }
  void operator += (Mod const &B)
  {
    *this = *this + B;
  }
  void operator *= (Mod const &B) 
  {
    *this = *this * B;
  }
  void operator -= (Mod const &B) 
  {
    *this = *this - B;
  }
};
class Tree
{
public:
  Mod drz[2*czapa];
  void insert(int poz, Mod w)
  {
    poz += czapa;
    while(poz >= 1)
    {
      drz[poz] += w;
      poz >>= 1;
    }
  }
  Mod query(int poza, int pozb)
  {
    poza += czapa;
    pozb += czapa;
    Mod ret = drz[poza];
    if(poza != pozb)ret += drz[pozb];
    while(poza/2 != pozb/2)
    {
      if(poza%2 == 0)
    ret += drz[poza+1];
      if(pozb%2 == 1)
    ret += drz[pozb-1];
      poza >>= 1;
      pozb >>= 1;
    }
    return ret;
  }
};
Tree pref, suf;

Mod pot[N];
bool isTriple(int w)
{
  pref.insert(w, pot[n-w]);
  suf.insert(w, pot[w-1]);
  int p, k;
  if(w <= n-w+1)
  {
    p = 1;
    k = 2*w-1;
  }
  else
  {
    p = 2*w - n;
    k = n;
  }
  
  Mod HP = pref.query(0, k) - pref.query(0, p-1);
  Mod HS = suf.query(p, n+1) - suf.query(k+1, n+1);
  if(HP * pot[p-1] != HS * pot[n-k])
    return 1;
  return 0;  
}

int main()
{
  pot[0] = Mod(1);
  
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
  {
    pot[i] = pot[i-1] * Mod(2);
  }
  for(int i=1; i<=n; i++)
  {
    scanf("%d", &x);
    if(isTriple(x))
    {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}