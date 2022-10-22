#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct cin_improve_speed{
  cin_improve_speed(){
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
  }
} cin_improve_speed_instance;

int N,K;

void loop(){
  cin>>N>>K;
  if(N%2==0) cout<<((K-1)%N+1)<<"\n";
  else cout<<(((K-1)/(N/2)+(K-1))%N+1)<<"\n";
}

int main(){
  int T; cin>>T;
  while(T--) loop();
  return 0;
}