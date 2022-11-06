#include<bits/stdc++.h>
#define re register
int a[500100],q[500100],vl[500100],fa[500100],cl[500100],cr[500100],p[500100];
int find(re int a){return a==fa[a]?a:fa[a]=find(fa[a]);}
inline bool cmp(re int a,re int b){return cr[a]>cr[b];}
int main()
{
	re int T,n;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&n);
		re int nm=0;
		for(re int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);vl[i]=0;fa[i]=i;cl[i]=0;cr[i]=n+1;p[i]=i;
			if(a[i]==0)nm++,vl[i]++;
		}
		for(re int i=1;i<=n;i++)vl[i]+=vl[i-1];
		for(re int i=1;i<=n;i++)
		if(a[i]!=0){
			if(vl[i]*2>nm)cr[a[i]]=std::min(cr[a[i]],vl[i]-(nm-1)/2);
			else cl[a[i]]=std::max(cl[a[i]],vl[i]);
		}
		for(re int i=1;i<=n;i++)vl[i]=0;
		std::sort(p+1,p+n+1,cmp);
		re int ans1=0,ans2=0;
		for(re int i=1;i<=n;i++)
		{
			re int xx=find(cl[p[i]]);
			if(xx>0)fa[xx]=xx-1,ans1++;
			else if(cr[p[i]]<=n)vl[cr[p[i]]]++;
		}
		re int nm1=0;
		for(re int i=1;i<=nm/2;i++)
		{
			nm1+=vl[i];
			if(i>ans1&&nm1>0)nm1--,ans2++;
		}
		printf("%d\n",ans1+ans2);
	}
}