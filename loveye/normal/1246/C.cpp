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
int n,m;
char s[N][N];
int dp[N][N][2],len[N],res[N];
int main() {
	cin>>n>>m;
	fr(i,1,n) cin>>&s[i][1];
	if(s[n][m]=='R') return cout<<0<<endl,0;
	if(n==1&&m==1) return cout<<1<<endl,0;
	dp[n][m][0]=dp[n][m][1]=1;
	rf(i,n,1) {
		int z=0,l=0;
		rf(j,m,1) {
			(res[j]+=dp[i+1][j][0])%=MOD;
			if(i==n||s[i+1][j]=='R') (res[j]-=dp[i+1+len[j]][j][0])%=MOD;
			else ++len[j];
			if(i!=n||j!=m) dp[i][j][1]=res[j];
		}
		rf(j,m,1) {
			(z+=dp[i][j+1][1])%=MOD;
			if(j==m||s[i][j+1]=='R') (z-=dp[i][j+1+l][1])%=MOD;
			else ++l;
			if(i!=n||j!=m) dp[i][j][0]=z;
		}
	}
	cout<<((dp[1][1][0]+dp[1][1][1])%MOD+MOD)%MOD<<endl;
	return 0;
}