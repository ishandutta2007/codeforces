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
int tab[105];
queue<int>Q;
int n, m;
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
  {
    cin>>tab[i];
    Q.push(i);
  }
  int last = 0;
  while(!Q.empty())
  {
    int w = Q.front();
    last = w;
    Q.pop();
    tab[w] -= m;
    if(tab[w] > 0)
      Q.push(w);
  }
  cout<<last;
  return 0;
}