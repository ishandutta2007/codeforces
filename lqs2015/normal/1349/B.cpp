#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,k,a[111111],b[111111],pre[111111],mn,pr,suf[111111];
int p1[111111],p2[111111],fuck[111111],cur,t1[111111],t2[111111]; 
bool flg,pt;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]<k) b[i]=-1;
			else b[i]=1;
		}
		for (int i=1;i<=n;i++) pre[i]=pre[i-1]+b[i];
		mn=1e9;flg=0;pr=0;
		if (n==1)
		{
			if (a[1]==k) printf("yes\n");
			else printf("no\n");
			continue;
		} 
		for (int i=0;i<=n+10;i++)
		{
			pre[i]=suf[i]=p1[i]=p2[i]=0;
		}
		pre[0]=0;suf[n+1]=0;
		p1[0]=0;p2[n+1]=0;
		for (int i=1;i<=n;i++)
		{
			pre[i]=pre[i-1]+b[i];
			p1[i]=min(p1[i-1],pre[i]);
		}
		for (int i=n;i>=1;i--)
		{
			suf[i]=suf[i+1]+b[i];
			p2[i]=min(p2[i+1],suf[i]);
		}
		flg=0;
		for (int i=1;i<=n;i++)
		{
			if (i==n) t2[i]=1e9;
			else t2[i]=p2[i+2];
			if (i==1) t1[i]=1e9;
			else t1[i]=p1[i-2];
		}
		for (int i=1;i<=n;i++)
		{
			cur=pre[n]-min(p1[i-1]+t2[i],p2[i+1]+t1[i]);
			if (cur>0) flg=1;
		}
		pt=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==k) pt=1;
		}
		if (flg&pt) printf("yes\n");
		else printf("no\n");
	}
	return Accepted;
}