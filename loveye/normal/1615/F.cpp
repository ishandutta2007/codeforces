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

const int N=2005,MOD=1e9+7;
int T,n;
char s[N],t[N];
ll _dp[N][2][N<<1],*dp[N][2];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s%s",&n,s+1,t+1);
		for(int i=1;i<=n;i+=2) if(s[i]!='?') s[i]^=1;
		for(int i=1;i<=n;i+=2) if(t[i]!='?') t[i]^=1;
		fr(i,0,n) {
			dp[i][0]=&_dp[i][0][N];
			dp[i][1]=&_dp[i][1][N];
		}
		dp[0][0][0]=1; dp[0][1][0]=0;
		fo(i,0,n) fr(j,-i,i) if(dp[i][0][j]||dp[i][1][j]) {
			fo(o1,0,2) if(s[i+1]=='?'||s[i+1]-'0'==o1)
				fo(o2,0,2) if(t[i+1]=='?'||t[i+1]-'0'==o2) {
					(dp[i+1][0][j+o1-o2]+=dp[i][0][j])%=MOD;
					if(o1&&o2) (dp[i+1][1][j]+=dp[i][1][j])%=MOD;
					else (dp[i+1][1][j+o1-o2]+=dp[i][1][j]+dp[i][0][j]*(o1*(j>=0?-i-1:i+1)+o2*(j<=0?-i-1:i+1)))%=MOD;
				}
		}
		printf("%lld\n",(dp[n][1][0]+MOD)%MOD);
		fr(i,0,n) fr(j,-i,i) dp[i][0][j]=dp[i][1][j]=0;
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