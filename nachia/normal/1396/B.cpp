#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[100];
int S;

int main(){
 int t; cin>>t;
 while(t--){
  S=0;
  cin>>N;
  rep(i,N) cin>>A[i];
  sort(A,A+N);
  rep(i,N) S+=A[i];
  if(S<A[N-1]*2 || S%2==1) printf("T\n");
  else printf("HL\n");
 }
  return 0;
}