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
int n, size;
int a[N], b[N];
pair<int, int> S[2*N];
priority_queue<pair<int, int> >Q;
priority_queue<pair<int, int> >Q2;
int ile[N];
vector<int>V[N], G[N];
int main()
{
  scanf("%d", &n);
  int mx = 0;
  int koszt = 0;
  for(int i=1; i<=n; i++)
  {
    scanf("%d%d", &a[i], &b[i]);
    koszt += b[i];
    mx = max(mx, a[i]);
    if(a[i] != 0)
    {
      V[a[i]].PB(b[i]);
    }  
  }
  int M = 0;
  for(int i=1; i<=mx; i++)
  {
    sort(V[i].begin(), V[i].end());
    if(M < V[i].size())
      M = V[i].size();
  }
  
  for(int i=1; i<=mx; i++)
  {
    for(int j=0; j<V[i].size(); j++)
    {
      G[M-V[i].size()+j+1].PB(V[i][j]);
    }
  }
  for(int i=1; i<=n; i++)
    sort(G[i].begin(), G[i].end());
  int wynik = koszt;
  int liczbaglosow = n;
  int last = n;
  for(int i=M; i>=1; i--)
  {
      int last = i;
      ile[i] = G[last].size()-1;
      for(int j=0; j<G[last].size(); j++)
    Q2.push(MP(G[last][j], last));
      while(liczbaglosow > M-i+2 && !Q2.empty())
      {
    int w = Q2.top().ff;
    int in = Q2.top().ss;
    Q2.pop();
    koszt -= w; 
    G[in].pop_back();   
    Q.push(MP(-w, in));
    liczbaglosow--; 
      }
      while(!Q.empty() && liczbaglosow < M-i+2)
      {
    int w = -Q.top().ff;
    int in = Q.top().ss;
    Q.pop();
    koszt += w;
    Q2.push(MP(w, in));
    G[in].PB(w);
    liczbaglosow++;
      }
      while(!Q2.empty() && !Q.empty() && Q2.top().ff > -Q.top().ff)
      {
    int w = -Q.top().ff;
    int in = Q.top().ss;
    int u = Q2.top().ff;
    int in2 = Q2.top().ss;
    Q2.pop();
    Q.pop();
    koszt += w;
    koszt -= u;
    G[in2].pop_back();  
    Q.push(MP(-u, in2));
    G[in].PB(w);
    Q2.push(MP(w, in));
      }      
      wynik = min(wynik, koszt);    
  }
  
  printf("%d", wynik);
  return 0;
}