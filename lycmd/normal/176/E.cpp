#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,M=19;
int n,q,cur,ans,dep[N],dfn[N],dis[N],f[N][M];
vector<int>e[N],w[N];
set<pair<int,int> >s;
void dfs(int x,int fa){
	f[x][0]=fa,dfn[x]=++cur;
	for(int i=1;i<M;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y==fa)continue;
		dep[y]=dep[x]+1,dis[y]=dis[x]+w[x][i];
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=M-1;~i;i--)
		if(dep[y]<=dep[f[x][i]])
			x=f[x][i];
	if(x==y)
		return x;
	for(int i=M-1;~i;i--)
		if(f[x][i]^f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dist(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y,k;
		cin>>x>>y>>k;
		e[x].push_back(y);
		e[y].push_back(x);
		w[x].push_back(k);
		w[y].push_back(k);
	}
	dep[1]=1,dfs(1,0);
	cin>>q;
	while(q--){
		char op;int x;cin>>op;
		if(op!='?')cin>>x;
		auto p=make_pair(dfn[x],x);
		switch(op){
			case'?':cout<<ans/2<<"\n";break;
			case'-':{
				auto i=s.lower_bound(p);
				if(s.size()<3){
					s.erase(i),ans=0;
					continue;
				}
				auto l=i,r=i;
				l=l==s.begin()?--s.end():--l;
				r=r==--s.end()?s.begin():++r;
				int al=l->second,ar=r->second;
				ans-=dist(al,x)+dist(ar,x)-dist(al,ar);
				s.erase(i);
				break;
			}
			case'+':{
				if(s.empty()){
					s.insert(p);
				}else if(s.size()==1){
					ans+=2*dist(x,s.begin()->second);
					s.insert(p);
				}else{
					auto i=s.lower_bound(p),l=i,r=i;
					l=l==s.begin()?--s.end():--l;
					r=r==s.end()?s.begin():r;
					int al=l->second,ar=r->second;
					ans+=dist(al,x)+dist(ar,x)-dist(al,ar);
					s.insert(p);
				}
				break;
			}
		}
	}
}