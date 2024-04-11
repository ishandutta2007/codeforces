#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
  int n; cin >> n;
  vector<vector<int>> E(n);
  rep(i,n-1){
    int u,v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> P(n,-1);
  vector<int> I = {0};
  rep(i,I.size()){
    int p = I[i];
    for(int e : E[p]) if(e != P[p]){
      P[e] = p;
      I.push_back(e);
    }
  }

  
  vector<int> isLeaf(n,1);
  vector<int> isBud(n,0);

  auto dfs = [&](int p, auto dfs)->void{
    for(int e : E[p]) if(e != P[p]){
      dfs(e, dfs);
      isLeaf[p] = 0;
      if(isBud[e] == 0) isBud[p] = 1;
    }
  };
  dfs(0,dfs);

  int leafCnt = 0;
  for(int a : isLeaf) leafCnt += a;
  rep(p,n){
    int budChild = 0;
    for(int e : E[p]) if(e != P[p]) budChild += isBud[e];
    if(budChild == 0) continue;
    if(isBud[p]) leafCnt -= budChild;
    else leafCnt -= budChild-1;
  }
  cout << leafCnt << "\n";
}


int main(){
  int T; cin >> T;
  rep(t,T) testcase();
  return 0;
}




struct ios_do_not_sync {
    ios_do_not_sync() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} ios_do_not_sync_instance;