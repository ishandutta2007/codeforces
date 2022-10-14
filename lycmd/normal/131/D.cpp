#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,deg[N],vis[N],d[N];
vector<int>e[N];
queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
		deg[x]++,deg[y]++;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]==1)
			q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=1;
		for(int y:e[x])
			if(--deg[y]==1)
				q.push(y);
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			q.push(i),d[i]=0;
	memset(vis,0,sizeof vis);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int y:e[x])
			if(!vis[y]&&d[y]>d[x]+1)
				q.push(y),d[y]=d[x]+1;
	}
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";
	cout<<"\n";
}