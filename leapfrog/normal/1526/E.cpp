//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,K,m,sa[200005],rk[200005],iv[200005];const int P=998244353;
int main()
{
	read(n),read(K),rk[sa[0]=n+1]=0,iv[1]=1;int rs=1;
	for(int i=1;i<=n;i++) read(sa[i]),rk[++sa[i]]=i;
	for(int i=2;i<=n;i++) m+=rk[sa[i]+1]>rk[sa[i-1]+1];
	for(int i=m+K;i>m+K-n;i--) rs=1ll*rs*i%P;
	for(int i=2;i<=n;i++) rs=1ll*rs*(iv[i]=1ll*(P-P/i)*iv[P%i]%P)%P;
	return printf("%d\n",rs),0;
}