#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,M;
vector<vector<int>> E;
int D[400][400];
int G[400][400]={};
ull X[400][400];

int main(){
  scanf("%d%d",&N,&M);
  E.resize(N);
  rep(i,M){
    int u,v; scanf("%d%d",&u,&v); u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  rep(s,N){
    rep(i,N) D[s][i]=-1;
    queue<int> Q;
    D[s][s]=0; Q.push(s);
    while(Q.size()){
      int p=Q.front(); Q.pop();
      for(int e:E[p]) if(D[s][e]==-1){
        D[s][e]=D[s][p]+1;
        Q.push(e);
      }
    }
  }
  rep(x,N){
    rep(y,x+1){
      ull ans=1;
      rep(i,N) G[D[x][i]][D[y][i]]++;
      for(int d=0; d<=D[x][y]; d++) if(G[d][D[x][y]-d]!=1) ans=0;
      rep(i,N) G[D[x][i]][D[y][i]]--;
      if(ans==0) continue;
      rep(i,N){
        int dx=D[x][i], dy=D[y][i];
        if(dx+dy>D[x][y]){
          int c=0; for(int e:E[i]) if(D[x][e]==dx-1 && D[y][e]==dy-1) c++;
          ans=ans*c%998244353;
        }
      }
      X[x][y]=X[y][x]=ans;
    }
  }
  
  rep(x,N){
    rep(y,N){ if(y) printf(" "); printf("%u",(unsigned int)X[x][y]); }
    printf("\n");
  }
  return 0;
}