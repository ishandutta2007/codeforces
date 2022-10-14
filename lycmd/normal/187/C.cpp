#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,k,s,t,v[N],vis[N];
vector<int>e[N];
queue<pair<int,int> >q;
int check(int val){
	memset(vis,0,sizeof vis);
	q=queue<pair<int,int> >();
	q.push({s,val});
	while(!q.empty()){
		int x=q.front().first,k=q.front().second;q.pop();
		if(k<=vis[x])continue;
		vis[x]=k;
		for(int y:e[x])
			if(y==t)return 1;
			else if(v[y])q.push({y,val});
			else if(k>1)q.push({y,k-1});
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	while(k--){
		int x;cin>>x;v[x]=1;
	}
	while(m--){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cin>>s>>t;
	int l=-1,r=n+1,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1,ans=mid;else l=mid+1;
	}
	cout<<ans<<"\n";
}