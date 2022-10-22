#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int W[50];
int C[100];

void loop(){
 scanf("%d",&N);
 rep(i,50) W[i]=0;
 rep(i,N){ int w; scanf("%d",&w); W[w-1]++; }
 rep(i,100) C[i]=0;
 rep(i,50) rep(j,i+1){
  if(i==j) C[i+j] += W[i]/2;
  else C[i+j] += min(W[i],W[j]);
 }
 int ans=0;
 rep(i,100) ans=max(ans,C[i]);
 printf("%d\n",ans);
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}