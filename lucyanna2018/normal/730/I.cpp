#include <iostream> 
#include <sstream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <bitset> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 

using namespace std; 

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++) 

#define COST_INF (1<<30)

template <typename T> class MinCostFlow{ 
//  private: 
public:
   
  struct edge{int to,cap; T cost; int rev;}; 
   
  int V; 
  vector <vector <edge> > adj; 
  vector <T> pot; 
   
  pair <int, T> dijkstra(int s, int t, int FLOW_BOUND){ 
    int i; 
     
    vector <int> used(V, 0); 
    vector <T> dist(V, COST_INF); 
    vector <pair <int, int> > path(V, make_pair(-1, -1)); 
     
    priority_queue <pair <T, int> > q; 
    dist[s] = 0; 
    q.push(make_pair(0, s)); 
     
    while(!q.empty()){ 
      int x = q.top().second; 
      q.pop(); 
      if(used[x]) continue; 
      used[x] = true; 
       
      REP(i,adj[x].size()){ 
        edge e = adj[x][i]; 
        int y = e.to; 
        if(e.cap > 0){ 
          T d = dist[x] + e.cost + pot[x] - pot[y]; 
          if(d < dist[y] && !used[y]){ 
            dist[y] = d; 
            path[y] = make_pair(x, i); 
            q.push(make_pair(-d, y)); 
          } 
        } 
      } 
    } 
     
    REP(i,V) pot[i] += dist[i]; 
     
    if(dist[t] == COST_INF) return make_pair(0, 0); 
     
    int f = FLOW_BOUND; 
    T sum = 0; 
     
    int x = t; 
    while(x != s){ 
      int y = path[x].first; 
      int id = path[x].second; 
      sum += adj[y][id].cost; 
      f = min(f, adj[y][id].cap); 
      x = y; 
    } 
     
    x = t; 
    while(x != s){ 
      int y = path[x].first; 
      int id = path[x].second; 
      adj[y][id].cap -= f; 
      int id2 = adj[y][id].rev; 
      adj[x][id2].cap += f; 
      x = y; 
    } 
     
    return make_pair(f, f * sum); 
  } 
   
  public: 
   
  MinCostFlow(int n){ 
    V = n; 
    adj.resize(V, vector <edge>(0)); 
    pot.resize(V, 0); 
  } 
   
  void add_edge(int s, int t, int f, T c){ 
    edge e1 = {t, f, c, adj[t].size()}; 
    edge e2 = {s, 0, -c, adj[s].size()}; 
    adj[s].push_back(e1); 
    adj[t].push_back(e2); 
  } 
   
  pair <int, T> mincostflow(int s, int t, int FLOW_BOUND = (1<<29)){ 
    pair <int, T> ans = make_pair(0, 0); 
     
    while(FLOW_BOUND > 0){ 
      pair <int, T> tmp = dijkstra(s, t, FLOW_BOUND); 
      if(tmp.first == 0) break; 
      ans.first += tmp.first; 
      ans.second += tmp.second; 
      FLOW_BOUND -= tmp.first; 
    } 
     
    return ans; 
  } 
   
  vector <int> get_ans(int n){ 
    int i,j; 
    vector <int> ans(n); 
     
    REP(i,n){ 
      int s = n + i; 
      REP(j,adj[s].size()){ 
        edge e = adj[s][j]; 
        if(e.cap == 1 && e.to < n) ans[e.to] = i; 
      } 
    } 
     
    return ans; 
  } 
   
}; 

int nn,pp,ss;
int aa[3333],bb[3333];
int op[3333],os[3333],lop,los;
int main(){
	scanf("%d%d%d",&nn,&pp,&ss);
	int src = nn;
	int pro = nn + 1;
	int spt = nn + 2;
	int des = nn + 3;
	for(int i=0; i<nn; i++){
		scanf("%d",&aa[i]);
		aa[i] = 3001 - aa[i];
	}
	for(int i=0; i<nn; i++){
		scanf("%d",&bb[i]);
		bb[i] = 3001 - bb[i];
	}
		
	MinCostFlow<int> mcf(nn+4);
	for(int i=0; i<nn; i++){
		mcf.add_edge(src, i, 1, 0);
		mcf.add_edge(i, pro, 1, aa[i]);
		mcf.add_edge(i, spt, 1, bb[i]);
	}
	mcf.add_edge(pro, des, pp, 0);
	mcf.add_edge(spt, des, ss, 0);

	printf("%d\n",3001 * (pp+ss) - mcf.mincostflow(src, des).second);

	
	for(int i=0; i<nn; i++)
		for(int j=0; j<mcf.adj[i].size(); j++){
			if(mcf.adj[i][j].to == pro && mcf.adj[i][j].cap == 0){
				op[lop++] = i+1;
			}
			if(mcf.adj[i][j].to == spt && mcf.adj[i][j].cap == 0){
				os[los++] = i+1;
			}
		}

	for(int i=0; i<lop; i++)
		printf("%d%c",op[i],i<lop-1?' ':'\n');
	for(int i=0; i<los; i++)
		printf("%d%c",os[i],i<los-1?' ':'\n');
	return 0;
}