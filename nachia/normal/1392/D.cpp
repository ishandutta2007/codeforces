#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int X[200000];
int dp[200001][2][2];
bool ok[2][2][2];

int D(int x,int y){ return (x!=y)?1:0; }

void loop(){
 scanf("%d",&N);
 scanf(" "); rep(i,N){ char c; scanf("%c",&c); X[i] = (c=='R'); }
 int ans = 1000000;
 rep(s1,2)rep(s2,2){
  rep(i,N+1)rep(x,2)rep(y,2) dp[i][x][y]=1000000;
  dp[0][s1][s2] = 0;
  rep(i,N)rep(x,2)rep(y,2)rep(xx,2){
   if(!ok[x][y][xx]) continue;
   dp[i+1][y][xx] = min(dp[i+1][y][xx],dp[i][x][y]+D(X[i],xx));
  }
  ans = min(ans,dp[N][s1][s2]);
 }
 printf("%d\n",ans);
}

int main() {
 ok[0][0][0] = false;
 ok[0][0][1] = true;
 ok[0][1][0] = true;
 ok[0][1][1] = true;
 ok[1][0][0] = true;
 ok[1][0][1] = true;
 ok[1][1][0] = true;
 ok[1][1][1] = false;
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}