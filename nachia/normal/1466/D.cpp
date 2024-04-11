#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int W[100000];
vector<int> E[100000];

void loop(){
  scanf("%d",&N);
  rep(i,N) scanf("%d",&W[i]);
  rep(i,N-1){
    int u,v; scanf("%d%d",&u,&v); u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  vector<int> A;
  rep(i,N) rep(j,E[i].size()-1) A.push_back(W[i]);
  sort(A.begin(),A.end(),greater<int>());
  LL ans=0; rep(i,N) ans+=W[i];
  printf("%lld",ans);
  rep(i,N-2){ ans+=A[i]; printf(" %lld",ans); }
  printf("\n");

  rep(i,N) E[i].clear();
}

int main(){
	int T; scanf("%d",&T);
  while(T--) loop();
	return 0;
}