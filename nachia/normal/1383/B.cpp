#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int X[30];

void loop(){
 int N; scanf("%d",&N);
 rep(d,30) X[d]=0;
 rep(i,N){
  int x; scanf("%d",&x);
  rep(d,30) X[d] += ((x>>d)&1);
 }
 for(int d=29; d>=0; d--){
  if(X[d]%2==1){
   if(N%2==1){
    if(X[d]/2%2==1) printf("LOSE\n");
    else printf("WIN\n");
   }
   else{
    printf("WIN\n");
   }
   return;
  }
 }
 printf("DRAW\n");
}

int main() {
 int t; cin>>t;
 rep(tt,t) loop();
 return 0;
}