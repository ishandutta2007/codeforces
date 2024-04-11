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
const int N=2e5+10;
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
int n,m,cnt=1;
int hed[N],p[N],h[N],vis[N],siz[N],A[N],B[N];
bool flag;
struct edge{
	int r,nxt;
}e[N<<1];
void insert(int u,int v){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;
}
void J(int x){
	vis[x]=1;
	siz[x]=p[x];
	int aa=0,bb=0;
	for(int i=hed[x];i;i=e[i].nxt){
		if(vis[e[i].r]) continue;
		J(e[i].r);
		siz[x]+=siz[e[i].r];
		aa+=A[e[i].r];bb+=B[e[i].r];
	}
	if((h[x]+siz[x])%2!=0) {
		//cout<<x<<endl;
		flag=0;
		return;
	}
	A[x]=(h[x]+siz[x])/2;
	B[x]=siz[x]-A[x];
	if(A[x]<0||B[x]<0) flag=0;
	if(aa>A[x]) {
		flag=0;
	}
}
int main(){
	int T,u,v;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);cnt=1;
		for(int i=1;i<=n;++i) scanf("%d",&p[i]);
		for(int i=1;i<=n;++i) scanf("%d",&h[i]);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			insert(u,v);insert(v,u);
		}
		flag=1;
		J(1);
		//for(int i=1;i<=n;++i) cout<<siz[i]<<" ";puts("");
		if(!flag) printf("NO\n");
		else printf("YES\n");
		for(int i=1;i<=n;++i){
			hed[i]=p[i]=h[i]=vis[i]=siz[i]=A[i]=B[i]=0;
		}
	}
	return 0;
}