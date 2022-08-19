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
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	int n, m;
	cin >> n >> m;


	vector<tuple<int, int, int> > e(m);
	vector<vector<int> > edges(n);
	set<pair<int,int> > exists;

	ll cur_xor = 0;

	for(int i = 0; i < m; i++){
		auto& [u, v, w] = e[i];
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		exists.insert({u, v});
		exists.insert({v, u});
		cur_xor ^= w;
	}
	sort(e.begin(), e.end(), [&](tuple<int,int,int> a, tuple<int,int,int> b){
		return get<2>(a) < get<2>(b);
	});

	UF uf(n);
	set<int> conn;
	for(int i = 0; i < n-1; i++){
		conn.insert(i);
	}
	for(int i = 0; i < n; i++){
		edges[i].push_back(-1);
		edges[i].push_back(n);
		sort(edges[i].begin(), edges[i].end());
		for(int j = 0; j+1 < (int)edges[i].size(); j++){
			int a = edges[i][j];
			int b = edges[i][j+1];
			if(a + 1 < b){
				uf.join(i, a+1);
				while(true){
					auto v = conn.lower_bound(a+1);
					if(v == conn.end()) break;
					if(*v + 1 >= b) break;
					uf.join(*v, *v + 1);
					conn.erase(v);
				}
			}
		}
	}

	UF uf2 = uf;

	UF uf4(n);

	ll mst = 0;
	for(auto [u, v, w] : e){
		if(uf2.join(u, v)){
			mst += w;
			uf4.join(u, v);
		}
	}
	ll extra = cur_xor;

	UF uf3(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(exists.count({i, j})) continue;
			if(!uf3.join(i, j)){
				extra = 0;
				goto done;
			}
		}
	}
	for(auto [u, v, w] : e){
		if(uf4.find(u) != uf4.find(v)){
			extra = min(extra, ll(w));
		}
	}
	done:;
	mst += extra;
	cout << mst << '\n';
}