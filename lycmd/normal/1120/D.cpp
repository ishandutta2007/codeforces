#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int n,m,res,cur,a[N],ldfn[N],rdfn[N];
vector<int>e[N],ans;
struct edge{
	int x,y,w,id;
	int operator<(const edge&rhs)const{
		return w<rhs.w;
	}
};
struct dsu{
	int f[N];
	void init(int n){
		for(int i=0;i<=n;i++)
			f[i]=i;
	}
	int find(int x){
		return x^f[x]?f[x]=find(f[x]):x;
	}
	int check(int x,int y){
		return find(x)==find(y);
	}
	int merge(int x,int y){
		int fx=find(x),fy=find(y);
		return fx^fy?(f[fx]=fy,1):0;
	}
};
vector<edge>g;
dsu s;
void dfs(int x,int fa){
	ldfn[x]=cur,cur+=x>1&&e[x].size()==1;
	for(int y:e[x])
		if(y^fa)
			dfs(y,x);
	rdfn[x]=cur;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		g.push_back({ldfn[i],rdfn[i],a[i],i});
	sort(g.begin(),g.end());
	s.init(n);
	for(edge i:g)
		if(s.merge(i.x,i.y))
			res+=i.w;
	s.init(n);
	for(int i=0;i<g.size();){
		int j=i;
		while(j<g.size()&&g[j].w==g[i].w)j++;
		for(int p=i;p<j;p++)
			if(!s.check(g[p].x,g[p].y))
				ans.push_back(g[p].id);
		for(int p=i;p<j;p++)
			s.merge(g[p].x,g[p].y);
		i=j;
	}
	sort(ans.begin(),ans.end());
	cout<<res<<" "<<ans.size()<<"\n";
	for(int x:ans)cout<<x<<" ";
}