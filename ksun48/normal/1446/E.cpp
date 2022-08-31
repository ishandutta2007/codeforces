#include <bits/stdc++.h>
using namespace std;

struct UF {
    int n;
    vector<int> par;
    vector<int> sz;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
        for(int i = 0; i < n; i++) sz.push_back(1);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
    	if(a == b) return false;
        par[a] = b;
        sz[b] += sz[a];
        return true;
    }
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int F = 510;
	vector<vector<int> > neighbors(F*F);
	for(int i = 0; i < F; i++){
		for(int j = 0; j < F; j++){
			int a = i*F + j;
			if(i+1 < F){
				neighbors[a].push_back((i+1)*F + j);
			}
			if(i > 0){
				neighbors[a].push_back((i-1)*F + j);
			}
			if(i & 1){
				if(i > 0 && j+1 < F){
					neighbors[a].push_back((i-1)*F + (j+1));
				}
			} else {
				if(i+1 < F && j > 0){
					neighbors[a].push_back((i+1)*F + (j-1));
				}
			}
		}
	}
	const int N = F*F;
	int n;
	cin >> n;
	vector<int> on(N, 0);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		x += 2; y += 2;
		int a = F*x + y;
		on[a] = 1;
	}
	vector<int> orig_on = on;
	vector<int> on_neighbors(N, 0);
	for(int a = 0; a < N; a++){
		if(on[a]){
			for(int b : neighbors[a]){
				on_neighbors[b]++;
			}
		}
	}
	vector<int> bfs;
	int s = 0;
	for(int a = 0; a < N; a++){
		if(on_neighbors[a] >= 2) bfs.push_back(a);
	}
	int steps = 0;
	while(s < (int)bfs.size()){
		int v = bfs[s];
		s++;
		if(on[v]) continue;
		on[v] = true;
		steps++;
		for(int b : neighbors[v]){
			on_neighbors[b]++;
			if(on_neighbors[b] >= 2){
				bfs.push_back(b);
			}
		}
	}
	{
		vector<int> on2 = on;
		vector<int> on2_neighbors = on_neighbors;
		bfs = {};
		s = 0;
		for(int a = 0; a < N; a++){
			if(on2_neighbors[a] <= 1){
				bfs.push_back(a);
			}
		}
		while(s < (int)bfs.size()){
			int v = bfs[s];
			s++;
			if(!on2[v]) continue;
			on2[v] = false;
			steps++;
			for(int b : neighbors[v]){
				on2_neighbors[b]--;
				if(on2_neighbors[b] <= 1){
					bfs.push_back(b);
				}
			}
		}
		bool fail = false;
		for(int a = 0; a < N; a++){
			if(on2[a]) fail = true;
		}
		if(fail){
			cout << "SICK" << '\n';
			exit(0);
		}
	}
	int perimeter = 0;
	for(int a = 0; a < N; a++){
		if(orig_on[a]){
			for(int b : neighbors[a]){
				if(!orig_on[b]) perimeter += 1;
			}
		}
	}
	int ans = perimeter;
	UF uf(N);
	for(int a = 0; a < N; a++){
		for(int b : neighbors[a]){
			if(on[a] && on[b]) uf.join(a, b);
		}
	}
	for(int a = 0; a < N; a++){
		if(on[a] && uf.find(a) == a){
			ans -= 2;
		}
	}
	for(int a = 0; a < N; a++){
		if(on[a] && !orig_on[a] && on_neighbors[a] == 3 && uf.sz[uf.find(a)] == 4){
			ans -= 2;
		}
	}
	cout << "RECOVERED" << '\n';
	cout << ans << '\n';
}