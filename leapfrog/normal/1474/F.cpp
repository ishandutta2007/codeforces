//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
//#define debug
const int N=1000005,P=998244353;
int n,iv[N],dp[1005][1005],L[N],R[N],ut;ll d[N],D[N],tn[N];
inline char tepan() {for(int i=1;i<=n;i++) if(d[i]>d[i-1]) return 0;return 1;}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	int r=1;for(int i=1;i<=m;i++) r=1ll*r*(n-i+1)%P*iv[i]%P;
	return r;
}
inline int calc(int A,int B,int tot)
{
	int rs=0;for(int i=0;i<=B;i++) rs=(rs+1ll*C(B,i)*C(tot-i+A-1,A-1))%P;
	return rs;
}
inline int solve(int l,int r)
{
	for(int i=l;i<=r;i++) if(d[i]==d[l]) dp[i][d[l]]=1;
	for(int i=l+1;i<=r;i++)
	{
		for(int j=L[i];j<=R[i];j++)
		{
			int A=0,B=0,tot=tn[j+1]-tn[j]-1;
			if(d[i-1]<d[i]) A=1,dp[i][j]=(dp[i][j]+1ll*dp[i][j-1]*calc(A,B,tot))%P;
			for(int k=i-1;k>=l;k--)
			{
				if(d[k-1]<d[k]&&L[k]<=j&&j<=R[k]) A++;
				dp[i][j]=(dp[i][j]+1ll*dp[k][j-1]*calc(A,B,tot))%P;
				//if(i==r) printf("qwq %d : %d %d %d\n",k,A,B,tot);
				if(d[k-1]>d[k]&&L[k]<=j&&j<=R[k]) B++;
			}
		}
#ifdef debug
		for(int j=L[i];j<=R[i];j++) printf("%d%c",dp[i][j],j==R[i]?'\n':' ');
#endif
	}
	int rs=0;for(int i=l;i<=r;i++) if(d[i]==d[r]) rs=(rs+dp[i][d[r]])%P;
	return rs;
}
int main()
{
	iv[1]=1;for(int i=2;i<=100000;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	read(n,d[1]);for(int i=1;i<=n;i++) read(d[i]),d[i]+=d[i-1];
	int qwq=1;for(int i=2;i<=n;i++) if(d[i-1]^d[i]) d[++qwq]=d[i];
	ll MX=0;n=qwq;for(int i=0;i<=n;i++) for(int j=i;j<=n;j++) MX=max(MX,d[j]-d[i]+1);
	if(tepan()) return printf("%lld %lld\n",MX,(1-d[n])%P),0;
	for(int i=0;i<n;i++) tn[++ut]=D[i]=d[i]+(d[i]<d[i+1]?1:-1);
	for(int i=0;i<=n;i++) tn[++ut]=d[i],(i?tn[++ut]=d[i]+1:0);
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;
	auto lsh=[](ll x){return lower_bound(tn+1,tn+ut+1,x)-tn;};
	for(int i=0;i<=n;i++) d[i]=lsh(d[i]),(i?D[i-1]=lsh(D[i-1]):0);
#ifdef debug
	for(int i=1;i<=ut;i++) printf("%lld%c",tn[i],i==ut?'\n':' ');
	for(int i=0;i<=n;i++) printf("%lld%c",d[i],i==n?'\n':' ');
#endif
	for(int i=1;i<=n;i++) L[i]=min(D[i-1],d[i]),R[i]=max(D[i-1],d[i]);
	int rs=0;for(int i=0;i<=n;)
	{
		int nx=n+1;for(int j=i;j<=n;j++) if(tn[d[j]]-tn[d[i]]+1==MX) nx=j;
		if(nx!=n+1) rs=(rs+solve(i,nx))%P,i=nx+1;else i++;
	}
	return printf("%lld %d\n",MX,rs),0;
}