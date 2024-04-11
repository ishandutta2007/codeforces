#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
  int N;
  ll K;
  scanf("%d%lld",&N,&K);
  if(N<61) if(K>(1ll<<(N-1))){ printf("-1\n"); return; }
  vector<int> ans(N);
  rep(i,N) ans[i]=i+1;
  reverse(ans.begin(),ans.end());
  K--;
  while(K!=0){
    int pre = 1; while(K>=(1ll<<(pre-1))) pre++;
    for(int p=pre-1; p>=0; p--){
      if(p>0) if(K >= (1ll<<(p-1))){
        K -= (1ll<<(p-1));
        continue;
      }
      reverse(ans.begin()+p,ans.begin()+pre);
      break;
    }
  }
  reverse(ans.begin(),ans.end());
  rep(i,N){ if(i) printf(" "); printf("%d",ans[i]); } printf("\n");
}

int main(){
  int T; scanf("%d",&T);
  while(T--) testcase();
  return 0;
}