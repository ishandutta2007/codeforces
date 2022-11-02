#include<cstdio>
#include<vector>
#include<set>
using namespace std;
const int N=800002;
int n,m,i,j,k,a,b,c,h[N],t[N],v[N],w[N];
int st[N],tp,vis[N],dfn[N],low[N],Tim,cnt;
vector<int>grp[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
int min(int x,int y){
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
void dfs(int i,int fa){
	vis[i]=1;
	dfn[i]=low[i]=++Tim;
	for(int j=h[i],k;j;j=t[j])
		if(v[j]!=fa){
			if(!vis[v[j]]){
				st[++tp]=v[j];
				dfs(v[j],i);
				low[i]=min(low[i],low[v[j]]);
				if(dfn[i]<=low[v[j]]){
					cnt++;
					do{
						k=st[tp--];
						grp[k].push_back(cnt);
					}
					while(k!=v[j]);
					grp[i].push_back(cnt);
				}
			}
			else
				low[i]=min(low[i],dfn[v[j]]);
		}
}
vector<int>p[N];
int dep[N],sz[N],fa[N],top[N],e[N],id[N];
int D,Tr[N],q,ans1,ans2,x,y;
multiset<int>val[N];
void ADD(int a,int b){
	p[a].push_back(b);
	p[b].push_back(a);
}
void init(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		scanf("%d",w+i);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,0);
	for(i=1;i<=cnt;i++)
		val[i].insert(1<<30);
	for(i=1;i<=n;i++){
		id[i]=i+cnt;
		for(j=0;j<grp[i].size();j++)
			ADD(id[i],grp[i][j]);
	}
	for(D=1;D<id[n]+2;D<<=1);
}
void dfs1(int i){
	sz[i]=1;
	for(int j=0,k;j<p[i].size();j++){
		k=p[i][j];
		if(k!=fa[i]){
			fa[k]=i;
			dep[k]=dep[i]+1;
			dfs1(k);
			sz[i]+=sz[k];
			if(sz[k]>sz[e[i]])
				e[i]=k;
		}
	}
}
void dfs2(int i){
	dfn[i]=++Tim;
	if(e[i]){
		top[e[i]]=top[i];
		dfs2(e[i]);
	}
	for(int j=0,k;j<p[i].size();j++){
		k=p[i][j];
		if(k!=fa[i]&&k!=e[i]){
			top[k]=k;
			dfs2(k);
		}
	}
}
void Update(int x,int y){
	Tr[x+=D]=y;
	while(x>>=1)
		Tr[x]=min(Tr[x<<1],Tr[x<<1|1]);
}
int Query(int x,int y){
	int s=1<<30;
	for(x+=D-1,y+=D+1;x^y^1;x>>=1,y>>=1){
		if(~x&1)s=min(s,Tr[x^1]);
		if(y&1)s=min(s,Tr[y^1]);
	}
	return s;
}
char s[3];
void work(){
	for(i=1;i<=n;i++){
		Update(dfn[id[i]],w[i]);
		j=fa[id[i]];
		val[j].insert(w[i]);
		Update(dfn[j],*val[j].lower_bound(0));
	}
//	scanf("%d",&q);
	while(q--){
		scanf("%s%d%d",s,&a,&b);
		x=a;y=b;
		if(*s=='C'){
			c=fa[id[a]];
			val[c].erase(val[c].lower_bound(w[a]));
			w[a]=b;
			val[c].insert(w[a]);
			Update(dfn[id[a]],b);
			Update(dfn[c],*val[c].lower_bound(0));
		}
		else{
			ans1=w[a];
			ans2=1<<30;
			a=id[a];
			b=id[b];
			while(top[a]!=top[b]){
				if(dep[top[a]]>dep[top[b]])
					ans2=min(ans2,Query(dfn[top[a]],dfn[a])),
					a=fa[top[a]];
				else
					ans2=min(ans2,Query(dfn[top[b]],dfn[b])),
					b=fa[top[b]];
			}
			if(dep[a]>dep[b])
				ans2=min(ans2,Query(dfn[b],dfn[a]));
			else
				ans2=min(ans2,Query(dfn[a],dfn[b]));
			a=dep[a]<dep[b]?a:b;
			if(a!=1&&a<=cnt){
				ans2=min(ans2,Query(dfn[fa[a]],dfn[fa[a]]));
			}
			printf("%d\n",ans2);
		}
	}
}
int main(){
	init();
	dfs1(1);
	Tim=0;
	top[1]=1;
	dfs2(1);
	work();
}