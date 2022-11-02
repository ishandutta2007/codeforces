#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef double ld;

vector<int> g[101010];
int aps[101010];

void dfs0(int x){
	aps[x]=1;
	for (int nx:g[x]){
		dfs0(nx);
		aps[x]+=aps[nx];
	}
}

ld v[101010];

void dfs1(int x){
	int su=aps[x]-1;
	for (int nx:g[x]){
		int lol=su-aps[nx];
		v[nx]=1+v[x]+(ld)lol/(ld)2;
		dfs1(nx);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=2;i<=n;i++){
		int p;
		cin>>p;
		g[p].push_back(i);
	}
	dfs0(1);
	v[1]=1;
	dfs1(1);
	cout<<setprecision(15);
	for (int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
}