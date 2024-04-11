#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
const int SQ = 400;
const int N = 1000005;

int sz[N];
vector<int> adj[N];
int n;

ll dfs1(int v){
  ll w = 0;
  for(auto& x : adj[v]){
    w += dfs1(x);
    sz[v] += sz[x];
  }
  w += ++sz[v];
  return w;
}

ll res = 0;
int in[1000005];
bitset<500500> ok;

void dfs2(int v, ll w){
  int mx = n - sz[v];
  for(auto& x : adj[v])
    mx = max(mx, sz[x]);
  if(mx >= n / 2){
    res = max(res, w + 1LL * mx * (n - 1 - mx));
  } else {
    in[n - sz[v]] = 1;
    for(auto& x : adj[v])
      ++in[sz[x]];
    ok.set(0);
    for(int i = 1; i <= n / 2; i++){
      int t = (in[i] - 1) / 2;
      in[i] -= 2 * t;
      in[i << 1] += t;
      while(in[i]--)
        ok |= ok << i;
    }
    for(int i = n / 2; i >= 0; --i)
      if(ok[i]){
        res = max(res, w + 1LL * i * (n - 1 - i));
        break;
      }
  }
  for(auto& x : adj[v]){
    dfs2(x, w - sz[x] + n - sz[x]);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>n;

  for(int i = 2; i <= n; i++){
    int v;
    cin>>v;
    adj[v].push_back(i);
  }

  dfs2(1, dfs1(1));
  cout<<res;
}