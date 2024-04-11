
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct Query{ int d; int i,j; };
bool operator<(Query l,Query r){ return l.d<r.d; }

int N;
vector<int> K;
vector<Query> Q;

int main(){
  scanf("%d",&N);
  K.resize(N);
  rep(i,N) scanf("%d",&K[i]);
  rep(i,N) rep(j,N) if(make_pair(K[i]-K[j],i-j) > make_pair(0,0)) Q.push_back({-(K[i]-K[j]),i,j});
  sort(Q.begin(),Q.end());
  for(Query q:Q){
    printf("? %d %d\n",q.i+1,q.j+1); fflush(stdout);
    char X[4]; scanf("%s",X);
    if(strcmp(X,"Yes")==0){
      printf("! %d %d\n",q.i+1,q.j+1); fflush(stdout);
      return 0;
    }
  }
  printf("! 0 0\n"); fflush(stdout);
  return 0;
}