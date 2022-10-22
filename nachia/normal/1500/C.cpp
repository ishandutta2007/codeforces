
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int H,W;
vector<vector<int>> A,B;

vector<int> F_Row;
vector<int> C_Col;
vector<int> Ord;

int main(){
  scanf("%d%d",&H,&W);
  A.assign(H,vector<int>(W));
  rep(y,H) rep(x,W) scanf("%d",&A[y][x]);
  B.assign(H,vector<int>(W));
  rep(y,H) rep(x,W) scanf("%d",&B[y][x]);

  F_Row.assign(H-1,1);
  C_Col.assign(W,0);
  rep(y,H-1) rep(x,W) if(B[y][x]>B[y+1][x]) C_Col[x]++;

  queue<int> Q;
  rep(x,W) if(C_Col[x]==0) Q.push(x);
  while(Q.size()){
    int px=Q.front(); Q.pop();
    Ord.push_back(px);
    rep(y,H-1) if(B[y][px]<B[y+1][px]) if(F_Row[y]){
      rep(x,W) if(B[y][x]>B[y+1][x]) if((--C_Col[x])==0) Q.push(x);
      F_Row[y]=0;
    }
  }

  reverse(Ord.begin(),Ord.end());

  vector<pair<pair<int,int>,int>> P(H);
  rep(y,H) P[y].second=y;
  for(int x:Ord){
    rep(i,H) P[i].first = { A[P[i].second][x],i };
    sort(P.begin(),P.end());
  }

  rep(i,H) rep(x,W){
    int y=P[i].second;
    if(A[y][x]!=B[i][x]){ printf("-1\n"); return 0; }
  }

  printf("%d\n",(int)Ord.size());
  rep(i,Ord.size()){
    if(i) printf(" ");
    printf("%d",Ord[i]+1);
  } printf("\n");
  return 0;
}