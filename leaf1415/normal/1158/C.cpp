#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int n;
int a[500005];
vector<int> G[500005];
vector<int> revG[500005];

vector<int> topo;
bool used[500005];
int ans[500005];

bool check(int l, int r)
{
	//cout << l << " " << r << endl;
	if(l == r) return true;
	for(int i = l; i < r; i++){
		//cout << i << endl;
		if(a[i] == -1) continue;
		if(a[i] > r) return false;
		if(!check(i+1, a[i])) return false;
		i = a[i]-1;
	}
	return true;
}

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		if(!check(1, n+1)){
			cout << -1 << endl;
			continue;
		}
		
		for(int i = 1; i <= n+1; i++){
			G[i].clear(), revG[i].clear();
			if(a[i] > 0){
				G[i].push_back(a[i]);
				revG[a[i]].push_back(i);
			}
			if(a[i] == -1){
				G[i].push_back(i+1);
				revG[i+1].push_back(i);
			}
		}
		for(int i = 1; i <= n+1; i++){
			for(int j = 1; j < revG[i].size(); j++){
				G[revG[i][j]].push_back(revG[i][j-1]);
			}
		}
		
		/*for(int i = 1; i <= n+1; i++){
			for(int j = 0; j < G[i].size(); j++) cout << G[i][j] << " "; cout << endl;
		}*/
		
		topo.clear();
		for(int i = 1; i <= n+1; i++) used[i] = false;
		for(int i = 1; i <= n+1; i++) if(!used[i]) tpsort(i);
		reverse(topo.begin(), topo.end());
		
		int id = 1;
		for(int i = 0; i < topo.size(); i++){
			if(topo[i] <= n) ans[topo[i]] = id++;
		}
		for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
	}
	
	return 0;
}