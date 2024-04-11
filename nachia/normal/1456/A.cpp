#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void loop(){
  int N,P,K; cin>>N>>P>>K;
  int G[100000]; rep(i,N){ char c; cin>>c; G[i]=c-'0'; }
  int GS[200000]={}; for(int i=N-1; i>=0; i--) GS[i]=GS[i+K]+(1-G[i]);
  int X,Y; cin>>X>>Y;
  int ans=100000000;
  for(int S=P-1; S<N; S++){
    ans=min(ans, (S-(P-1))*Y + GS[S]*X);
  }
  cout<<ans<<endl;
}

int main(){
  int T; cin>>T;
  while(T--) loop();
  return 0;
}