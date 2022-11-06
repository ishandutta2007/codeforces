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
const int N = 100005;
int tab[N];
int S[N];
int n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>tab[i];
  }
  tab[0] = -1;
  int poc = 1;
  int kon = n;
  int ret = 0;
  while(poc <= kon)
  {      
    int psize = 1;
    int ksize = 0;
    int sr = (poc + kon)/2;
    for(int i=1; i<=sr; i++)
    {
      if(tab[i] <= tab[i-1])
      {
    S[++ksize] = i-1;
      }
    }
    int tak = 0;
    for(int i=sr; i<=n; i++)
    {
      
      while(psize <= ksize && S[psize] <= i-sr)psize++;
      if(ksize - psize + 1 == 0)
      {
    tak = 1;
    break;    
      }
      if(ksize - psize + 1 == 1)
      {
    if(S[psize] == i-sr+1 || tab[S[psize]+1] - tab[S[psize]-1] > 1)
    {
      tak = 1;
      break;
    }
    else
    {
      if(S[psize] == i-1 || tab[S[psize]+2] - tab[S[psize]] > 1)
      {
        tak = 1;
        break;
      }
    }
      }
      if(tab[i+1] <= tab[i])S[++ksize] = i;
    }
    if(tak)
    {
      ret = sr;
      poc = sr+1;
    }
    else
      kon = sr-1;
  }
  cout<<ret;
  return 0;
}