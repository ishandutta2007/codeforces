//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=200005;int n,K,sq[N],sc[N][17],ps[N][17],dp[1<<17];char ch[N];
inline char chk(int x)
{
	memset(ps[n+2],0x3f,sizeof(ps[n+2]));for(int k=0;k<K;k++) for(int i=n+1;i;i--)
		ps[i][k]=(i+x-1<=n&&sq[i+x-1]-sq[i-1]+sc[i+x-1][k]-sc[i-1][k]==x)?i+x-1:ps[i+1][k];
	dp[0]=1;for(int i=1;i<(1<<K);i++) dp[i]=n+2;
	for(int S=1;S<(1<<K);S++) for(int i=0;i<K;i++)
		if((S>>i)&1) dp[S]=min(dp[S],ps[dp[S^(1<<i)]][i]+1);
	return dp[(1<<K)-1]<=n+1;
}
int main()
{
	read(n),read(K),scanf("%s",ch+1);for(int i=1;i<=n;i++) sq[i]=sq[i-1]+(ch[i]=='?');
	for(int i=1;i<=n;i++) {memcpy(sc[i],sc[i-1],sizeof(sc[i]));if(ch[i]!='?') sc[i][ch[i]-'a']++;}
	int l=0,r=n/K,rs=0;while(l<=r) {int md=(l+r)>>1;if(chk(md)) rs=md,l=md+1;else r=md-1;}
	return printf("%d\n",rs),0;
}