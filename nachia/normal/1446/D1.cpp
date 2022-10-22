#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
vector<int> A;
vector<int> posMx;

int main(){
  cin>>N;
  A.resize(N); rep(i,N){ cin>>A[i]; A[i]--; }
  vector<vector<int>> posV(N);
  rep(i,N) posV[A[i]].push_back(i);
  int mx=0; rep(i,N) if(posV[i].size()>posV[mx].size()) mx=i;
  rep(i,N) if(mx!=i) if(posV[i].size()==posV[mx].size()){ cout<<N<<endl; return 0; }

  int ans=0;
  rep(v,min(100,N)){
    if(v==mx) continue;
    vector<int> p(N*2,N);
    int vcnt=N;
    p[vcnt]=0;
  
    rep(i,N){
      ans=max(ans,i-p[vcnt]);
      if(A[i]==mx){
        vcnt--;
      }
      if(A[i]==v){
        vcnt++;
      }
      p[vcnt]=min(p[vcnt],i+1);
    }
    ans=max(ans,N-p[vcnt]);
  }

  cout<<ans<<endl;

  return 0;
}