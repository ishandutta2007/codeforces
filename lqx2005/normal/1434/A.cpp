#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N = 1e5 + 10;
int san[N * 6], a[6], b[N], tot = 0, n;
struct node
{
  int x, y;
  friend bool operator < (const node p, const node q)
  {
    return b[p.x] - a[p.y] < b[q.x] - a[q.y];
  }
};
int value(node v)
{
  return b[v.x] - a[v.y];
}

multiset<node> s;
int main()
{
  for(int i = 0; i <= 5; i++) scanf("%d", &a[i]);
  sort(a, a + 6);
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &b[i]);
    for(int j = 0; j <= 5; j++) san[++tot] = b[i] - a[j];
  }
  sort(san + 1, san + tot + 1);
  tot = unique(san + 1, san + tot + 1) - (san + 1);
  for(int i = 1; i <= n; i++) s.insert(node{i, 5});
  int flag = 0, ans = san[tot] - san[1];
  for(int i = 1; i <= tot; i++)
  {
    while(!s.empty() && value(*(s.begin())) < san[i]) 
    {
      node v = (*s.begin());
      s.erase(s.begin());
      if(v.y == 0)
      {
        flag = 1;
        break;
      }
      else
      {
        v.y--;
        s.insert(v);
      }
    }
    if(flag) break;
    ans = min(ans, value(*(--s.end())) - san[i]);
  }
  printf("%d\n", ans);
  return 0;
}