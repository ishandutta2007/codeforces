#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> node;
int const N=1000010;
int n,m,k,ans,c[N],flg[N];
struct dsu{
	int f[N],h[N];
	stack<node>s;
	void init(int n){
		for(int i=1;i<=n;i++)
			f[i]=i,h[i]=1;
	}
	int find(int x){
		return x^f[x]?find(f[x]):x;
	}
	int check(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx==fy)
			return;
		if(h[fx]>h[fy])
			swap(fx,fy);
		s.push({fx,h[fx]==h[fy]});
		h[fy]+=h[fx]==h[fy],f[fx]=fy;
	}
	void undo(){
		node t=s.top();s.pop();
		int x=t.first;
		h[f[x]]-=t.second,f[x]=x;
	}
	int add_edge(int x,int y){
		return check(x,y)?0:(merge(x,y+n),merge(x+n,y),1);
	}
};
dsu g;
map<node,vector<node> >e; 
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k,g.init(n*2);
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int x,y;m--;){
		cin>>x>>y;
		if(c[x]>c[y])
			swap(x,y);
		if(c[x]==c[y])
			flg[c[x]]|=!g.add_edge(x,y);
		else
			e[{c[x],c[y]}].push_back({x,y});
	}
	for(int i=1;i<=k;i++)
		ans+=!flg[i];
	ans=ans*(ans-1)/2;
	int w=g.s.size();
	for(auto[t,v]:e){
		auto[x,y]=t;
		if(flg[x]||flg[y])
			continue;
		for(auto i:v)
			if(!g.add_edge(i.first,i.second)){
				ans--;break;
			}
		while(g.s.size()>w)
			g.undo();
	}
	cout<<ans<<"\n";
}