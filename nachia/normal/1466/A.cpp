#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[100];

void loop(){
  cin>>N;
  rep(i,N) cin>>A[i];
  set<int> S;
  rep(r,N) rep(l,r) S.insert(A[r]-A[l]);
  cout<<S.size()<<endl;
}

int main(){
	int T; cin>>T;
  while(T--) loop();
	return 0;
}