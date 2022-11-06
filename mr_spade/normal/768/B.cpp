#include<cstdio>
#include<iostream>
#define int long long
using std::swap;
int n,l,r,ans1,ans2;
int bit[100],tot;
int size[100],weight[100];
signed main()
{
	register int i;
	scanf("%lld%lld%lld",&n,&l,&r);
	if(!n)
		return puts("0"),0;
	while(n)
		bit[tot++]=(n&1),n>>=1;
	for(i=0;i<tot-1-i;i++)
		swap(bit[i],bit[tot-1-i]);
	size[0]=1;
	for(i=1;i<tot;i++)
		size[i]=size[i-1]<<1|1;
	weight[0]=bit[0];
	for(i=1;i<tot;i++)
		weight[i]=weight[i-1]<<1|bit[i];
	for(i=tot-1;i;i--)
		if(size[i-1]+1<=r)
			r-=size[i-1]+1,ans2+=weight[i-1]+bit[i];
	if(1<=r)
		r-=1,ans2+=weight[0];
	for(i=tot-1;i;i--)
		if(size[i-1]+1<l)
			l-=size[i-1]+1,ans1+=weight[i-1]+bit[i];
	if(1<l)
		l-=1,ans1+=weight[0];
	printf("%lld\n",ans2-ans1);
	return 0;
}