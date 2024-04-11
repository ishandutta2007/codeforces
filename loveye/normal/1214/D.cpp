#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e6+5,MOD=957504827;
int n,m;
string s[N];
vector<ll> dp1[N],dp2[N];
/*typedef pair<int,int> pii;
#define fi first
#define se second
queue<pii> q;
void bfs() {
	q.push(pii(n,m));
	vis[n][m]=1;
	while(!q.empty()) {
		pii u=q.front(); q.pop();
		int tx=u.fi-1,ty=u.se;
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty]&&s[tx][ty]!='#')
			q.push(pii(tx,ty)),vis[tx][ty]=1;
		tx=u.fi,ty=u.se-1;
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty]&&s[tx][ty]!='#')
			q.push(pii(tx,ty)),vis[tx][ty]=1;
	}
}*/
int main() {
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	fr(i,1,n) {
		cin>>s[i];
		s[i].insert(s[i].begin(),'\0');
	}
	fr(i,0,n+1) {
		dp1[i].resize(m+2);
		dp2[i].resize(m+2);
	}
	dp1[1][1]=1;
	fr(i,1,n) fr(j,1,m) if(s[i][j]!='#'&&(i!=1||j!=1))
		dp1[i][j]=(dp1[i-1][j]+dp1[i][j-1])%MOD;
	dp2[n][m]=1;
	rf(i,n,1) rf(j,m,1) if(s[i][j]!='#'&&(i!=n||j!=m))
		dp2[i][j]=(dp2[i+1][j]+dp2[i][j+1])%MOD;
	if(!dp2[1][1]) return puts("0"),0;
	fr(i,1,n) fr(j,1,m) if((i!=1||j!=1)&&(i!=n||j!=m))
		if(1ll*dp1[i][j]*dp2[i][j]%MOD==dp2[1][1])
			return puts("1"),0;
	puts("2");
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}