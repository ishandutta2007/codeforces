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
int n, m, tab1[N], tab2[N];
LL s1, s2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
  {cin>>tab1[i]; s1 += tab1[i];}
  for(int i=1; i<=m; i++)
  {cin>>tab2[i]; s2 += tab2[i];}
  sort(tab1+1, tab1+1+n);
  sort(tab2+1, tab2+1+m);
  
  int wsk1 = 1;
  int wsk2 = 1;
  LL wynik = 0;
  
  while(wsk1 <= n && wsk2 <= m)
  {
    if(tab1[wsk1] <= tab2[wsk2])
    {
      wynik += tab1[wsk1];
      wsk1++;
    }
    else
    {
      wynik += tab2[wsk2];
      wsk2++;
    }
  }
  while(wsk1 < n)
  {
    wynik += min(s2, (LL)tab1[wsk1]);
    wsk1++;
  }
  while(wsk2 < m)
  {
    wynik += min(s1, (LL)tab2[wsk2]);
    wsk2++;
  }
  cout<<wynik;
  return 0;
}