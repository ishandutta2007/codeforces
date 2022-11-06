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
const int INF = 1e9 + 5;
int tab[N];
int n;
bool isSorted(int *t)
{
  for(int i=2; i<=n; i++)
    if(t[i] < t[i-1])return 0;
  return 1;
}

pair<int, int> change(int *t)
{
  int start = -1;
  int koniec = -1;
  for(int i=2; i<=n+1; i++)
  {
    if(start == -1 && t[i] < t[i-1])
      start = i-1;
    if(start != -1 && tab[i] >= tab[i-1])
    {
      koniec = i-1;
      break;
    }
  }
  if(start == -1 || koniec == -1)return MP(-1, -1);
  reverse(t+start, t+koniec+1);
  if(isSorted(t))return MP(start, koniec);
  return MP(-1, -1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n;
  for(int i=1; i<=n; i++)cin>>tab[i];
  tab[n+1] = INF;
  if(isSorted(tab))
    cout<<"yes\n1 1";
  else
  {
    pair<int, int>ans = change(tab);
    if(ans == MP(-1, -1))
      cout<<"no";
    else
      cout<<"yes\n"<<ans.ff<<" "<<ans.ss;    
  }
  return 0;
}