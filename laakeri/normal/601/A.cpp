#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[444][2];

int gg[444][444];

int n;
int d[444];
int inf=1e9;

int dd(int k){
	for (int i=1;i<=n;i++){
		d[i]=inf;
	}
	queue<pair<int, int> > bfs;
	bfs.push({1, 0});
	while (!bfs.empty()){
		auto x=bfs.front();
		bfs.pop();
		if (d[x.F]<inf) continue;
		d[x.F]=x.S;
		for (int nx:g[x.F][k]){
			bfs.push({nx, x.S+1});
		}
	}
	return d[n];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		gg[a][b]=1;
		gg[b][a]=1;
	}
	for (int a=1;a<=n;a++){
		for (int b=1;b<=n;b++){
			if (a!=b){
				if (gg[a][b]){
					g[a][0].push_back(b);
					g[b][0].push_back(a);
				}
				else{
					g[a][1].push_back(b);
					g[b][1].push_back(a);
				}
			}
		}
	}
	int v=max(dd(0), dd(1));
	if (v==inf){
		cout<<-1<<endl;
	}
	else{
		cout<<v<<endl;
	}
}