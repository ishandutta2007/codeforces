#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> lol;

int u[202020];
vector<int> g[202020];

void dfs(int x){
	if (u[x]) return;
	u[x]=1;
	lol.push_back(x);
	for (int nx:g[x]){
		if (!u[nx]){
			dfs(nx);
			lol.push_back(x);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	int c=(2*n)/k;
	if ((2*n)%k>0) c++;
	int t=0;
	for (int i=0;i<k;i++){
		vector<int> v;
		for (int j=0;j<c;j++){
			if (t<(int)lol.size()){
				v.push_back(lol[t]);
				t++;
			}
		}
		if (v.size()==0) v.push_back(1);
		cout<<v.size()<<" ";
		for (int vv:v){
			cout<<vv<<" ";
		}
		cout<<'\n';
	}
	assert(t>=(int)lol.size());
}