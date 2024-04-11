#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100;
int n,ans;
vector<int> adj[N];
int del[N],nn;

int main() {
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b); --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  nn = n;
  while (true) {
    if (nn == 1) {
      REP(i,n) if (!del[i]) { ans = i; }
      break;
    }
    int a=-1,b=-1;
    REP(i,n) if (!del[i] && adj[i].size() == 1) a=i;
    REP(i,n) if (!del[i] && i != a && adj[i].size() == 1) b=i;
    printf("? %d %d\n",a+1,b+1);
    fflush(stdout);
    int c; scanf("%d",&c); --c;
    if (c == a || c == b) { ans = c; break; }

    int pa = adj[a][0], pb = adj[b][0];
    adj[pa].erase(find(adj[pa].begin(),adj[pa].end(), a));
    adj[pb].erase(find(adj[pb].begin(),adj[pb].end(), b));
    del[a] = del[b] = 1;
    nn -= 2;
  }

  printf("! %d\n",ans+1);
}