#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
ll T,n,L,R,mid,psL,psR,tmp[N<<1];ll l,r,s[N];
void print(ll x)
{
	if(x==n) printf("1 ");
	else for(ll i=x+1;i<=n;++i) printf("%lld %lld ",x,i);
}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld %lld",&n,&l,&r);
		for(ll i=1;i<=n;++i) s[i]=s[i-1]+(n-i<<1);s[n]=s[n-1]+1;L=1;R=n;
		while(L<=R)
		{
			mid=L+R>>1;
			if(s[mid-1]<l) psL=mid,L=mid+1;else R=mid-1;
		}L=1;R=n;
		while(L<=R)
		{
			mid=L+R>>1;
			if(s[mid]>=r) psR=mid,R=mid-1;else L=mid+1;
		}if(psL==n) {print(n);puts("");continue;}
		tmp[0]=0;for(ll i=1;i<=n-psL;++i) tmp[++tmp[0]]=psL,tmp[++tmp[0]]=psL+i;
		if(psL==psR)
		{
			for(ll i=l-s[psL-1];i<=r-s[psL-1];++i) printf("%lld ",tmp[i]);
			puts("");continue;
		}for(ll i=l-s[psL-1];i<=tmp[0];++i) printf("%lld ",tmp[i]);
		for(ll i=psL+1;i<psR;++i) print(i);
		if(psR==n) {print(n);puts("");continue;}
		tmp[0]=0;for(ll i=1;i<=n-psR;++i) tmp[++tmp[0]]=psR,tmp[++tmp[0]]=psR+i;
		for(ll i=1;i<=r-s[psR-1];++i) printf("%lld ",tmp[i]);puts("");
	}
}