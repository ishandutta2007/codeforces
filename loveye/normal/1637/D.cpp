#include<cstdio>
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

const int N=105,M=105;
int n,a[N],b[N];
ll dp[N][N*M],sa[N],sb[N];
void chkmin(ll &a,ll b) {if(a>b) a=b;}
int main() {
	int t;cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,n) cin>>a[i],sa[i]=sa[i-1]+a[i];
		fr(i,1,n) cin>>b[i],sb[i]=sb[i-1]+b[i];
		fr(i,0,n) memset(dp[i],0x3f,sizeof dp[i]);
		dp[0][0]=0;
		ll ans=dp[0][1];
		fo(i,0,n) fr(j,0,i*100) if(dp[i][j]<ans) {
			chkmin(dp[i+1][j+a[i+1]],dp[i][j]+1ll*j*a[i+1]+1ll*(sa[i]+sb[i]-j)*b[i+1]);
			chkmin(dp[i+1][j+b[i+1]],dp[i][j]+1ll*j*b[i+1]+1ll*(sa[i]+sb[i]-j)*a[i+1]);
		}
		fr(i,0,n*100) ans=min(ans,dp[n][i]);
		ans*=2;
		fr(i,1,n) ans+=1ll*a[i]*a[i]*(n-1);
		fr(i,1,n) ans+=1ll*b[i]*b[i]*(n-1);
		cout<<ans<<endl;
	}
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