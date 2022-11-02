#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[101010];

int c[101010];

vector<int>a,b;

void dfs(int x, int cc){
	if (c[x]!=0){
		if (c[x]!=cc){
			cout<<-1<<endl;
			exit(0);
		}
		return;
	}
	c[x]=cc;
	if (c[x]==1){
		a.push_back(x);
	}
	else{
		b.push_back(x);
	}
	for (int nx:g[x]){
		dfs(nx, 3-cc);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int aa,bb;
		cin>>aa>>bb;
		g[aa].push_back(bb);
		g[bb].push_back(aa);
	}
	for (int i=1;i<=n;i++){
		if (c[i]==0){
			dfs(i, 1);
		}
	}
	cout<<a.size()<<'\n';
	for (int t:a){
		cout<<t<<" ";
	}
	cout<<b.size()<<'\n';
	for (int t:b){
		cout<<t<<" ";
	}
}