#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[202020];

int mk=0;
int c[202020];

void dfs(int x, int p){
	mk=max(mk, c[x]);
	int nc=1;
	for (int nx:g[x]){
		if (nx!=p){
			while (nc==c[x]||nc==c[p]) nc++;
			c[nx]=nc;
			dfs(nx, x);
			nc++;
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
	c[1]=1;
	dfs(1, 0);
	cout<<mk<<'\n';
	for (int i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
}