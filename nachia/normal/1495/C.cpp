#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int H,W;
char G[500][500];

void testcase(){
  scanf("%d%d",&H,&W);
  rep(y,H){ scanf(" "); rep(x,W) scanf("%c",&G[y][x]); }
  if(H%3==0){
    for(int y=1; y<H; y+=3){ rep(x,W) G[y][x]='X'; }
    for(int y=1; y<H-3; y+=3){
      int p=0;
      rep(x,W){ if(G[y+1][x]=='X' || G[y+2][x]=='X') p=x; }
      G[y+1][p]=G[y+2][p]='X';
    }
  }
  else{
    for(int y=0; y<H; y+=3){ rep(x,W) G[y][x]='X'; }
    for(int y=0; y<H-3; y+=3){
      int p=0;
      rep(x,W){ if(G[y+1][x]=='X' || G[y+2][x]=='X') p=x; }
      G[y+1][p]=G[y+2][p]='X';
    }
  }
  rep(y,H){ rep(x,W) printf("%c",G[y][x]); printf("\n"); }
}

int main(){
  int T; scanf("%d",&T);
  while(T--) testcase();
  return 0;
}