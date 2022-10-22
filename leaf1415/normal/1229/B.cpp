#include <iostream>
#include <vector>
#include <map>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
llint x[100005];
vector<llint> G[100005];
map<llint, llint> mp[100005];

llint gcd(llint a, llint b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

llint ans = 0;
void dfs(llint v, llint p)
{
  for(auto it = mp[p].begin(); it != mp[p].end(); it++){
    mp[v][gcd(it->first, x[v])] += it->second;
  }
  mp[v][x[v]]++;
  for(auto it = mp[v].begin(); it != mp[v].end(); it++){
    ans += it->first%mod * it->second%mod, ans %= mod;
  }

  for(int i = 0; i < G[v].size(); i++){
    if(G[v][i] == p) continue;
    dfs(G[v][i], v);
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> x[i];
  llint u, v;
  for(int i = 1; i <= n-1; i++){
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(1, 0);
  cout << ans << endl;

  return 0;
}