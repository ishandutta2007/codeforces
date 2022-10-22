
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
vector<pair<int,int>> A;

int main(){
  scanf("%d",&N);
  A.resize(N);
  rep(i,N){ int a; scanf("%d",&a); A[i]={a,i+1}; }

  sort(A.begin(),A.end());

  if(N>=5000){
    priority_queue<pair<int,pair<int,int>>> Q;
    rep(i,2500) Q.push({
      A[i*2+1].first-A[i*2].first,
      { A[i*2].second, A[i*2+1].second }
    });
    while(Q.size()){
      int d = Q.top().first;
      pair<int,int> a1 = Q.top().second;
      Q.pop();
      if(Q.top().first!=d) continue;
      pair<int,int> a2 = Q.top().second;
      printf("YES\n");
      printf("%d %d %d %d\n",a1.first,a2.second,a1.second,a2.first);
      return 0;
    }
    printf("ERROR\n"); return 0;
  }

  vector<pair<int,int>> G;
  G.assign(2500000,make_pair(-1,-1));
  pair<int,int> ansA=make_pair(-1,-1), ansB=make_pair(-1,-1);

  rep(i,N){
    for(int j=i+1; j<N; j++){
      int d=A[j].first-A[i].first;
      if(G[d].first!=-1){ ansA=G[d]; ansB={A[j].second,A[i].second}; }
    }
    for(int j=0; j<i; j++){
      int d=A[i].first-A[j].first;
      G[d] = {A[i].second,A[j].second};
    }
  }

  if(ansA.first==-1) printf("NO\n");
  else{
    printf("YES\n");
    printf("%d %d %d %d\n",ansA.first,ansB.second,ansA.second,ansB.first);
  }

  return 0;
}