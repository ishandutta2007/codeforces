#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,m,k,a[N],p[N],l[N],r[N],in[N],vis[N],ans[N];
vector<int>e[N],g[N];
queue<int>q;
priority_queue<pair<int,int> >s;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]?(l[i]=r[i]=a[i]):(l[i]=1,r[i]=k);
	while(m--){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		for(int j:e[i])in[j]++;
	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=1;
		for(int y:e[x]){
			if((r[y]=min(r[y],r[x]-1))<l[y])
				cout<<"-1\n",exit(0);
			if(!--in[y])q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			cout<<"-1\n",exit(0);
	memset(in,0,sizeof in);
	for(int i=1;i<=n;i++)
		for(int j:g[i])in[j]++;
	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:g[x]){
			if((l[y]=max(l[y],l[x]+1))>r[y])
				cout<<"-1\n",exit(0);
			if(!--in[y])q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		a[i]=i;
	sort(a+1,a+1+n,[&](int x,int y){
		return l[x]<l[y]||(l[x]==l[y]&&r[x]<r[y]);
	});
	for(int i=1,j=1;i<=k;i++){
		for(;j<=n&&l[a[j]]<=i;j++)
			s.push({-r[a[j]],a[j]});
		int flg=0;
		while(s.size()){
			int t=s.top().second;
			if(flg&&r[t]>i)break;
			ans[t]=i,flg=1,s.pop();
		}
		if(!flg)
			cout<<"-1\n",exit(0);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
}