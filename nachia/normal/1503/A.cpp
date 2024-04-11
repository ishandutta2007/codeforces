

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
string S;

void testcase(){
  scanf("%d",&N);
  S.resize(N); scanf("%s",S.data());
  if(S.front()=='0' || S.back()=='0'){ printf("NO\n"); return; }
  vector<int> C1;
  rep(i,N) if(S[i]=='1') C1.push_back(i);
  if(C1.size()%2==1){ printf("NO\n"); return; }
  string ans[2];
  rep(t,2) ans[t].resize(N);
  int sw=0;
  rep(t,2) ans[t][0] = '(';
  for(int i=1; i<N-1; i++){
    if(S[i]=='0'){
      ans[0^sw][i] = '(';
      ans[1^sw][i] = ')';
      sw^=1;
    }
  }
  for(int ic=0; ic<C1.size()/2; ic++){
    rep(t,2) ans[t][C1[ic]] = '(';
    rep(t,2) ans[t][C1[C1.size()-1-ic]] = ')';
  }
  rep(t,2) ans[t][N-1] = ')';
  printf("YES\n%s\n%s\n",ans[0].c_str(),ans[1].c_str());
}

int main(){
  int T; scanf("%d",&T);
  while(T--) testcase();
  return 0;
}