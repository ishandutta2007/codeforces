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
const int N = 500005;
int n, m, w;
LL pref[N], height[N];
bool canGet(LL H)
{
  LL sum = 0;
  LL moves = 0;
  for(int i=1; i<=n; i++)pref[i] = 0;
  for(int i=1; i<=n; i++)
  {
      sum += pref[i];
      if(height[i] + sum < H)
      {
    moves += H - height[i] - sum;
    pref[i + w] -= H - height[i] - sum;
    sum += H - height[i] - sum;
    if(moves > m)return 0;
      }
  }  
  return moves <= m;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n>>m>>w;
  for(int i=1; i<=n; i++)
    cin>>height[i];
  
  LL poc = 1;
  LL kon = 1e10;
  LL res = 0;
  while(poc <= kon)
  {
    LL sr = (poc + kon) / 2;
    if(canGet(sr))
    {
      res = sr;
      poc = sr + 1;
    }
    else
      kon = sr - 1;
  }
  cout<<res;
  return 0;
}