#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,tot=1,deg[N],f[N],a[N],b[N],hd[N],to[N],nxt[N],vis[N];
vector<int>v;
void add(int x,int y){
	to[++tot]=y,nxt[tot]=hd[x],hd[x]=tot,deg[x]++;
}
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
void dfs(int x){
	for(int&i=hd[x];i;i=nxt[i]){
		if(vis[i])continue;
		vis[i]=vis[i^1]=1;
		int y=to[i];dfs(y);
	}
	cout<<v[x-1]<<" ";
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>a[i],v.push_back(a[i]);
	for(int i=1;i<n;i++){
		cin>>b[i],v.push_back(b[i]);
		if(a[i]>b[i])
			cout<<"-1\n",exit(0);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=v.size();i++)
		f[i]=i;
	for(int i=1;i<n;i++)
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1,
		b[i]=lower_bound(v.begin(),v.end(),b[i])-v.begin()+1,
		merge(a[i],b[i]),add(a[i],b[i]),add(b[i],a[i]);
	int cnt=0,s=1;
	for(int i=1;i<=v.size();i++){
		if(find(i)^find(1))
			cout<<"-1\n",exit(0);
		if(deg[i]&1)
			cnt++,s=i;
	}
	if(cnt>2)
		cout<<"-1\n",exit(0);
	dfs(s);
}