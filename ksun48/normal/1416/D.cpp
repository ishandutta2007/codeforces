#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	vector<pair<int,int> > edges(m);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[i] = {u, v};
	}
	vector<int> type(q), where(q);
	vector<int> del(m, 0);
	for(int i = 0; i < q; i++){
		cin >> type[i] >> where[i];
		where[i]--;
		if(type[i] == 2){
			assert(del[where[i]] == 0);
			del[where[i]] = 1;
		}
	}
	for(int i = 0; i < m; i++){
		if(!del[i]){
			del[i] = 1;
			type.push_back(2);
			where.push_back(i);
		}
	}
	q = (int)type.size();
	vector<int> par(n);
	vector<vector<int> > contents(n);
	for(int i = 0; i < n; i++){
		par[i] = i;
		contents[i] = {i};
	}
	vector<vector<int> > rewrite(q);
	vector<int> rewrite_par(q, -1);
	for(int i = q-1; i >= 0; i--){
		if(type[i] == 2){
			int u, v;
			tie(u, v) = edges[where[i]];
			if(par[u] == par[v]) continue;
			u = par[u];
			v = par[v];
			if(contents[u].size() < contents[v].size()) swap(u, v);
			rewrite[i] = contents[v];
			rewrite_par[i] = v;
			for(int a : contents[v]){
				contents[u].push_back(a);
				par[a] = u;
			}
			contents[v] = {};
		}
	}
	vector<set<int> > cc_label(n);
	for(int i = 0; i < n; i++){
		cc_label[par[i]].insert(p[i]);
	}
	for(int i = 0; i < q; i++){
		if(type[i] == 1){
			int loc = par[where[i]];
			if(cc_label[loc].empty()){
				cout << 0 << '\n';
			} else {
				auto r = prev(cc_label[loc].end());
				cout << *r << '\n';
				cc_label[loc].erase(r);
			}
		} else {
			int cpar = par[edges[where[i]].first];
			int npar = rewrite_par[i];
			for(int x : rewrite[i]){
				if(cc_label[cpar].count(p[x])){
					cc_label[cpar].erase(p[x]);
					cc_label[npar].insert(p[x]);
				}
				assert(par[x] == cpar);
				par[x] = npar;
			}
		}
	}
}