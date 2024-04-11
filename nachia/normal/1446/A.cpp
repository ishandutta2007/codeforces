
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop(){
  int N; LL W; cin>>N>>W;
  vector<pair<LL,int>> A(N); rep(i,N){ int a; cin>>a; A[i]={a,i+1}; }
  sort(A.begin(),A.end());
  LL S=0; rep(i,N) S+=A[i].first;
  while(true){
    if((W+1)/2 > S) break;
    if(S<=W){
      cout<<A.size()<<endl;
      rep(i,A.size()){ if(i) cout<<" "; cout<<A[i].second; } cout<<endl;
      return;
    }
    if((W+1)/2 <= A.back().first && A.back().first <= W){
      cout<<1<<endl;
      cout<<A.back().second<<endl;
      return;
    }
    S-=A.back().first;
    A.pop_back();
  }
  cout<<-1<<endl;
}

int main() {
  int t; cin>>t;
  while(t--) loop();
  return 0;
}