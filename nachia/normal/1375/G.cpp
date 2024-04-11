#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL N;
vector<UL> E[200000];
UL B[200000]={};

int main() {
 scanf("%u",&N);
 rep(i,N-1){
  UL u,v; scanf("%u%u",&u,&v); u--;v--;
  E[u].push_back(v);
  E[v].push_back(u);
 }
 queue<UL> Q; Q.push(0); B[0]=1;
 while(Q.size()){
  UL p=Q.front(); Q.pop();
  for(UL e : E[p]){
   if(B[e]) continue;
   B[e]=3-B[p];
   Q.push(e);
  }
 }
 UL ans[3]={};
 rep(i,N){
  ans[B[i]]++;
 }
 printf("%u\n",min(ans[1],ans[2])-1);
 return 0;
}