#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m, k;
vector<edge> G[200005];
vector<pair<llint, P> > vec;
map<P, llint> mp;
set<pair<llint, P> > S;

void add(llint l, llint u, llint v)
{
	for(int i = 0; i < G[u].size(); i++){
		int x = G[u][i].to;
		P p = make_pair(x, v);
		if(p.second < p.first) swap(p.first, p.second);
		
		llint prel = inf;
		if(mp.count(p)) prel = mp[p];
		if(p.first == p.second || prel <= l+G[u][i].cost) continue;
		
		S.erase(make_pair(prel, p));
		S.insert(make_pair(l+G[u][i].cost, p));
		if(S.size() > k){
			auto it = S.end();
			it--;
			S.erase(it);
		}
		mp[p] = l+G[u][i].cost;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	llint u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		vec.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < min(k, (llint)vec.size()); i++){
		w = vec[i].first, u = vec[i].second.first, v = vec[i].second.second;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
		if(u > v) swap(u, v);
		mp[make_pair(u, v)] = w;
		S.insert(make_pair(w, make_pair(u, v)));
	}
	
	while(1){
		llint l = S.begin()->first, u = S.begin()->second.first, v = S.begin()->second.second;
		//cout << l << " " << u << " " << v << endl;
		if(k == 1){
			cout << l << endl;
			return 0;
		}
		S.erase(S.begin());
		k--;
		add(l, u, v);
		add(l, v, u);
	}
	
	return 0;
}