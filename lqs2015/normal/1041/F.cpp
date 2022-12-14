#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,y,m,yy,ans;
int a[111111],b[111111],cnta,cntb,qa[111111],qb[111111],pos,posa,posb;
int cta[111111],ctb[111111],pre,numa[111111],numb[111111];
int finda(int x)
{
	int l=1,r=cnta,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (numa[mid]==x) return cta[mid];
		if (numa[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return 0;
}
int findb(int x)
{
	int l=1,r=cntb,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (numb[mid]==x) return ctb[mid];
		if (numb[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&y);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d%d",&m,&yy);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	ans=2;
	for (int i=1;i<=30;i++)
	{
		for (int j=1;j<=n;j++)
		{
			qa[j]=a[j]%(1<<i);
		}
		for (int j=1;j<=m;j++)
		{
			qb[j]=b[j]%(1<<i);
		}
		sort(qa+1,qa+n+1);sort(qb+1,qb+m+1);
		cnta=cntb=0;posa=posb=1;
		memset(cta,0,sizeof(cta));memset(ctb,0,sizeof(ctb));
		while(posa<=n) 
		{
			cnta++;pre=posa;
			numa[cnta]=qa[posa];
			while(posa<=n && qa[posa]==qa[pre]) 
			{
				posa++;
				cta[cnta]++;
			}
		}
		while(posb<=m) 
		{
			cntb++;pre=posb;
			numb[cntb]=qb[posb];
			while(posb<=m && qb[posb]==qb[pre]) 
			{
				posb++;
				ctb[cntb]++;
			}
		}
		/*for (int j=1;j<=cnta;j++)
		{
			cout<<numa[j]<<" "<<cta[j]<<endl;
		}
		cout<<endl;
		for (int j=1;j<=cntb;j++)
		{
			cout<<numb[j]<<" "<<ctb[j]<<endl;
		}
		cout<<endl;cout<<endl;*/
		for (int j=1;j<=cnta;j++)
		{
			ans=max(ans,cta[j]+findb((numa[j]+(1<<(i-1)))%(1<<i)));
		}
		for (int j=1;j<=cntb;j++)
		{
			ans=max(ans,ctb[j]+finda((numb[j]+(1<<(i-1)))%(1<<i)));
		}
	}
	printf("%d\n",ans);
	return 0;
}