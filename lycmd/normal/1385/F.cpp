#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int t,n,k,deg[N],vis[N];
vector<int>e[N];
queue<int>q;
int check(int x){
	return deg[x]&&deg[x]%k==0&&e[x].size()-deg[x]==1;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear(),vis[i]=deg[i]=0;
		for(int i=1,x,y;i<n;i++)
			cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
		if(k==1){
			cout<<n-1<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			if(e[i].size()==1)
				vis[i]=1,deg[e[i][0]]++;
		for(int i=1;i<=n;i++)
			if(check(i))
				q.push(i);
		int ans=0;
		while(!q.empty()){
			int x=q.front();q.pop();
			ans+=deg[x]/k,vis[x]=1;
			for(int y:e[x])
				if(!vis[y]&&++deg[y]&&check(y))
					q.push(y);
		}
		for(int i=1;i<=n;i++)
			ans+=!vis[i]*deg[i]/k;
		cout<<ans<<"\n";
	}
}