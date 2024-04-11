#include <bits/stdc++.h>

#define int long long
using namespace std;
vector < int > adj[100005];
int have[100005], ax[100005], n, cac[100005];
int ans = 0;

int lcm(int cut, int buoi)
{
  if(cut==0) return buoi;
  if(buoi==0) return cut;
  return cut*buoi/__gcd(cut, buoi);
}

void dfs(int node, int fa) {
  int ono = 0;
  if(node!=1&&adj[node].size()==1)
  {
    cac[node]=1;
    have[node]++;
  }
  for (auto i: adj[node]) {
    if (i != fa) {
      dfs(i, node);
    	have[node]+=have[i];
      ono=lcm(ono, cac[i]);
      // } ono = max(ono, 1ll) / lol * have[i];
      // if(node==7) cout<<ono<<endl;
      if (ono > 100000000000000)
      {
        cout<<ans;
        exit(0);
      }
    }
  }
  // cout<<node<<" "<<ono<<endl;
  if(ono==0) return;
  else {
    ax[node] = 10000000000000;
    for (auto i: adj[node])
      if (i != fa) 
      	{
          ax[node] = min(ax[node], ax[i] - ax[i] % ono);
      	}
  }
  if (node == fa) ax[node] *= adj[node].size(), cac[node]=ono*adj[node].size();
  else ax[node] *= (adj[node].size() - 1), cac[node]=ono*(adj[node].size()-1);
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ax[i];
    ans += ax[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  // return 0;
  // for(int i=1; i<=n; i++)
  // {
  // 	cout<<ax[i]<<" ";
  // }
  cout << ans - ax[1];
}