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
int n,m,q,a[maxn],f[maxn],g[maxn],ans,x,y,z,l,id[maxn],fa[maxn],F[maxn],w[maxn];
vector<pi>e[maxn];
int find(int x){if(x==fa[x])return x;return fa[x]=find(fa[x]);}
void dfs(int x,int fa){
	for(auto i:e[x])if(i.fi^fa){dfs(i.fi,x);
		if(f[i.fi]+i.se>f[x])g[x]=f[x],f[x]=f[i.fi]+i.se;
		else g[x]=max(g[x],f[i.fi]+i.se);
	}
}
void dfs1(int x,int fa){
	for(auto i:e[x])if(i.fi^fa){
		if(f[x]!=f[i.fi]+i.se)f[i.fi]=f[x]+i.se;
		else if(g[x]+i.se>f[i.fi])f[i.fi]=g[x]+i.se;
		else g[i.fi]=max(g[x]+i.se,g[i.fi]);
		dfs1(i.fi,x);
	}
}
bool cmp(int x,int y){return f[x]>f[y];}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)x=read(),y=read(),z=read(),e[x].pb(mp(y,z)),e[y].pb(mp(x,z));
	dfs(1,0);dfs1(1,0);
	for(int i=1;i<=n;i++)id[i]=i;
	
	for(int i=1;i<=n;i++)
		for(auto j:e[i])if(f[j.fi]>f[i])F[j.fi]=i;else F[i]=j.fi;
	sort(id+1,id+n+1,cmp);q=read();
	while(q--){
		x=read();l=1;ans=0;
		for(int i=0;i<=n;i++)fa[i]=i,w[i]=1;
		for(int i=1;i<=n;i++){
			while(f[id[l]]>f[id[i]]+x)w[find(id[l])]--,l++;
			fa[id[i]]=F[id[i]];w[F[id[i]]]+=w[id[i]];ans=max(ans,w[id[i]]);
		}cout<<ans<<endl;
	}
 	return 0;
}