#include<bits/stdc++.h>
using namespace std;
int const N=100010,B=23,INF=0x3f3f3f3f;
int n,q,m,cur,sum,mx,mn,dfn[N],p[N],dep[N],fa[N][B],vis[N],f[N];
vector<int>e[N],g[N];
stack<int>s;
void dfs(int x,int pre){
	dep[x]=dep[pre]+1,dfn[x]=++cur;
	for(int i=1;;i++)
		if(!(fa[x][i]=fa[fa[x][i-1]][i-1]))
			break;
	for(int y:e[x])
		if(y^pre)
			dfs(y,fa[y][0]=x);
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
int solve(int x){
	int res=0,cnt=0;
	for(int y:g[x])
		res+=solve(y),cnt+=f[y];
	if(vis[x])
		res+=cnt,f[x]=1;
	else if(cnt>1)
		res++,f[x]=0;
	else f[x]=cnt;
	vis[x]=0,g[x].clear();
	return res;
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
		cin>>m;
		int flg=0;
		for(int i=1;i<=m;i++)
			cin>>p[i],vis[p[i]]=1;
		for(int i=1;i<=m;i++)
			flg|=vis[fa[p[i]][0]];
		if(flg){
			for(int i=1;i<=m;i++)
				vis[p[i]]=0;
			cout<<"-1\n";
			continue;
		}
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
		cout<<solve(s.top())<<"\n",s.pop();
	}
}