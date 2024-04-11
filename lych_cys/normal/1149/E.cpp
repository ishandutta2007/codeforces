#include<bits/stdc++.h>
#define ll long long
#define inf 1010000000
#define infll 1010000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 200009
using namespace std;

int n,m,a[N],h[N],q[N],d[N],s[N],sg[N],bo[N];
vi e[N]; bool vis[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int dfs(int x){
	if (vis[x]) return sg[x]; vis[x]=1;
	for (int y:e[x]) sg[y]=dfs(y);
	for (int y:e[x]) bo[sg[y]]=x;
	for (sg[x]=0; bo[sg[x]]==x; sg[x]++);
	s[sg[x]]^=a[x]; return sg[x];
}
int main(){
	scanf("%d%d",&n,&m);
	int i,x,y;
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	for (i=1; i<=m; i++){
		scanf("%d%d",&x,&y);
		e[x].pb(y); d[y]++;	
	}
	for (i=1; i<=n; i++) sg[i]=dfs(i);
	for (i=n; i>=0; i--) if (s[i]) break;
	if (i==-1){ puts("LOSE"); return 0; }
	x=i;
	memset(vis,0,sizeof(vis));
	for (i=1; i<=n; i++) if (sg[i]==x && (a[i]^s[x])<a[i]){
		a[i]^=s[x];
		for (int p:e[i]){
			if (vis[sg[p]]) continue; vis[sg[p]]=1;
			a[p]^=s[sg[p]];
		}
		break;
	}
	puts("WIN");
	for (i=1; i<=n; i++) printf("%d%c",a[i],i<n?' ':'\n');
	return 0;
}