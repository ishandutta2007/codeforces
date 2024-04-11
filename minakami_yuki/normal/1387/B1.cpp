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
int n,cnt=1;
struct edge{
	int r,nxt;
}e[N];
int hed[N];
void insert(int u,int v){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;
}
LL ans=0;
int p[N],fa[N];
void dfs(int u){
	for(int i=hed[u];i;i=e[i].nxt){
		if(e[i].r==fa[u])continue;
		fa[e[i].r]=u;
		dfs(e[i].r);
	}
	if(p[u]==u&&fa[u]){
		ans+=2;
		swap(p[u],p[fa[u]]);
	}
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		insert(u,v);insert(v,u);
	}
	for(int i=1;i<=n;++i) p[i]=i;
	dfs(1);
	if(p[1]==1) {
		v=e[hed[1]].r;
		ans+=2;
		swap(p[1],p[v]);
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;++i) printf("%d ",p[i]);puts("");
	return 0;
}