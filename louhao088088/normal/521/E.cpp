#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=34005;
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
int n,m,d[maxn],fa[maxn],cx[maxn],cy[maxn],vis[maxn],flag[maxn],x,y,st[maxn],top;vector<int>e[maxn];
int Lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	while(d[x]>d[y])x=fa[x];
	while(x!=y){x=fa[x];y=fa[y];}return x;
}
void print(){
	cout<<top<<" ";
	for(int i=1;i<=top;i++)printf("%d ",st[i]);puts("");
}
void getpath(int x,int y){
	while(x!=y)st[++top]=x,x=fa[x];
	st[++top]=y;
}
void get(int a,int b,int x,int y){
	puts("YES");
	int g=Lca(a,x);if(d[b]>d[y])swap(b,y),swap(a,x);
	//cout<<a<<" "<<b<<" "<<x<<" "<<y<<" "<<g<<endl;
	top=0;getpath(g,y);reverse(st+1,st+top+1);print();
	top=0;getpath(y,b);getpath(a,g);print();
	top=0;st[++top]=y;getpath(x,g);print();
	exit(0);
}
void dfs(int x,int f){
	vis[x]=1;d[x]=d[f]+1;fa[x]=f;flag[x]=1;
	for(auto i:e[x])if(i^fa[x]){
		if(!vis[i])dfs(i,x);
		else if(flag[i]){
			for(int j=x;j!=i;j=fa[j])
				if(cx[j]&&cy[j]) get(cx[j],cy[j],x,i);
				else cx[j]=x,cy[j]=i;
		}
	}flag[x]=0;
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
		x=read(),y=read(),e[x].pb(y),e[y].pb(x);
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
	puts("NO");
 	return 0;
}