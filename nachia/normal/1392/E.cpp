#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL G[25][25];

LL UB(int x,int y){
 LL ans = 0;
 rep(xx,x) ans += G[xx][y];
 rep(yy,y) ans += G[0][yy];
 return ans;
}
LL LB(int x,int y){
 LL ans = 0;
 rep(xx,x) ans += G[xx][0];
 rep(yy,y) ans += G[x][yy];
 return ans;
}

void loop(){
 LL K; scanf("%lld",&K);
 int x,y; x=y=N-1;
 printf("1 1\n"); fflush(stdout);
 while(x+y>0){
  if(x==0){ y--; }
  else if(y==0){ x--; }
  else{
   if(UB(x,y-1)+G[x][y-1] < K){ x--; }
   else y--;
  }
  K -= G[x][y];
  printf("%d %d\n",N-x,N-y); fflush(stdout);
 }
}

int main() {
 scanf("%d",&N);
 rep(x,N)rep(y,N) G[x][y]=0;
 for(int y=1; y<N; y++){
  for(int x=0; x<N-1; x++){
   G[x][y] = 1+UB(x+1,y-1)+G[x+1][y-1]-LB(x,y);
  }
 }
 rep(x,N){ rep(y,N){ if(y) printf(" "); printf("%lld",G[N-1-x][N-1-y]); }  printf("\n"); }
 fflush(stdout);

 int T; scanf("%d",&T);
 while(T--){ loop(); }

 return 0;
}