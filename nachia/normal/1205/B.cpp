#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)



int main(){
  int N;
  vector<ull> A;
  cin >> N;
  rep(i,N){
    ull a; cin >> a;
    if(a == 0){ i--; N--; }
    else{ A.push_back(a); }
  }
  vector<vector<ull>> E(N);
  for(ull d=1ull<<59; d!=0; d>>=1){
    vector<int> I;
    rep(i,N) if(A[i]&d) I.push_back(i);
    if(I.size() >= 3){ cout << "3\n"; return 0; }
    if(I.size() == 2){
      E[I[1]].push_back(I[0]);
      E[I[0]].push_back(I[1]);
    }
  }
  int ans = 100000;
  rep(s,N){
    vector<int> D(N,-1);
    vector<int> P(N,-1);
    D[s] = 0;
    vector<int> I = {s};
    rep(i,I.size()){
      int p = I[i];
      for(int e : E[p]) if(P[p] != e) if(P[e] != p){
        if(D[e] == -1){
          I.push_back(e);
          D[e] = D[p] + 1;
          P[e] = p;
        }
        else if(P[p] != e){
          ans = min(ans,D[e]+D[p]+1);
        }
      }
    }
  }
  if(ans == 100000) cout << "-1\n";
  else cout << ans << "\n";
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;