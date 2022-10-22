#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

struct edge{
	llint to, cost;
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

llint n, m, k, Q;
vector<edge> G[100005];
llint dist[100005];
llint u[300005], v[300005], w[300005];
llint s[300005], t[300005];
llint ub[300005], lb[300005], mid[300005];
UnionFind uf(300005);
vector<E> vec;
vector<P> qvec;

void dijkstra(vector<edge> G[], llint S, llint dist[])
{
	for(int i = 0; i <= n+1; i++) dist[i] = inf;
	dist[S] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( make_pair(0, S) );
	
	llint v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].to] > d + G[v][i].cost){
				dist[G[v][i].to] = d + G[v][i].cost;
				Q.push( make_pair(dist[G[v][i].to], G[v][i].to) );
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k >> Q;
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		G[u[i]].push_back(edge(v[i], w[i]));
		G[v[i]].push_back(edge(u[i], w[i]));
	}
	llint S = n+1;
	for(int i = 1; i <= k; i++) G[S].push_back(edge(i, 0));
	
	dijkstra(G, S, dist);
	
	//for(int i = 1; i <= n; i++) cout << dist[i] << " "; cout << endl;
	
	for(int i = 1; i <= m; i++){
		vec.push_back(E(dist[u[i]]+dist[v[i]]+w[i], P(u[i], v[i])));
	}
	sort(vec.begin(), vec.end());
	
	//for(int i = 0; i < vec.size(); i++) cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << endl;
	
	for(int i = 1; i <= Q; i++) cin >> s[i] >> t[i];
	for(int q = 1; q <= Q; q++) ub[q] = (llint)3e14 + 7, lb[q] = 0;
	
	while(1){
		for(int q = 1; q <= Q; q++) mid[q] = (ub[q]+lb[q])/2;
		
		//for(int q = 1; q <= Q; q++) cout << mid[q] << " "; cout << endl;
		
		qvec.clear();
		for(int q = 1; q <= Q; q++){
			if(ub[q]-lb[q]>1) qvec.push_back(P(mid[q], q));
		}
		if(qvec.size() == 0) break;
		sort(qvec.begin(), qvec.end());
		
		uf.init(); llint p = 0;
		for(int i = 0; i < vec.size(); i++){
			while(p < qvec.size() && qvec[p].first < vec[i].first){
				llint qid = qvec[p].second;
				if(uf.same(s[qid], t[qid])) ub[qid] = mid[qid];
				else lb[qid] = mid[qid];
				p++;
			}
			uf.unite(vec[i].second.first, vec[i].second.second);
		}
		while(p < qvec.size()){
			llint qid = qvec[p].second;
			if(uf.same(s[qid], t[qid])) ub[qid] = mid[qid];
			else lb[qid] = mid[qid];
			p++;
		}
	}
	
	for(int i = 1; i <= Q; i++) cout << ub[i] << "\n";
	flush(cout);
	
	
	return 0;
}