#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
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
#define N 100009
#define M 209
#define mod 1000000007
using namespace std;

int n,m,tot,bin[N],fst[N],pnt[N<<1],nxt[N<<1];
int sz[N],fa[N],cbn[M][M],f[M][M],dp[N][M][2],c[M][2];
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
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;	
}
void mrg(int a[][2],int b[][2],int u,int v,int w,int t){
	memset(c,0,sizeof(c));
	int i,j,tmp;
	for (i=1; i<=u; i++)
		for (j=1; j<=v && i+j<=m; j++){
			tmp=(ll)a[i][1]*b[j][1]%mod;
			ad(c[i+j][0],tmp); ad(c[i+j][1],tmp);
		}
	for (i=1; i<=u; i++){
		tmp=(ll)a[i][1]*(bin[t]-1)%mod;
		ad(c[i][0],tmp); ad(c[i][1],tmp);
		ad(c[i][0],a[i][0]); ad(c[i][1],a[i][1]);
	}
	for (i=1; i<=v; i++){
		tmp=(ll)(bin[w]-1)*b[i][1]%mod;
		ad(c[i][0],tmp); ad(c[i][1],tmp);
		ad(c[i][0],b[i][0]); ad(c[i][1],b[i][1]);
	}
}
void dfs(int x){
	int i,j,y;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]){
			fa[y]=x; dfs(y);
			for (j=min(m,sz[y]); j>1; j--)
				ad(dp[y][j][1],dp[y][j-1][1]);
			ad(dp[y][1][1],bin[sz[y]]-1);
			mrg(dp[x],dp[y],min(m,sz[x]),min(m,sz[y]),sz[x],sz[y]);
			sz[x]+=sz[y];
			memcpy(dp[x],c,sizeof(c));
		}
	}
	for (j=1; j<=sz[x] && j<=m; j++){
		ad(dp[x][j][0],dp[x][j][1]);
		ad(dp[x][j][1],dp[x][j][1]);
	}
	//for (j=1; j<=sz[x] && j<=m; j++) cerr<<x<<' '<<j<<' '<<dp[x][j][0]<<' '<<dp[x][j][1]<<'\n';
	//cerr<<'\n';
	sz[x]++;
}
int main(){
	n=read(); m=read();
	int i,j,k,x,y;
	for (i=1; i<n; i++){
		x=read(); y=read();
		add(x,y); add(y,x);	
	}
	for (i=bin[0]=1; i<=n; i++) bin[i]=bin[i-1]*2%mod;
	for (i=0; i<=m; i++)
		for (j=cbn[i][0]=1; j<=i; j++) cbn[i][j]=(cbn[i-1][j]+cbn[i-1][j-1])%mod;
	f[0][0]=1;
	for (i=1; i<=m; i++)
		for (j=1; j<=i; j++)
			for (k=j-1; k<i; k++) ad(f[i][j],(ll)cbn[i][k]*f[k][j-1]);
	dfs(1);
	int ans=0;
	for (i=1; i<n && i<=m; i++){
		ad(ans,(ll)f[m][i]*dp[1][i][0]);
	//	cerr<<f[m][i]<<'\n';
	}
	printf("%d\n",ans);
	return 0;
}