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
#define check if(nr <= n-k && nr2 <= k && (k-nr2)%3 == 0 && !((n-k-nr)%3)){cout<<"yes\n"; continue;}
using namespace std;


int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--)
  {
      LL n, k, d1, d2;
      cin>>n>>k>>d1>>d2;
      //Case 1:
      LL nr = 2*d1 + d2;
      LL nr2 = 2*d2 + d1;
      check
      swap(nr, nr2);
      check
      if(d1 < d2)swap(d1, d2);
      nr = d1+d2;
      nr2 = 2*d1 - d2;
      check     
      swap(nr, nr2);
      check
      cout<<"no\n";
  }
  return 0;
}