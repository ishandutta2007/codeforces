#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<set<int> > edges;
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].insert(v);
		edges[v].insert(u);
	}
	if(n <= 3){
		cout << "No" << endl;
		return 0;
	}
	vector<int> d3;
	set<int> leaves;
	for(int i = 0; i < n; i++){
		if(edges[i].size() == 2){
			cout << "No" << endl;
			return 0;
		} else if(edges[i].size() == 3){
			d3.push_back(i);
		} else if(edges[i].size() == 1){
			leaves.insert(i);
		}
	}
	if(d3.size() > 1){
		cout << "No" << endl;
		return 0;
	}
	int nsteps = 0;
	while(1){
		nsteps++;
		set<int> newleaves;
		for(int a : leaves){
			if(edges[a].size() != 1){
				cout << "No" << endl;
				return 0;
			}
			int b = *edges[a].begin();
			if(!edges[b].count(a)){
				cout << "No" << endl;
				return 0;
			}
			edges[a].erase(b);
			newleaves.insert(b);
			edges[b].erase(a);
		}
		leaves = newleaves;
		if(leaves.size() == 0){
			cout << "No" << endl;
			return 0;			
		}
		if(leaves.size() == 1 && edges[*leaves.begin()].size() == 0) break;
		for(int v : leaves){
			if(edges[v].size() != 1){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	if(d3.size() == 1 && !leaves.count(d3[0])){
		cout << "No" << endl;
		return 0;
	}
	if(nsteps == k){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;		
	}
}