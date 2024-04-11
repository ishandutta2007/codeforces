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

void solve(){
	int n;
	cin >> n;
	vector<vector<string> > s(n, vector<string>(n));
	for(int i = 0; i < n; i++){
		s[i][i] = string(n, '1');
		for(int j = i+1; j < n; j++){
			cin >> s[i][j];
			s[j][i] = s[i][j];
		}
	}
	UF uf(n * n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			uf.join(i * n + j, i + n * j);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(s[i][j][k] == '1'){
					uf.join(i * n + k, j * n + k);
				}
			}
		}
	}
	vector<vector<int>> cc(n*n);
	for(int i = 0; i < n*n; i++){
		cc[uf.find(i)].push_back(i);
	}
	for(int st = 0; st < n*n; st++){
		if(cc[st].size() == 2 * (n-1)){
			bool works = true;
			vector<pair<int,int> > edges;
			UF uf_tree(n);
			for(int x : cc[st]){
				int a = x / n;
				int b = x % n;
				if(a < b){
					edges.push_back({a, b});
					uf_tree.join(a, b);
				}
			}
			if(edges.size() != n-1){
				works = false;
			}
			for(int i = 0; i < n; i++){
				if(uf_tree.find(i) != uf_tree.find(0)){
					works = false;
				}
			}
			if(!works) continue;
			vector<vector<int> > dist(n, vector<int>(n, n));
			for(int i = 0; i < n; i++) dist[i][i] = 0;
			for(auto [x, y] : edges){
				dist[x][y] = dist[y][x] = 1;
			}
			for(int k = 0; k < n; k++){
				for(int i = 0; i < n; i++){
					for(int j = 0; j < n; j++){
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					for(int k = 0; k < n; k++){
						if((dist[i][k] == dist[j][k]) != (s[i][j][k] == '1')){
							works = false;
						}
					}
				}
			}
			if(works){
				cout << "Yes" << '\n';
				for(auto [x, y] : edges){
					cout << (x+1) << ' ' << (y+1) << '\n';
				}
				return;
			}
		}
	}
	cout << "No" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}