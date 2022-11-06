#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N = 300005;
int a, b, n;
bool odw[N];
int pod[N], prz[N], mid[N];
vector<int>V[N];
LL dp[N];
int q;
int ans[N];

void DFS(int w)
{
  odw[w] = 1;
  pod[w] = 1;
  for(int i = 0; i < V[w].size(); i++)
  {
    int u = V[w][i];
    if(!odw[u])
    {
      prz[u] = w;
      DFS(u);
      pod[w] += pod[u];
    }
  }
  if(pod[w] == 1)
  {
    mid[w] = w;
    ans[w] = w;
    return;
  }

  for(int i=0; i<V[w].size(); i++)
  {
    int u = V[w][i];
    if(prz[w] == u) continue;
    while(pod[mid[u]] < pod[w] - pod[mid[w]])
    {
      if((LL)pod[mid[u]] * (pod[w] - pod[mid[u]]) > dp[w])
      {
        dp[w] = (LL)pod[mid[u]] * (pod[w] - pod[mid[u]]);
        mid[w] = mid[u];
      }
      mid[u] = prz[mid[u]];
    }
    if((LL)pod[mid[u]] * (pod[w] - pod[mid[u]]) > dp[w])
    {
      dp[w] = (LL)pod[mid[u]] * (pod[w] - pod[mid[u]]);
      mid[w] = mid[u];
    }
  }
  ans[w] = pod[mid[w]] >= (pod[w] - pod[mid[w]]) ? mid[w] : prz[mid[w]];
}

int main() {

    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &a);
        V[a].push_back(i);
    }

    DFS(1);

    while (q--) {
        scanf("%d", &a);
        printf("%d\n", ans[a]);
    }

    return 0;
}