#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,m,cnt,tot=1,cur,hd[N],to[N],nxt[N],deg[N],vis[N];
vector<int>t;
void add(int x,int y){
	deg[x]++,to[++tot]=y,nxt[tot]=hd[x],hd[x]=tot;
}
void dfs(int x){
	for(int&i=hd[x];i;i=nxt[i]){
		if(vis[i])continue;
		vis[i]=vis[i^1]=1;
		int y=to[i];dfs(y);
		cur++&1?cout<<x<<" "<<y<<"\n":cout<<y<<" "<<x<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int t=m;t--;){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(deg[i]&1)
			t.push_back(i);
	for(int i=0;i<t.size();i+=2)
		add(t[i],t[i+1]),add(t[i+1],t[i]),m++;
	if(m&1)add(1,1),add(1,1),m++;
	cout<<m<<"\n",dfs(1);
}