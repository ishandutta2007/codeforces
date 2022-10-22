#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop(){
 string S; cin>>S;
 int x; cin>>x;
 int N=S.size();
 string W; W.resize(N,'1');
 rep(i,N){
  if(S[i]=='0'){
   if(i-x>=0) W[i-x]='0';
   if(i+x<N) W[i+x]='0';
  }
 }
 bool validW = true;
 rep(i,N){
  if(S[i]=='1'){
   bool ok=false;
   if(i-x>=0) if(W[i-x]=='1') ok=true;
   if(i+x<N) if(W[i+x]=='1') ok=true;
   validW = validW && ok;
  }
 }
 if(validW) cout<<W<<endl;
 else cout<<-1<<endl;
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}