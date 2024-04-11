#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int P[200000];
vector<vector<int>> R;
vector<pair<int,int>> ans;

int main(){
  scanf("%d",&N);
  rep(i,N){ scanf("%d",&P[i]); P[i]--; }
  rep(i,N){
    if(P[i]!=-1) R.push_back({});
    int p=i; while(P[p]!=-1){ int to=P[p]; R.back().push_back(p); P[p]=-1; p=to; }
  }
  while(R.size()>=2){
    auto C1=move(R.back()); R.pop_back();
    auto C2=move(R.back()); R.pop_back();
    ans.push_back({C1.back(),C2.back()});
    rep(i,C2.size()-1) ans.push_back({C1.back(),C2[i]});
    rep(i,C1.size()-1) ans.push_back({C2.back(),C1[i]});
    ans.push_back({C1.back(),C2.back()});
  }
  if(R.size()==1){
    auto C=move(R.back()); R.pop_back();
    reverse(C.begin(),C.end());
    if(C.size()>=3){
      ans.push_back({C[0],C[2]});
      ans.push_back({C[1],C[2]});
      ans.push_back({C[0],C[1]});
      for(int i=C.size()-1; i>=2; i--) ans.push_back({C[0],C[i]});
    }
    if(C.size()==2){
      int t=-1; rep(i,N) if(i!=C[0] && i!=C[1]) t=i;
      ans.push_back({C[0],t});
      ans.push_back({C[1],t});
      ans.push_back({C[0],t});
    }
  }

  printf("%d\n",(int)ans.size());
  for(auto p:ans) printf("%d %d\n",p.first+1,p.second+1);
  return 0;
}