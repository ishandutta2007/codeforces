#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL N;
UL A[1000];
pair<UL,UL> X[1000];
vector<pair<UL,UL>> ans;
bool F[1000]={};

int main() {
 scanf("%u",&N);
 rep(i,N) scanf("%u",&A[i]);
 rep(i,N) X[i]={A[i],i};
 sort(X,X+N);
 rep(x,N){
  auto p=X[x].second;
  for(UL i=N-1; i!=p; i--){
   if(F[i]) ans.push_back({p,i});
  }
  F[p]=true;
 }
 printf("%u\n",ans.size());
 for(auto p : ans)
  printf("%u %u\n", p.first+1,p.second+1);
 return 0;
}