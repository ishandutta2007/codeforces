#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define DEBUG(lol) cerr<<#lol<<" "<<(lol)<<endl;
using namespace std;
const int N = 100005;
LL dp[N];
int zlicz[N], n, x;
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n;
  int mx = 0;
  for(int i=1; i<=n; i++)
  {
    cin>>x;
    mx = max(mx, x);
    zlicz[x]++;
  }
  dp[1] = zlicz[1];
  for(int i=2; i<=mx; i++)
    dp[i] = max(dp[i-1], (LL)zlicz[i]*i + dp[i-2]);
  cout<<dp[mx];
  return 0;
}