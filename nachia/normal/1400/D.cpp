#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[3000];
int C[3001][3000];
int G[3000][3000];

void loop(){
 rep(i,N+1)rep(j,N) C[i][j]=0;
 rep(i,N+1)rep(j,N+1) G[i][j]=0;
 scanf("%d",&N);
 rep(i,N){ scanf("%d",&A[i]); A[i]--; }
 rep(i,N){
  rep(j,N)C[i+1][j]=C[i][j];
  C[i+1][A[i]]++;
 }
 rep(s,N) for(int t=s+2; t<N; t++){
  G[s][t] = G[s][t-1] + C[s][A[t-1]];
 }
 LL ans=0;
 rep(j,N)rep(l,N) if(A[j]==A[l]) ans+=G[j][l];
 printf("%lld\n",ans);
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}