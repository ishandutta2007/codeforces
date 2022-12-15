#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=3e5+10;
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
int n,cnt=1,rt;
struct edge{
	int r,nxt;
}e[N];
int hed[N];
void insert(int u,int v){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;
}
bool vis[N];
int siz[N],son[N];
LL ans=0;
void dfs(int u){
	vis[u]=1;siz[u]=1;
	for(int i=hed[u];i;i=e[i].nxt){
		if(vis[e[i].r]) continue;
		dfs(e[i].r);
		siz[u]+=siz[e[i].r];
		if(siz[e[i].r]>siz[son[u]]) son[u]=e[i].r;
	}
}
int fa[N];
void getans(int u){
	siz[u]=1;
	for(int i=hed[u];i;i=e[i].nxt)
		if(fa[u]!=e[i].r){
			fa[e[i].r]=u;
			getans(e[i].r);
			siz[u]+=siz[e[i].r];
			if(siz[e[i].r]>siz[son[u]]) son[u]=e[i].r;
			ans=ans+(LL)2*(LL)min(siz[e[i].r],n-siz[e[i].r]);
		}
}
vector<int> ve;
bool cmp(int A,int B){return siz[A]>siz[B];}
int t1=0,t2=0;
int p1[N],p2[N],p[N];
void dfs2(int u,int *p,int &top){
	p[++top]=u;
	for(int i=hed[u];i;i=e[i].nxt)
		if(fa[u]!=e[i].r) dfs2(e[i].r,p,top);
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		insert(u,v);insert(v,u);
	}
	dfs(1);
	for(int i=1;i<=n;++i){
		u=max(siz[son[i]],n-siz[i]);
		if(u<=(n/2)) {rt=i;break;}
	}
	memset(siz,0,sizeof(siz));
	memset(son,0,sizeof(son));
	getans(rt);
	printf("%I64d\n",ans);
	for(int i=hed[rt];i;i=e[i].nxt) ve.push_back(e[i].r);
	sort(ve.begin(),ve.end(),cmp);
	for(int i=0;i<ve.size();++i) dfs2(ve[i],p1,t1);
	p1[++t1]=rt;
	for(int i=1;i<ve.size();++i) dfs2(ve[i],p2,t2);
	p2[++t2]=rt;dfs2(ve[0],p2,t2);
	for(int i=1;i<=t1;++i) p[p1[i]]=p2[i];
	for(int i=1;i<=n;++i) printf("%d ",p[i]);puts("");
	return 0;
}