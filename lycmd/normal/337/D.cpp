#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,dis,p,cnt,mon[N],d[N][2];
vector<int>e[N];
queue<pair<int,int> >q;
void dfs(int x,int fa,int dep,int col){
	d[x][col]=dep;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=fa)
			dfs(e[x][i],x,dep+1,col);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>dis;
	for(int i=1;i<=m;i++)cin>>mon[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0,0,0);
	for(int i=1;i<=m;i++)
		if(d[mon[i]][0]>d[p][0])
			p=mon[i];
	dfs(p,0,0,0);
	p=0;
	for(int i=1;i<=m;i++)
		if(d[mon[i]][0]>d[p][0])
			p=mon[i];
	dfs(p,0,0,1);
	for(int i=1;i<=n;i++)
		if(d[i][0]<=dis&&d[i][1]<=dis)
			cnt++;
	cout<<cnt<<"\n";
}