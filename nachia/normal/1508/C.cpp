#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct DSU{
  vector<int> V;
  int cnt;
  DSU(int n=0){
    V.resize(n);
    rep(i,n) V[i]=i;
    cnt = n;
  }
  int leader(int a){
    if(V[a]==a) return a;
    return V[a] = leader(V[a]);
  }
  void merge(int u,int v){
    u = leader(u);
    v = leader(v);
    if(u==v) return;
    cnt--;
    V[u] = v;
  }
};

struct Edge{ int to; ll w; };
struct Edge2{ int u,v; ll w; };
bool sort_Edge2_by_cost(Edge2 l,Edge2 r){ return l.w < r.w; }

int N, M;
vector<vector<Edge>> E;
vector<Edge2> J;
set<pair<int,int>> ES;
int allxor;

DSU dsu;

int main(){
  scanf("%d%d",&N,&M);
  E.resize(N);
  allxor = 0;
  rep(i,M){
    int u,v,w; scanf("%d%d%d",&u,&v,&w); u--; v--;
    E[u].push_back({v,w});
    E[v].push_back({u,w});
    ES.insert({u,v});
    ES.insert({v,u});
    J.push_back({min(u,v),max(u,v),w});
    allxor ^= w;
  }

  sort(J.begin(),J.end(),sort_Edge2_by_cost);

  dsu = DSU(N);
  bool allxor_zero = false;
  rep(i,N){
    rep(j,i){
      if(ES.count({j,i})) continue;
      if(dsu.leader(i) == dsu.leader(j)) allxor_zero = true;
      if(allxor_zero) break;
      dsu.merge(i,j);
    }
    if(allxor_zero) break;
  }
  if(allxor_zero) allxor = 0;
  
  vector<int> zero_bind(N,0);

  dsu = DSU(N);
  set<int> lefts; rep(i,N) lefts.insert(i);
  rep(s,N){
    if(lefts.count(s)==0) continue;
    queue<int> Q;
    Q.push(s); lefts.erase(s);
    while(Q.size()){
      int p = Q.front(); Q.pop();
      for(auto is = lefts.begin(); is != lefts.end(); ){
        if(ES.count({*is,p}) != 0){ is++; continue; }
        dsu.merge(*is,p);
        Q.push(*is);
        zero_bind[*is] = zero_bind[p] = 1;
        is = lefts.erase(is);
      }
    }
  }

  //cout<<"dsu.cnt = "<<dsu.cnt<<endl;


  ll ans = 0;
  ll min_penalty = allxor;

  for(auto e:J){
    if(dsu.leader(e.u) == dsu.leader(e.v)){
      if(zero_bind[e.u] || zero_bind[e.v]) min_penalty = min(min_penalty,e.w);
      continue;
    }
    dsu.merge(e.u,e.v);
    ans += e.w;
  }

  //cout<<"min_penalty = "<<min_penalty<<endl;

  printf("%lld\n",ans + min_penalty);

  return 0;
}