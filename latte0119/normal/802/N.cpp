#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Ti = tuple<int, int, int>;
using Tl = tuple<ll, ll, ll>;
const int INF = 1LL << 55;
struct edge
{
  int to, capacity, cost, rev;
  edge(){}
  edge(int to, int capacity, int cost, int rev):to(to), capacity(capacity), cost(cost), rev(rev){}
};

struct PrimalDual
{
  vector< vector<edge> > graph;
  vector<int> potential, mincost, prevv, preve;
  PrimalDual(int V):graph(V), potential(V), mincost(V), prevv(V), preve(V){}
  void add_edge(int from, int to, int capacity, int cost)
  {
    graph[from].push_back(edge(to, capacity, cost, (int)graph[to].size()));
    graph[to].push_back(edge(from, 0, -cost, (int)graph[from].size()-1));
  }
  int min_cost_flow(int source, int sink, int f)
  {
    int ret = 0;
    fill(potential.begin(), potential.end(), 0);
    fill(prevv.begin(), prevv.end(), -1);
    fill(preve.begin(), preve.end(), -1);

    while(f > 0) {
      priority_queue<Pi, vector<Pi>, greater<Pi> > que;
      fill(mincost.begin(), mincost.end(), INF);
      mincost[source] = 0;
      que.push(Pi(0, source));
      while(!que.empty()) {
    Pi p = que.top(); que.pop();
    int v = p.second;
    if(mincost[v] < p.first) continue;
    for(int i = 0; i < (int)graph[v].size(); i++) {
      edge& e = graph[v][i];
      int dual_cost = mincost[v] + e.cost + potential[v] - potential[e.to];
      if(e.capacity > 0 && dual_cost < mincost[e.to]) {
        mincost[e.to] = dual_cost;
        prevv[e.to] = v; preve[e.to] = i;
        que.push(Pi(mincost[e.to], e.to));
      }
    }
      }

      if(mincost[sink] == INF) return -1;
      for(int v = 0; v < (int)graph.size(); v++) potential[v] += mincost[v];
      int d = f;
      for(int v = sink; v != source; v = prevv[v]) d = min(d, graph[prevv[v]][preve[v]].capacity);
      f -= d;
      ret += d * potential[sink];
      for(int v = sink; v != source; v = prevv[v]) {
    edge& e = graph[prevv[v]][preve[v]];
    e.capacity -= d;
    graph[v][e.rev].capacity += d;
      }
    }
    return ret;
  }
};
signed main(){
    int N,K;
    cin>>N>>K;
    vint A(N),B(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];

    PrimalDual mcf(5000);
    int src=4998,snk=4999;
    int INF=1001001001;
    rep(i,N){
        mcf.add_edge(src,i,1,A[i]);
        mcf.add_edge(i,i+N,INF,0);
        mcf.add_edge(i+N,snk,1,B[i]);
        if(i+1!=N)mcf.add_edge(i+N,i+1+N,INF,0);
    }

    cout<<mcf.min_cost_flow(src,snk,K)<<endl;
    return 0;
}