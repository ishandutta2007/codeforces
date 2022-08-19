#include <bits/stdc++.h>
using namespace std;
 
struct UF {
    int n;
    vector<int> par;
    UF(int n) : n(n) {
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
 
using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	UF uf(n);
	vector<vector<int> > edges(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
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
	int ncc = 0;
	vector<int> zz(n);
	vector<int> cnt(n, 0);
 
	ll ne = 0;
	for(int i = 0; i < n; i++){
		ne += cnt[uf.find(i)];
		cnt[uf.find(i)]++;
		if(uf.find(i) == i){
			zz[i] = ncc;
			ncc++;
		}
	}
	cout << ncc - 1 << '\n';
}