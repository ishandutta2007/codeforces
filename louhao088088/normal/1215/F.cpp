#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
//#define int long long
const int maxn=2e6+5;
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
int n,m,M,p,dfn[maxn],low[maxn],l[maxn],r[maxn],o,x,y,vis[maxn];
int id[maxn],tot=0,cnt=0,top=0,st[maxn],ans[maxn];
vector<int>e[maxn];
void tarjan(int x){
	dfn[x]=++tot;low[x]=dfn[x];st[++top]=x;vis[x]=1;
	for(auto i:e[x]){
		if(!dfn[i])tarjan(i),low[x]=min(low[x],low[i]);
		else if(vis[i])low[x]=min(low[x],dfn[i]);
	}if(low[x]==dfn[x]){
		++cnt;while(st[top]!=x)id[st[top]]=cnt,vis[st[top]]=0,top--;id[x]=cnt;
		top--;vis[x]=0;
	}
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	n=read();p=read();M=read(),m=read();
	for(int i=1;i<=n;i++)
		x=read(),y=read(),e[x+p].pb(y),e[y+p].pb(x);
	for(int i=1;i<=p;i++){
		l[i]=read(),r[i]=read();
		if(l[i]-1>0)e[i].pb(l[i]+2*p-1);
		if(r[i]+1<=M)e[i].pb(r[i]+2*p+M+1);
		e[l[i]+M+2*p].pb(i+p);e[r[i]+2*p].pb(i+p);
	}//e[2*p+1].pb(2*p+M+1),e[2*p+M+1].pb(2*p+1);
	for(int i=1;i<M;i++)e[i+2*p+1].pb(i+2*p),e[i+2*p+M].pb(i+2*p+M+1);
	for(int i=1;i<=m;i++)
		x=read(),y=read(),e[x].pb(y+p),e[y].pb(x+p);
	for(int i=1;i<=2*p;i++)if(!id[i])tarjan(i),top=0;
	for(int i=1;i<=p;i++)if(id[i]==id[i+p])puts("-1"),exit(0);
	//for(int i=1;i<=M;i++)if(id[i+2*p]==id[i+2*p+M])puts("-1"),cout<<i<<endl,exit(0);
	cnt=0;int lx=0,rx=1e9;
	for(int i=1;i<=p;i++)if(id[i]<id[i+p])ans[++cnt]=i;
	for(int i=1;i<=cnt;i++)lx=max(lx,l[ans[i]]),rx=min(rx,r[ans[i]]);
	if(lx>rx)puts("-1"),exit(0);
	cout<<cnt<<" "<<lx<<endl;
	for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
	
 	return 0;
}