//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,a[200005],F[35],L[200005],R[200005];long long res;map<int,int>mp;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	memset(L,0,sizeof(L));for(int i=1;i<=n;i++) R[i]=n+1;
	memset(F,0,sizeof(F)),res=n*1ll*(n+1)/2;
	for(int j=1;j<=n;j++)
		for(int i=0;i<31;i++)
		{
			if((a[j]>>i)&1) F[i]=j;
			else L[j]=max(F[i]+1,L[j]);
		}
	for(int i=0;i<31;i++) F[i]=n+1;
	for(int j=n;j>=1;j--)
		for(int i=0;i<31;i++)
		{
			if((a[j]>>i)&1) F[i]=j;
			else R[j]=min(F[i]-1,R[j]);
		}
	for(int i=1;i<=n;i++) L[i]=max(L[i],mp[a[i]]),mp[a[i]]=i+1;
	for(int i=1;i<=n;i++) res-=1ll*(i-L[i]+1)*(R[i]-i+1);
	return printf("%lld\n",res),0;
}