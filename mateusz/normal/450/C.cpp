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
LL n, m, k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n>>m>>k;
  if(n < m)swap(n, m);
  if(k > n+m-2)
    printf("-1");
  else
  {
    if(k > n-1)
    {
      k -= n-1;
      LL w1 = m/(k+1);
      k += n-1;
      k -= m-1;
      LL w2 = n/(k+1);
      cout<<max(w1, w2);
    }
    else
    {
      if(k <= m-1)
      cout<<max(n*(m/(k+1)), m*(n/(k+1)));
      else
    cout<<m*(n/(k+1));
    }
  }
  
  return 0;
}