#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<endl;

using namespace std;

const LL M = 1000000000;
vector<int>S;
LL a, b, c;
int digits(LL w)
{
  LL ret = 0;
  while(w)
  {
    ret += w % 10;
    w /= 10;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>a>>b>>c;
  for(int i=0; i<=81; i++)
  {
    LL l = 1;
    for(int j=1; j<=a; j++)
      l *= (LL)i;
    LL f = b * l + c;
    if(f > 0 && f < M && digits(f) == i)
      S.PB(f);
  }
  sort(S.begin(), S.end());
  cout<<S.size()<<endl;
  for(int i=0; i<S.size(); i++)cout<<S[i]<<" ";
  return 0;
}