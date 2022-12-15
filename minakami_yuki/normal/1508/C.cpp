#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LD INF=2e12;
const int N=3e5+10;
const LL P=1e9+7;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
void get_min(int &x,int y){
    if(x>y) x=y;
}
int n,m;
struct edge{
	int l,r;
	LL v;
}e[N];
bool cmp(edge x,edge y){
	return x.v<y.v;
}
int fa[N],nxt[N];
map<int,int> mp[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int NXT(int x){
	return nxt[x]==x?x:nxt[x]=NXT(nxt[x]); 
}
void dfs(int x,int y){
	fa[x]=y;
	nxt[x]=x+1;
	int i=1,j;
	while(i<=n){
		j=NXT(i);
		if(j!=i){
			i=j;
			continue;
		}
		if(mp[x][i]==0){
			dfs(i,y);
		}
		else{
			i++;
		}
	}
	return;
}
bool vis[N];
vector<int> R[N];
int F[N],dep[N];
void DP(int x){
	for(int i=0;i<R[x].size();++i){
		if(R[x][i]!=F[x]){
			F[R[x][i]]=x;
			dep[R[x][i]]=dep[x]+1;
			DP(R[x][i]);
		}
	}
}
bool p[700][700];
void MAIN(){
	int u,v;
	LL res=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&e[i].l,&e[i].r,&e[i].v);
		res=res^e[i].v;
		mp[e[i].l][e[i].r]=1;
		mp[e[i].r][e[i].l]=1;
	}
	LL las=(LL)n*(LL)(n-1)/(LL)2-(LL)m;
	bool flag=0;
	if(las>=n) flag=1;
	else {
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(mp[i][j]==0){
					u=find(i);
					v=find(j);
					if(u==v){
						flag=1;
						break;
					}
					fa[u]=v;
				}
			}
		}
	}
	sort(e+1,e+1+m,cmp);
	LL ans=0;
	for(int i=1;i<=n;++i) {
		nxt[i]=i;
	}
	nxt[n+1]=n+1;
	for(int i=1;i<=n;++i){
		if(NXT(i)==i){
			dfs(i,i);
		}
	}
	if(flag){
		for(int i=1;i<=m;++i){
			u=find(e[i].l);
			v=find(e[i].r);
			if(u==v) continue;
			ans+=e[i].v;
			fa[u]=v;
		}
		printf("%lld\n",ans);
		return;
	}
	for(int i=1;i<=m;++i){
		u=find(e[i].l);
		v=find(e[i].r);
		if(u==v) continue;
		ans+=e[i].v;
		fa[u]=v;
		R[e[i].l].push_back(e[i].r);
		R[e[i].r].push_back(e[i].l);
	}
	for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(mp[i][j]==0){
					R[i].push_back(j);
					R[j].push_back(i);
				}
				p[i][j]=p[j][i]=mp[i][j];
			}
	}
	DP(1);
	bool f;
	for(int i=1;i<=m;++i){
		if(e[i].v>=res) continue;
		u=e[i].l;
		v=e[i].r;
		f=0;
		while(u!=v){
			if(dep[u]<dep[v]) swap(u,v);
			if(p[u][F[u]]==0){
				f=1;break;
			}
			u=F[u];
		}
		if(f){
			res=min(res,e[i].v);
		}
	}
	ans=ans+res;
	//cout<<ans<<" "<<res<<endl;
	printf("%lld\n",ans);
	return;
}
int main(){
    int T=1;//scanf("%d",&T);
    while(T--) MAIN();
	return 0;
}