#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
const int maxn=1e6+5,M=34005;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,k,q,a[maxn],u[maxn],v[maxn],p[maxn],fa[51][maxn],sz[51][maxn],col[maxn],c[maxn],tot=0;
vector<int>g[maxn*2];struct node{int x,y,c;}st[maxn*5];
int find(int x,int y){while(y!=fa[x][y])y=fa[x][y];return y;}
void merge(int c,int x,int y){
	x=find(c,x),y=find(c,y);if(x==y)return;
	if(sz[c][x]>sz[c][y])swap(x,y);sz[c][y]+=sz[c][x];fa[c][x]=y;st[++tot]={x,y,c};
}
void del(int x,int y,int c){sz[c][y]-=sz[c][x],fa[c][x]=x;}
void add(int rt,int l,int r,int L,int R,int id){
	if(l>R||r<L)return;if(L>R)return;
	if(l>=L&&r<=R){g[rt].pb(id);return;}
	add(ls,l,mid,L,R,id),add(rs,mid+1,r,L,R,id);
}
void solve(int rt,int l,int r){
	int o=tot;
	for(auto i:g[rt])merge(c[i],u[a[i]],v[a[i]]+n),merge(c[i],u[a[i]]+n,v[a[i]]);
	if(l==r){
		if(find(c[l],u[a[l]])==find(c[l],v[a[l]]))puts("NO"),c[l]=col[a[l]];
		else col[a[l]]=c[l],puts("YES");return;
	}
	solve(ls,l,mid),solve(rs,mid+1,r);
	for(int i=tot;i>o;i--)del(st[i].x,st[i].y,st[i].c);tot=o;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),k=read(),q=read();
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n*2;j++)
			fa[i][j]=j,sz[i][j]=1;
	for(int i=1;i<=m;i++)u[i]=read(),v[i]=read(),p[i]=q+1;
	for(int i=1;i<=q;i++)a[i]=read(),c[i]=read();
	for(int i=q;i>=1;i--){
		if(i<p[a[i]]-1)add(1,1,q,i+1,p[a[i]]-1,i);p[a[i]]=i;
	}solve(1,1,q);
 	return 0;
}