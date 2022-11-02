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
int n,K,L[1000005],R[1000005];char s[1000005];
int main()
{
	read(n),read(K),scanf("%s",s+1),L[0]=1,R[n+1]=n;
	for(int i=1;i<=n;i++) if(s[i-1]==s[i]) L[i]=L[i-1];else L[i]=i;
	for(int i=n;i>=1;i--) if(s[i+1]==s[i]) R[i]=R[i+1];else R[i]=i;
	if(n==K||L[n-K]==1||R[K+1]==n) return puts("tokitsukaze"),0;
	for(int i=2;i<=n-K;i++) if(s[i-1]==s[i+K]&&L[i-1]==1&&R[i+K]==n) return puts("tokitsukaze"),0;
	if(K*2<n) return puts("once again"),0;
	for(int i=2;i<=n-K;i++) if(L[i-1]!=1||R[i+K]!=n) return puts("once again"),0;
	return puts("quailty"),0;
}