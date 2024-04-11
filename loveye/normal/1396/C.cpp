#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e6+5;
int n,a[N];
ll dp[N][2];
ll r1,r2,r3,d;
ll W1(int i) {return min(1ll*(a[i]+2)*r1,r2+r1);}
ll W2(int i) {return 1ll*a[i]*r1+r3;}
int main() {
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	fr(i,1,n) scanf("%d",a+i);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	fr(i,1,n) {
		dp[i][0]=dp[i-1][0]+min(W2(i),W1(i)+2*d);
		if(i>1) dp[i][0]=min(dp[i][0],dp[i-2][0]+W1(i)+2*d+W1(i-1));
		if(i<n) {
			dp[i][1]=dp[i-1][1]+min(W2(i),W1(i));
			dp[i][1]=min(dp[i][1],dp[i-1][0]+1ll*(n-i)*d+W1(i));
		} else dp[i][1]=dp[i-1][1]+min(W2(i),W1(i)+2*d);
	}
	printf("%lld\n",min(dp[n][0],dp[n][1])+1ll*(n-1)*d);
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}