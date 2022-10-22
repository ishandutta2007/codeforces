#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int X[100000];

void loop(){
  cin>>N;
  rep(i,N) cin>>X[i];
  X[N-1]++;
  for(int i=N-1; i>=1; i--) if(X[i-1]+1<X[i]) X[i-1]++;
  int ans=N;
  rep(i,N-1) if(X[i]==X[i+1]) ans--;
  cout<<ans<<endl;
}

int main(){
	int T; cin>>T;
  while(T--) loop();
	return 0;
}