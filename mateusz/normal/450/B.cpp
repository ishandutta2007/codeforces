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
#define double long double
#define MP make_pair
#define ff first
#define ss second
#define PB push_back
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;
const int N = 105;
const LL M = 1000000007;
LL n,x,y;
struct macierz
{
  LL a, b, c, d;
  macierz(LL c=0, LL v=0, LL x=0, LL z=0): a(c), b(v), c(x), d(z) {}
  macierz operator * (macierz const &B)const
  {
    macierz A = *this;
    macierz C;
    C.a = (A.a*B.a + A.c*B.b)%M;
    if(C.a < 0)
      C.a += M;
//     C.a %= M;
    C.b = (A.b*B.a + A.d*B.b)%M;
      if(C.b < 0)
      C.b += M;/*C.b %= M;*/
    C.c = (A.a*B.c + A.c*B.d)%M;
      if(C.c < 0)
      C.c += M;/*C.c %= M;*/
    C.d = (A.b*B.c + A.d*B.d)%M;
      if(C.d < 0)
      C.d += M;/*C.d %= M;*/
    return C;
  }
  
};
macierz jednostkowa = macierz(0, 1, -1, 1);
macierz poteguj(LL pot)
{
  if(pot == 0)return macierz(1, 0, 1, 0);
  if(pot == 1)
    return jednostkowa;
  macierz ret = poteguj(pot/2);
  ret = ret*ret;
  if(pot % 2== 1)
    ret = ret * jednostkowa;
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin>>x>>y>>n;
  if(n == 1)
  {
    if(x > 0)x%=M;
    else
      x = M+(x%M);
    cout<<x;
    return 0;
  }
  if(n == 2)
  {
    if(y > 0)y%=M;
    else
      y = M+(y%M);
    cout<<y;
    return 0;
  }
  n -= 2;
    
  macierz wynik = poteguj(n);
  LL wyn = (y*wynik.d + x*wynik.c)%M;
  if(wyn < 0)wyn += M;
  wyn %= M;
  cout<<wyn;
  
  return 0;
}