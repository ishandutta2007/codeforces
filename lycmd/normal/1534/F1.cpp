#include<bits/stdc++.h>
#define ord(i,j) ((i-1)*m+j)
using namespace std;
int const N=400010;
int n,m,cnt,ans,tot,cur,top,in[N],id[N],dfn[N],low[N],vis[N],stk[N],col[N];
string s[N];
vector<int>e[N],p[N],x[N];
void add(int x,int y){
	e[x].push_back(y);
}
void dfs(int x){
	dfn[x]=low[x]=++cur,stk[++top]=x,vis[x]=1;
	for(int y:e[x]){
		if(!dfn[y]){
			dfs(y),low[x]=min(low[x],low[y]);
		}else if(vis[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		for(tot++;;){
			int k=stk[top--];
			vis[k]=0,col[k]=tot;
			if(k==x)return;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i],s[i]=" "+s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#')
				p[j].push_back(id[ord(i,j)]=++cnt),
				x[j].push_back(i);
	for(int i=1;i<=m;i++)
		for(int j=0;j<p[i].size();j++){
			int t=p[i][j];
			if(j){
				add(p[i][j-1],t);
				if(x[i][j]-x[i][j-1]==1)
					add(t,p[i][j-1]);
			}
			auto p1=lower_bound(p[i-1].begin(),p[i-1].end(),p[i][j]),
				 p2=lower_bound(p[i+1].begin(),p[i+1].end(),p[i][j]);
			if(p1!=p[i-1].end()){
				add(t,*p1);
				if(x[i-1][p1-p[i-1].begin()]==x[i][j])
					add(*p1,t);
			}
			if(p2!=p[i+1].end()){
				add(t,*p2);
				if(x[i+1][p2-p[i+1].begin()]==x[i][j])
					add(*p2,t);
			}
		}
	for(int i=1;i<=cnt;i++)
		if(!dfn[i])dfs(i);
	for(int i=1;i<=cnt;i++)
		for(int j:e[i])
			if(col[i]^col[j])
				in[col[j]]++;
	for(int i=1;i<=tot;i++)
		ans+=!in[i];
	cout<<ans<<"\n";
}