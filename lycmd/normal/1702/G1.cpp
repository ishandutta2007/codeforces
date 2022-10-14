#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=500010,B=23,INF=0x3f3f3f3f3f3f3f3fll;
int n,q,cur,dfn[N],p[N],dep[N],fa[N][B],vis[N];
vector<int>e[N],g[N];
stack<int>s;
void dfs(int x,int pre){
	dep[x]=dep[pre]+1,dfn[x]=++cur;
	for(int i=1;;i++)
		if(!(fa[x][i]=fa[fa[x][i-1]][i-1]))
			break;
	for(int y:e[x]){
		if(y==pre)continue;
		dfs(y,fa[y][0]=x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=B-1;~i;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for(int i=B-1;~i;i--)
		if(fa[x][i]^fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int solve(int x,int fa){
	int flg=g[x].size()+!!fa<3;
	for(int y:g[x])
		flg&=solve(y,x);
	vis[x]=0,g[x].clear();
	return flg;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,
		e[x].push_back(y),
		e[y].push_back(x);
	dfs(1,0),s.push(0);
	for(cin>>q;q--;){
		int m;cin>>m;
		for(int i=1;i<=m;i++)
			cin>>p[i],vis[p[i]]=1;
		sort(p+1,p+1+m,[&](int x,int y){
			return dfn[x]<dfn[y];
		});
		s.push(p[1]);
		for(int i=2;i<=m;i++){
			int a=lca(p[i],s.top());
			for(;;){
				int x=s.top(),y=(s.pop(),s.top());
				s.push(x);
				if(dep[a]<dep[y]){
					g[y].push_back(x),s.pop();
				}else{
					if(a!=x){
						g[a].push_back(x),s.pop();
						if(a!=y)s.push(a);
					}
					break;
				}
			}
			s.push(p[i]);
		}
		while(s.size()>2){
			int x=s.top(),y=(s.pop(),s.top());
			g[y].push_back(x);
		}
		cout<<(solve(s.top(),0)?"YES\n":"NO\n"),s.pop();
	}
}
//