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

const int N=5005;
int n,a[N],dp[N][N][3];
int main() {
	scanf("%d",&n);
	fr(i,1,n) scanf("%d",a+i);
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0]=0;
	fr(i,1,n) {
		dp[i][0][0]=0;
		fr(k,1,n+1>>1) {
			dp[i][k][0]=min(dp[i-1][k][0],dp[i-1][k][2]);
			dp[i][k][1]=dp[i-1][k-1][0]+max(0,a[i-1]-a[i]+1);
			if(i>2) dp[i][k][1]=min(dp[i][k][1],
					dp[i-1][k-1][2]-max(0,a[i-1]-a[i-2]+1)+max(0,a[i-1]-min(a[i],a[i-2])+1));
			dp[i][k][2]=dp[i-1][k][1]+max(0,a[i]-a[i-1]+1);
		}
	}
	fr(k,1,n+1>>1) printf("%d ",min(min(dp[n][k][0],dp[n][k][1]),dp[n][k][2]));
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}