#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

#define y1 asdfsadfsa
const int N=2010;
PII pos[N*N];
VI e[N*N];
int q[N*N],id[N][N],d[N*N];
bool vis[N*N],inq[N*N];
char s[N][N];
int n,m,t,tot;
void draw(int u,int v) {
	int x1=pos[u].fi,y1=pos[u].se,x2=pos[v].fi,y2=pos[v].se;
//	printf("%d %d %d %d\n",x1,y1,x2,y2);
	if (x1==x2) {
		if (y1>y2) swap(y1,y2);
		s[x1][y1]='<'; s[x2][y2]='>';
	} else {
		if (x1>x2) swap(x1,x2);
		s[x1][y1]='^'; s[x2][y2]='v';
	}
}
void del(int u) {
	for (auto v:e[u]) if (!vis[v]) {
		--d[v];
		if (!inq[v]&&d[v]<=1) q[t++]=v,inq[v]=1;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%s",s[i]+1);
	rep(i,1,n+1) rep(j,1,m+1) if (s[i][j]=='.') pos[id[i][j]=tot++]=mp(i,j);
	rep(i,1,n+1) rep(j,1,m+1) if (s[i][j]=='.') {
		if (s[i+1][j]=='.') e[id[i][j]].pb(id[i+1][j]);
		if (s[i-1][j]=='.') e[id[i][j]].pb(id[i-1][j]);
		if (s[i][j+1]=='.') e[id[i][j]].pb(id[i][j+1]);
		if (s[i][j-1]=='.') e[id[i][j]].pb(id[i][j-1]);
	}
	rep(i,0,tot) d[i]=SZ(e[i]);
	rep(i,0,tot) if (d[i]==1) q[t++]=i,inq[i]=1;
	rep(i,0,t) {
		int u=q[i];
		if (vis[u]) continue;
		vis[u]=1;
		del(u);
		for (auto v:e[u]) if (!vis[v]) {
			vis[v]=1; draw(u,v);
			del(v);
		}
	}
	rep(i,1,n+1) rep(j,1,m+1) if (s[i][j]=='.') {
		puts("Not unique");
		return 0;
	}
	rep(i,1,n+1) puts(s[i]+1);
}