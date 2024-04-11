#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void testcase(){
  int N; cin>>N;
  vector<pair<int,int>> mem_lines;
  vector<pair<int,int>> mem_rem;
  vector<vector<int>> E(N);
  rep(i,N-1){
    int u,v; cin>>u>>v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> P(N,-1);
  vector<int> Q = {0};
  {
    int pQ = 0;
    while(Q.size() != pQ){
      int p = Q[pQ++];
      for(int e : E[p]) if(P[p] != e){
        P[e] = p;
        Q.push_back(e);
      }
    }
  }
  vector<int> I(N,0);
  vector<int> F(N,0);
  vector<int> leaf(N,0); rep(i,N) leaf[i] = i;
  for(int i : P) if(i != -1) I[i]++;
  for(int iQ=Q.size()-1; iQ>=0; iQ--){
    int p = Q[iQ];
    if(I[p] <= 1){
      if(P[p] != -1){
        leaf[P[p]] = leaf[p];
      }
      else{
        mem_lines.push_back({p,leaf[p]});
      }
    }
    else{
      vector<int> Ep;
      for(int e : E[p]) if(P[p] != e) if(F[e] == 0) Ep.push_back(e);
      for(int i=2; i<Ep.size(); i++){
        int e = Ep[i];
        mem_rem.push_back({p,e});
        mem_lines.push_back({leaf[e],e});
      }
      if(P[p] != -1){
        I[P[p]]--;
        mem_rem.push_back({p,P[p]});
        F[p] = 1;
      }
      mem_lines.push_back({leaf[Ep[0]],leaf[Ep[1]]});
    }
  }

  if(mem_rem.size()+1 != mem_lines.size()){ cout<<"ERROR"<<endl; return; }

  cout << (mem_rem.size()) << "\n";
  for(int i=0; i<mem_rem.size(); i++){
    cout << (mem_rem[i].first+1) << " " << (mem_rem[i].second+1) << " ";
    cout << (mem_lines[i].first+1) << " " << (mem_lines[i+1].second+1) << "\n";
  }
}

int main(){
  int T; cin>>T;
  while(T--) testcase();
  return 0;
}




struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;