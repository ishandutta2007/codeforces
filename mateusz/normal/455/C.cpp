#include <iostream>
#include <map>
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
const int N = 300005;
int n, m, q;
bool odw[N];
int rep[N];
int glebokosc[N], srednica[N];
vector<int> V[N];
void DFS(int w, int r)
{
  odw[w] = 1;
  rep[w] = r;
  int second_best = 0;
  for(int i=0; i<V[w].size(); i++)
  {
    int u = V[w][i];
    if(!odw[u])
    {
      DFS(u, r);
      int x = glebokosc[u]+1;
      srednica[w] = max(srednica[w], srednica[u]);
      if(x > glebokosc[w])
      {
    swap(x, glebokosc[w]);
      }
      if(x > second_best)
    second_best = x;
    }
  }
  srednica[w] = max(srednica[w], glebokosc[w] + second_best);
}
int find(int w)
{
  return rep[w] = (w == rep[w]? w: find(rep[w]));
}
void merge(int a, int b)
{
  a = find(a);
  b = find(b);
  if(a == b)return;
  int l = srednica[a]/2;
  if(srednica[a] % 2 == 1)l++;
  int l2 = srednica[b]/2;
  if(srednica[b] % 2 == 1)l2++;
    srednica[a] = max(l+l2+1, max(srednica[a], srednica[b]));    
  rep[b] = a;
}
int main()
{
  scanf("%d%d%d", &n, &m, &q);
  int a, b, co, x;
  for(int i=1; i<=m; i++)
  {
    scanf("%d%d", &a, &b);
    V[a].PB(b);
    V[b].PB(a);
  }
  
  for(int i=1; i<=n; i++)
  {
    if(!odw[i])
    {
      DFS(i, i);
    }
  }
  
  for(int i=1; i<=q; i++)
  {
    scanf("%d", &co);
    if(co == 1)
    {
      scanf("%d", &x);
      printf("%d\n", srednica[find(x)]);
    }
    else
    {
      scanf("%d%d", &a, &b);
      merge(a, b);
    }
  }
  
  return 0;
}