#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

const ULL M=1000000007;

int N;
vector<int> E[100000];
int nP;
ULL P[60000];

int gP[100000];
int gZ[100000];
ULL Sc[99999];
ULL Ml[99999];

void dfs(int p=0){
 gZ[p]=1;
 for(int e:E[p]){
  if(gP[p]==e) continue;
  gP[e] = p;
  dfs(e);
  gZ[p] += gZ[e];
 }
}

void loop(){
 scanf("%d",&N);
 rep(i,N) E[i].clear();
 rep(i,N-1){
  int u,v; scanf("%d%d",&u,&v); u--; v--;
  E[u].push_back(v);
  E[v].push_back(u);
 }
 scanf("%d",&nP); rep(i,nP) scanf("%d",&P[i]);
 sort(P,P+nP); reverse(P,P+nP);

 rep(i,N) gP[i]=-1;
 dfs();
 rep(i,N-1) Sc[i] = ULL(gZ[i+1]) * (N-gZ[i+1]);
 sort(Sc,Sc+N-1); reverse(Sc,Sc+N-1);
 rep(i,N-1) Sc[i] = Sc[i] % M;
 rep(i,N-1) Ml[i]=1;
 if(nP<N-1) rep(i,nP) Ml[i]=P[i];
 else{
  rep(i,N-1) Ml[i] = P[nP-(N-1)+i];
  rep(i,nP-(N-1)) Ml[0] = Ml[0] * P[i] % M;
 }
 ULL ans = 0;
 rep(i,N-1) ans += Sc[i] * Ml[i] % M;

 ans %= M;
 printf("%llu\n",ans);
}

int main() {

 int T; scanf("%d",&T);
 while(T--){
  loop();
 }

 return 0;
}