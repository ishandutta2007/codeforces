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
const int INF = 1e9+5;
int n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n;
  int mini = INF;
  int maxi = -INF;
  int ilemini = 0;
  int ilemaxi = 0;
  for(int i=1; i<=n; i++)
  {
    int x;
    cin>>x;
    if(x > maxi)
    {
      maxi = x;
      ilemaxi = 0;
    }
    if(x == maxi)
      ilemaxi++;
    if(x < mini)
    {
      mini = x;
      ilemini = 0;
    }
    if(x == mini)
      ilemini++;
  }
  if(mini == maxi)
    cout<<0<<" "<<(LL)ilemaxi*(ilemaxi-1)/2;
  else
    cout<<maxi - mini <<" "<<(LL)ilemaxi * ilemini;
  return 0;
}