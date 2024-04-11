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
const int P=1e9+7;char ch[1005];int fc[1005],fi[1005],K,n,dp[1005],sz[1005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	scanf("%s",ch),n=strlen(ch),read(K);if(!K) return puts("1"),0;
	fc[0]=1;for(int i=1;i<=1000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[1000]=ksm(fc[1000]);for(int i=1000;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	sz[1]=1;for(int i=1;i<=1000;i++) sz[i]=sz[i>>1]+(i&1);
	dp[1]=0;for(int i=2;i<=1000;i++) dp[i]=dp[sz[i]]+1;
	int rs=0,cnt=0;for(int i=0;i<n;i++) if(ch[i]=='1')
		{for(int j=max(1,cnt);j<n;j++) if(dp[j]==K-1) rs=(rs+C(n-i-1,j-cnt))%P;cnt++;}
	rs-=K==1;if(dp[cnt]==K-1) rs++;
	return printf("%d\n",rs),0;
}