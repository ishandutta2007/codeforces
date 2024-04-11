#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,m,vis[N];
queue<int>q;
vector<int>e[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m;m--;){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int p=0;
	for(int i=1;i<=n;i++)
		if(e[i].size()>e[p].size())
			p=i;
	for(q.push(p),vis[p]=1;!q.empty();){
		int x=q.front();q.pop();
		for(int y:e[x])
			if(!vis[y])
				vis[y]=1,cout<<x<<" "<<y<<"\n",q.push(y);
	}
}