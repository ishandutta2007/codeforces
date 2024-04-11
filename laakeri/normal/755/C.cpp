#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[10101];
int u[10101];

void dfs(int x){
	if (u[x]) return;
	u[x]=1;
	for (int nx:g[x]) dfs(nx);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int p;
		cin>>p;
		g[i].push_back(p);
		g[p].push_back(i);
	}
	int v=0;
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			v++;
			dfs(i);
		}
	}
	cout<<v<<endl;
}