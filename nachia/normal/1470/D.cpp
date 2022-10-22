
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


int N,M;
vector<vector<int>> E;

void testcase(){
  cin >> N >> M;
  E.assign(N,vector<int>());
  rep(i,M){
    int u,v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  vector<int> I = {0};
  vector<int> F(N,0);
  F[0] = 1;
  rep(i,I.size()){
    int p = I[i];
    for(int e : E[p]) if(F[e] == 0){
      F[e] = 1;
      I.push_back(e);
    }
  }

  if(I.size() != N){
    cout << "NO\n";
    return;
  }

  F.assign(N,0);
  vector<int> ans;
  for(int p : I) if(F[p] == 0){
    ans.push_back(p);
    for(int e : E[p]) F[e] = 1;
  }
  
  sort(ans.begin(),ans.end());

  cout << "YES\n";
  cout << ans.size() << "\n";
  rep(i,ans.size()){
    if(i != 0) cout << " ";
    cout << (ans[i] + 1);
  }
  cout << "\n";
}

int main(){
  int T; cin >> T; while(T--)
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;