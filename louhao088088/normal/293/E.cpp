// LUOGU_RID: 90947068
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
#define int long long
const int maxn=2e5+5,M=2e5+5,mod=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a,b,x,y,k,c[maxn],sz[maxn],rt,dis[maxn],d[maxn],ans=0,z,vis[maxn],mx,tot=0;
vector<pi>e[maxn];pi p[maxn];
void add(int x,int y){x++;for(int i=x;i<=a+1;i+=lowbit(i))c[i]+=y;return;}
int query(int x){int res=0;x++;for(int i=x;i>=1;i-=lowbit(i))res+=c[i];return res;}
void getrt(int x,int fa,int num){
	int mx=0;sz[x]=1;
	for(auto i:e[x])if(i.fi!=fa&&!vis[i.fi]){
		getrt(i.fi,x,num);sz[x]+=sz[i.fi];mx=max(mx,sz[i.fi]);
	}mx=max(num-sz[x],mx);if(mx*2<=num)rt=x;
}
void dfs(int x,int fa){
	sz[x]=1;if(dis[x]<=b)p[++tot]=mp(dis[x],d[x]);
	for(auto i:e[x])if(i.fi!=fa&&!vis[i.fi]){
		dis[i.fi]=dis[x]+i.se;d[i.fi]=d[x]+1;
		dfs(i.fi,x);sz[x]+=sz[i.fi];
	}
}
int getans(int x,int fa,int d1,int d2){
	dis[x]=d1;d[x]=d2;tot=0;dfs(x,fa);
	sort(p+1,p+tot+1);int l=0,sum=0;
	for(int i=1;i<=tot;i++){
		while(l&&p[i].fi+p[l].fi>b)add(p[l].se,-1),l--;
		sum+=query(a-p[i].se);
		if(p[i].fi*2<=b)add(p[i].se,1),l=i;
		
	}
	while(l)add(p[l].se,-1),l--;
	return sum;
}
void solve(int x,int fa){
	vis[x]=1;dis[x]=0;
	ans+=getans(x,fa,0,0);
	for(auto i:e[x])if(i.fi!=fa&&!vis[i.fi]){
		ans-=getans(i.fi,x,i.se,1);
		getrt(i.fi,x,sz[i.fi]);solve(rt,x);
	}
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();a=read(),b=read();
	for(int i=2;i<=n;i++)y=read(),z=read(),e[i].pb(mp(y,z)),e[y].pb(mp(i,z));
	getrt(1,0,n);solve(rt,0);
	cout<<ans<<endl;
 	return 0;
}