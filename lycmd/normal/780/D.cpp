#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,cur,tot,dfn[N],low[N],vis[N],scc[N];
string a,b,s1[N],s2[N];
vector<int>e[N];
stack<int>s;
void dfs(int x){
	dfn[x]=low[x]=++cur,vis[x]=1,s.push(x);
	for(int y:e[x])
		if(!dfn[y])
			dfs(y),low[x]=min(low[x],low[y]);
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	if(dfn[x]==low[x])
		for(tot++;;){
			int t=s.top();s.pop();
			vis[t]=0,scc[t]=tot;
			if(x==t)break;
		}
}
void mark(int x){
	vis[x]=1;
	for(int y:e[x])
		if(!vis[y])
			mark(y);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a>>b,s1[i]=a.substr(0,3),s2[i]=a.substr(0,2)+b[0];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j)
				continue;
			if(s1[i]==s1[j])
				e[i+n].push_back(j+n),
				e[i].push_back(j+n);
			if(s1[i]==s2[j])
				e[i].push_back(j);
			if(s2[i]==s1[j])
				e[i+n].push_back(j+n);
			if(s2[i]==s2[j])
				e[i+n].push_back(j);
		}
	for(int i=1;i<=n+n;i++)
		if(!dfn[i])dfs(i);
	for(int i=1;i<=n;i++)
		if(scc[i]==scc[i+n])
			cout<<"NO\n",exit(0);
	memset(vis,0,sizeof vis);
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
		if(vis[i])
			cout<<s1[i]<<"\n",mark(i);
		else
			cout<<s2[i]<<"\n",mark(i+n);
}