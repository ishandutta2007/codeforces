#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,M;
vector<int> E[100000];

int Z[100000];
int P[100000];
int cdP[100000];
int cdD[100000][18]={};
int cdDep[100000];

int F[100000];

void DFS(int p){
 Z[p]=1;
 for(int e:E[p]){
  if(P[p]==e) continue;
  P[e] = p;
  DFS(e);
  Z[p] += Z[e];
 }
}
void DFS2(int p,int dep=0){
 for(int e:E[p]){
  if(Z[e]>Z[p]) continue;
  if(Z[e]==0) continue;
  cdD[e][dep] = cdD[p][dep]+1;
  DFS2(e,dep);
 }
}
void cdDFS(int p,int pre=-1,int dep=0){
 int d=1;
 while(true){
  bool nx=false;
  for(int e:E[p])
   if(Z[p]/2 < Z[e]){
    swap(Z[p],Z[e]);
    Z[p] = Z[e]-Z[p];
    p=e;
    nx=true;
   }
  if(!nx) break;
  d++;
 }
 cdDep[p]=dep;
 cdD[p][dep]=0; DFS2(p,dep);
 cdP[p]=pre;
 Z[p]=0;
 for(int e:E[p]) if(Z[e]!=0) cdDFS(e,p,dep+1);
}

void cdInit(){
 rep(i,N) Z[i]=P[i]=-1;
 DFS(0);
 cdDFS(0);
 rep(i,N) F[i]=10000000;
}

void red(int p){
 F[p]=0;
 int pp=p, dep=cdDep[p];
 while(cdP[pp]!=-1){
  F[cdP[pp]] = min(F[cdP[pp]],F[p]+cdD[p][dep-1]);
  pp = cdP[pp]; dep--;
 }
}
int query(int p){
 int ans=10000000;
 int pp=p, dep=cdDep[p];
 while(pp!=-1){
  ans=min(ans,cdD[p][dep]+F[pp]);
  pp=cdP[pp]; dep--;
 }
 return ans;
}

int main() {
 scanf("%d%d",&N,&M);
 rep(i,N-1){
  int u,v; scanf("%d%d",&u,&v); u--; v--;
  E[u].push_back(v);
  E[v].push_back(u);
 }
 cdInit();
 red(0);

 while(M--){
  int c,v; scanf("%d%d",&c,&v); v--;
  if(c==1) red(v);
  if(c==2) printf("%d\n",query(v));
 }

 return 0;
}