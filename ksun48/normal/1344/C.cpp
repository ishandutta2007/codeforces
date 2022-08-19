#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<pair<int,int> > what(m);
	for(int i = 0; i < m; i++){
		cin >> what[i].first >> what[i].second;
		what[i].first--; what[i].second--;
	}
	vector<bool> for_all(n, true);
	for(int j = 0; j < 2; j++){
		vector<vector<int> > edges(n);
		vector<int> deg(n, 0);
		vector<int> val(n);
		for(int i = 0; i < m; i++){
			int x, y;
			tie(x, y) = what[i];
			if(j == 1) swap(x, y);
			edges[x].push_back(y);
			deg[y]++;
		}
		for(int i = 0; i < n; i++) val[i] = i;
		vector<int> bfs;
		int s = 0;
		for(int i = 0; i < n; i++) if(deg[i] == 0) bfs.push_back(i);
		while(s < (int)bfs.size()){
			int v = bfs[s];
			s++;
			if(val[v] < v){
				for_all[v] = false;
			}
			for(int w : edges[v]){
				val[w] = min(val[w], val[v]);
				deg[w]--;
				if(deg[w] == 0){
					bfs.push_back(w);
				}
			}
		}
		if((int)bfs.size() != n){
			cout << -1 << '\n';
			exit(0);
		}
	}
	int a = 0;
	for(bool r : for_all) if(r) a++;
	cout << a << '\n';
	for(int i = 0; i < n; i++){
		cout << "EA"[for_all[i]];
	}
	cout << '\n';
}