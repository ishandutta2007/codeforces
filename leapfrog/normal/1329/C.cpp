#include<bits/stdc++.h>
using namespace std;
int q,g,h,tot,t[2100005],a[2100005],dep[2100005],mx[2100005];long long ans;
inline void chg(int x)
{
	if(!a[x<<1]) {if(!a[x<<1|1]) mx[x]=x;else mx[x]=mx[x<<1|1];}
	else {if(!a[x<<1|1]) mx[x]=mx[x<<1];else mx[x]=a[x<<1]>a[x<<1|1]?mx[x<<1]:mx[x<<1|1];}
}
inline void pop(int x)
{
	if(!a[x<<1]) {if(!a[x<<1|1]) a[x]=0;else a[x]=a[x<<1|1],pop(x<<1|1);}
	else {if(!a[x<<1|1]) a[x]=a[x<<1],pop(x<<1);else {if(a[x<<1]>a[x<<1|1]) a[x]=a[x<<1],pop(x<<1);else a[x]=a[x<<1|1],pop(x<<1|1);}}
	chg(x);
}
int main()
{
	for(scanf("%d",&q);q--;)
	{
		scanf("%d%d",&h,&g),ans=0,tot=0;
		for(int i=1;i<=(1<<h)-1;i++) scanf("%d",a+i),dep[i]=dep[i>>1]+1,ans+=a[i];
		for(int i=(1<<h);i<=(1<<(h+1));i++) a[i]=0;
		for(int i=(1<<h)-1;i>=1;i--) chg(i);
		for(int i=1;i<=(1<<h);i++) while(a[i]&&dep[mx[i]]>g) t[++tot]=i,ans-=a[i],pop(i);
		printf("%lld\n",ans);
		for(int i=1;i<=tot;i++) printf("%d%c",t[i],i==tot?'\n':' ');
	}
	return 0;
}