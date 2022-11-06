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
const LL INF = 1e18;
LL n, m, k;
priority_queue<pair<pair<LL, int>, int> >Q;
LL odl[N];
vector<pair<int, int> >V[N];
bool odw[N];
int a, b, waga;
int gdzie[N], wagson[N];
bool nieuzyty[N];
bool jest[N];
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n >> m >> k;
  for(int i=1; i<=m ; i++)
  {
    cin>>a >> b >> waga;
    V[a].PB(MP(b, waga));
    V[b].PB(MP(a, waga));
    
  }
  int ans = 0;
  for(int i=1; i<=k; i++)
  {
    cin>>gdzie[i] >> wagson[i];
    if(jest[gdzie[i]])
      ans++;
    jest[gdzie[i]] = 1;
  }
  
  for(int i=2; i<=n; i++)
  {
    odl[i]  = INF;
  }
  
//   odw[1] = 1;
  odl[1] = 0;
  Q.push(MP(MP(0, 1), 1));
  while(!Q.empty())
  {
    int w = Q.top().ss;
    int jak = Q.top().ff.ss;
//     DEBUG(w);
//     DEBUG(jak);
    Q.pop();
    if(!odw[w])
    {
      odw[w] = 1;
      if(jak == 1)
    nieuzyty[w] = 1;
      for(int i=0; i<V[w].size(); i++)
      {
    int u = V[w][i].ff;
    int kr = V[w][i].ss;
//  cout<<odl[u]<<" "<<odl[w]+kr<<endl;
    if(!odw[u] && odl[u] >= odl[w] + kr)
    {
      odl[u] = odl[w] + kr;
      Q.push(MP(MP(-odl[u], 1), u));
    }
      }
      if(w == 1)
      {
    for(int i=1; i<=k; i++)
    {
      int u = gdzie[i];
       if(!odw[u] && odl[u] > odl[w] + wagson[i])
       {
        
         odl[u] = odl[w] + wagson[i];
         Q.push(MP(MP(-odl[u], 0), u));
      }
    }
      }
    }
  }
  
//   int ans = 0;
  for(int i=1; i<=n; i++)if(jest[i] && nieuzyty[i])ans++;
  cout<<ans;
  
  return 0;
}