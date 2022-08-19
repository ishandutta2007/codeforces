#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m;
vector<int> children[210000];

int sz[210000];
int maximum[210000];
int minimum[210000];
int depth[210000];
void dfs(int a){
	int c = children[a].size();
	if(c == 0){
		sz[a] = 1;
		maximum[a] = 1;
		minimum[a] = 1;
		return;
	}
	sz[a] = 0;
	for(int i = 0; i < c; i++){
		depth[children[a][i]] = depth[a]+1;
		dfs(children[a][i]);
		sz[a] += sz[children[a][i]];
		//cout << a << " " << children[a][i] << endl;
	}
	if(depth[a] % 2 == 0){
		maximum[a] = 1;
		minimum[a] = 0;
		for(int i = 0; i < c; i++){
			maximum[a] = max(maximum[a], sz[a]-(sz[children[a][i]]-maximum[children[a][i]]) );
			//minimum[a] -= (sz[children[a][i]] - maximum[children[a][i]]);
			minimum[a] += minimum[children[a][i]];
		}
	} else {
		maximum[a] = sz[a]+1;
		minimum[a] = sz[a];
		for(int i = 0; i < c; i++){
			maximum[a] -= (1+sz[children[a][i]] - maximum[children[a][i]]);
			//maximum[a] += (minimum[children[a][i]]-1);
			minimum[a] = min(minimum[a], minimum[children[a][i]]);
		}
	}
	return;
}

int main(){
	cin >> n;
	depth[1] = 0;
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		children[a].push_back(b);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		//cout << i << " " << depth[i] << " " << sz[i] << " " << maximum[i] << " " << minimum[i] << endl;
	}
	cout << maximum[1] << " " << minimum[1] << endl;

}