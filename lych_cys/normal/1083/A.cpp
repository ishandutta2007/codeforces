#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 300009
using namespace std;

int n,tot,fa[N],a[N],fst[N],pnt[N<<1],nxt[N<<1],len[N<<1]; ll ans,d[N];
void add(int x,int y,int z){
	pnt[++tot]=y; len[tot]=z; nxt[tot]=fst[x]; fst[x]=tot;
}
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void dfs(int x){
	int i,y; d[x]=a[x];
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]){
			fa[y]=x; dfs(y);
			ans=max(ans,d[x]+d[y]-len[i]);
			d[x]=max(d[x],a[x]+d[y]-len[i]);
		}
	}
}
int main(){
	n=read();
	int i,x,y,z;
	for (i=1; i<=n; i++){
		a[i]=read(); ans=max(ans,(ll)a[i]);
	}
	for (i=1; i<n; i++){
		x=read(); y=read(); z=read();
		add(x,y,z); add(y,x,z);
	}
	//ans=-1000000000000000000ll;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}