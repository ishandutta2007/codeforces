#include<bits/stdc++.h>
using namespace std;
int const N=300010;
int n,m,q,f[N],d[N],vis[N];
vector<int>e[N];
struct dsu{
	int f[N],v[N];
	void init(int n){
		for(int i=1;i<=n;i++)
			f[i]=i,v[i]=0;
	}
	int find(int x){
		return x^f[x]?f[x]=find(f[x]):x;
	}
	int check(int x,int y){
		return find(x)==find(y);
	}
	int isr(int x){
		return f[x]==x;
	}
	int merge(int x,int y){
		int a=find(x),b=find(y);
		return a^b?(v[f[a]=b]=max((v[a]+1)/2+(v[b]+1)/2+1,
			max(v[a],v[b])),1):0;
	}
};
dsu g;
int getdia(int x,int fa){
	f[x]=d[x]=0;
	int mx1=0,mx2=0;
	for(int y:e[x]){
		if(y==fa)continue;
		f[x]=max(f[x],getdia(y,x));
		int t=d[y]+1;
		d[x]=max(d[x],t);
		if(t>mx1)mx2=mx1,mx1=t;
		else if(t>mx2)mx2=t;
	}
	return f[x]=max(f[x],mx1+mx2);
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m>>q,g.init(n);m--;){
		int x,y;cin>>x>>y;g.merge(x,y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(g.isr(i))
			g.v[i]=getdia(i,0);
	while(q--){
		int op,x,y;cin>>op>>x;
		if(op<2)cout<<g.v[g.find(x)]<<"\n";
		else cin>>y,g.merge(x,y);
	}
}