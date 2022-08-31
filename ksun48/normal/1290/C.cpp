#include <bits/stdc++.h>
using namespace std;

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    void join(int a, int b){
        par[find(a)] = find(b);
    }
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	string lamps;
	cin >> lamps;
	vector<vector<int> > which(n);
	for(int i = 0; i < k; i++){
		int l;
		cin >> l;
		for(int j = 0; j < l; j++){
			int a;
			cin >> a;
			a--;
			which[a].push_back(i);
		}
	}
	// sol for n
	vector<int> forced(k, 0);
	vector<vector<pair<int,int> > > edges(k);
	for(int i = 0; i < n; i++){
		if(which[i].size() == 0){

		} else if(which[i].size() == 1){
			forced[which[i][0]] = (lamps[i] == '0') ? -1 : 1;
		} else if(which[i].size() == 2){
			int a = which[i][0];
			int b = which[i][1];
			edges[a].push_back({b, (lamps[i] == '0') ? -1 : 1});
			edges[b].push_back({a, (lamps[i] == '0') ? -1 : 1});
		} else assert(false);
	}
	vector<int> sol(k, 0);
	for(int i = 0; i < k; i++){
		if(sol[i]) continue;
		vector<pair<int,int> > bfs;
		int s = 0;
		sol[i] = 1;
		bfs.push_back({i, 1});
		while(s < (int)bfs.size()){
			int v = bfs[s].first;
			int d = bfs[s].second;
			s++;
			for(pair<int,int> e : edges[v]){
				int w = e.first;
				int val = d * e.second;
				if(sol[w]) continue;
				sol[w] = val;
				bfs.push_back({w, val});
			}
		}
		bool flip = false;
		for(pair<int,int> x : bfs){
			int v = x.first;
			if(forced[v] && forced[v] != sol[v]){
				flip = true;
			}
		}
		if(flip){
			for(pair<int,int> x : bfs){
				sol[x.first] *= -1;
			}
		}
	}

	UF uf(k);

	vector<int> ops(k);
	for(int i = 0; i < k; i++) ops[i] = (sol[i] == 1) ? 0 : 1;
	vector<int> sz(k, 1);
	vector<bool> fixed(k, false);

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(which[i].size() == 0){

		} else if(which[i].size() == 1){
			int a = uf.find(which[i][0]);
			ans -= (fixed[a] ? ops[a] : min(ops[a], sz[a] - ops[a]));
			fixed[a] = true;
			ans += (fixed[a] ? ops[a] : min(ops[a], sz[a] - ops[a]));
		} else if(which[i].size() == 2){
			int a = uf.find(which[i][0]);
			int b = uf.find(which[i][1]);
			if(a != b){
				ans -= (fixed[a] ? ops[a] : min(ops[a], sz[a] - ops[a]));
				ans -= (fixed[b] ? ops[b] : min(ops[b], sz[b] - ops[b]));
				uf.par[a] = b;
				ops[b] += ops[a];
				sz[b] += sz[a];
				fixed[b] = fixed[b] | fixed[a];
				ans += (fixed[b] ? ops[b] : min(ops[b], sz[b] - ops[b]));
			}
		} else assert(false);
		cout << ans << '\n';
	}
}