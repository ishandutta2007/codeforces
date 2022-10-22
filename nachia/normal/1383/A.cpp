#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

int N;
string A,B;

void loop(){
 cin>>N>>A>>B;
 rep(i,N) if(A[i]>B[i]){ cout<<-1<<endl; return; }
 int X[20]; rep(i,20)X[i]=i;
 int ans=0;
 rep(i,N){
  if(A[i]!=B[i]) if(X[A[i]-'a'] != X[B[i]-'a']){
   ans++;
   int tg=X[A[i]-'a'];
   rep(j,20) if(X[j]==tg) X[j]=X[B[i]-'a'];
  }
 }
 cout<<ans<<endl;
}

int main() {
 int t; cin>>t;
 rep(tt,t) loop();
 return 0;
}