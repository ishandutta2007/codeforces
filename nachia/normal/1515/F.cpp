#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct DSU{
  vector<int> V;
  DSU(int n=0){ V.assign(n,-1); }
  int leader(int a){ if(V[a] < 0) return a; return V[a] = leader(V[a]); }
  void merge(int r,int c){ r=leader(r); c=leader(c); if(r != c) V[c] = r; }
};

//template<class T> using nega_queue = priority_queue<T,vector<T>,greater<T>>;

struct Edge{ int to; int id; };

void testcase(){
  int N,M; cin>>N>>M;
  ll X; cin>>X;
  vector<ll> A(N); for(int i=0; i<N; i++) cin>>A[i];
  ll S=0; for(int i=0; i<N; i++) S+=A[i];
  if(S < X*(N-1)){ cout<<"NO\n"; return; }

  vector<vector<Edge>> E(N);
  for(int i=0; i<M; i++){
    int u,v; cin>>u>>v; u--; v--;
    E[u].push_back({v,i});
    E[v].push_back({u,i});
  }

  DSU dsu(N);

  priority_queue<pair<ll,int>> Q;
  vector<int> ans;
  for(int i=0; i<N; i++) Q.push({A[i],i});

  int dsucnt = N;
  while(dsucnt > 1){
    auto q = Q.top(); Q.pop();
    int u = q.second;
    if(u != dsu.leader(u)) continue;
    if(A[u] != q.first) continue;
    int ei = -1, v = -1;
    while(true){
      Edge e = E[u].back();
      if(dsu.leader(e.to) == dsu.leader(u)){ E[u].pop_back(); continue; }
      ei = e.id; v = dsu.leader(e.to);
      break;
    }
    ans.push_back(ei);
    if(E[u].size() < E[v].size()) swap(u,v);
    for(auto e : E[v]) E[u].push_back(e);
    A[u] = A[u] + A[v] - X;
    Q.push(make_pair(A[u],u));
    dsu.merge(u,v);
    dsucnt--;
  }

  cout<<"YES\n";
  for(int i=0; i<N-1; i++) cout<<(ans[i]+1)<<"\n";
}

int main(){
  int T; //cin>>T;
  T=1;
  while(T--) testcase();
  return 0;
}



struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;