#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1e9;
int aps[505050];
vector<int> g[505050];

int v=0;

vector<int> dd[505050];

void dfs1(int x, int p, int p2, int d){
	if (x>1&&g[x].size()==1){
		dd[p2].push_back(d);
	}
	for (int nx:g[x]){
		if (nx!=p){
			if (x==1){
				dfs1(nx, x, nx, d+1);
			}
			else{
				dfs1(nx, x, p2, d+1);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(1, 0, 0, 0);
	for (int i=1;i<=n;i++){
		sort(dd[i].rbegin(), dd[i].rend());
		for (int j=0;j<(int)dd[i].size();j++){
			v=max(v, j+dd[i][j]);
		}
	}
	cout<<v<<endl;
}