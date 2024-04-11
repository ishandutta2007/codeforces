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
const int N = 1005;
const int INF = 1e9;
int wash[N], dry[N], fold[N];
queue<pair<int, int> >Q;
int main()
{
  ios_base::sync_with_stdio(0);
  int k, n1, n2, n3, t1, t2, t3;
  cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
  
  for(int i=1; i<=k; i++)
  {
    Q.push(MP(0, 0));
  }
  
  while(!Q.empty())
  {
    int czas = Q.front().ff;
    int skad = Q.front().ss;
    Q.pop();
    if(skad == 0)
    {
      int mini = INF;
      int ktory = 0;
      for(int i=1; i<=n1; i++)
      {
    if(wash[i] < mini)
    {
      mini = wash[i];
      ktory = i;
    }
      }
      wash[ktory] = max(wash[ktory], czas)+t1;
      Q.push(MP(wash[ktory], 1));
    }
    if(skad == 1)
    {
      int mini = INF;
      int ktory = 0;
      for(int i=1; i<=n2; i++)
      {
    if(dry[i] < mini)
    {
      mini = dry[i];
      ktory = i;
    }
      }
      dry[ktory] = max(dry[ktory], czas)+t2;
      Q.push(MP(dry[ktory], 2));
    }
    if(skad == 2)
    {
      int mini = INF;
      int ktory = 0;
      for(int i=1; i<=n3; i++)
      {
    if(fold[i] < mini)
    {
      mini = fold[i];
      ktory = i;
    }
      }
      fold[ktory] = max(fold[ktory], czas)+t3;
    }
  }
  int ans = 0;
  for(int i=1; i<=n3; i++)ans = max(ans, fold[i]);
  cout<<ans;
  return 0;
}