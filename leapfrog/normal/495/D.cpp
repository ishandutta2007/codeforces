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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005,P=1e9+7;
int n,m,nx[N],dp[N],sm[N];char s[N],t[N];
int main()
{
	scanf("%s%s",s+1,t+1),n=strlen(t+1),nx[1]=0;
	for(int i=2,k=0;i<=n;i++)
	{
		while(k&&t[k+1]!=t[i]) k=nx[k];
		nx[i]=(k+=t[k+1]==t[i]);
	}m=strlen(s+1),sm[0]=dp[0]=1;
	for(int i=1,ls=0,k=0;i<=m;i++)
	{
		while(k&&t[k+1]!=s[i]) k=nx[k];
		k+=s[i]==t[k+1];if(k==n) ls=i-n+1;
		dp[i]=(dp[i-1]+(ls?sm[ls-1]:0))%P,sm[i]=(sm[i-1]+dp[i])%P;
	}return	printf("%d\n",(dp[m]-1+P)%P),0;
}