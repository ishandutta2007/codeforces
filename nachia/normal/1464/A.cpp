
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct DSU{
  vector<int> V;
  int sz = 0;
  DSU(int n=0){ V.assign(n,-1); sz = n; }
  int leader(int a){ if(V[a]<0) return a; return V[a] = leader(V[a]); }
  void merge(int a,int b){
    a = leader(a);
    b = leader(b);
    if(a != b){ V[a] = b; sz--; }
  }
};

void testcase(){
  int N, M; cin >> N >> M;
  DSU G(N);
  int ans = 0;
  rep(i,M){
    int x,y; cin >> x >> y; x--; y--;
    if(x != y){
      ans++;
      if(G.leader(x) == G.leader(y)) ans++;
    }
    G.merge(x,y);
  }
  cout << ans << "\n";
}

int main(){
  int T; cin >> T;
  while(T--) testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;