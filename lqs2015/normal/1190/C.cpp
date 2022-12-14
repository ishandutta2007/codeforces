#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,k,a[111111],pre[111111],x,y,nx,ny,l,r,mid,aa,bb;
bool f;
char s[111111];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for (int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	x=-1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=a[1]) 
		{
			x=i-1;
			break;
		}
	}
	if (x==-1)
	{
		printf("tokitsukaze\n");
		return 0;
	}
	for (int i=n;i>=1;i--)
	{
		if (a[i]!=a[n])
		{
			y=n-i;
			break;
		}
	}
	if (a[1]==a[n])
	{
		if (x+y+k>=n)
		{
			printf("tokitsukaze\n");
			return 0;
		}
	}
	else
	{
		if (max(x,y)+k>=n)
		{
			printf("tokitsukaze\n");
			return 0;
		}
	}
	for (int i=1;i+k-1<=n;i++)
	{
		for (int j=0;j<2;j++)
		{
			if (i==1) aa=j;
			else aa=a[1];
			if (i+k-1==n) bb=j;
			else bb=a[n];
			if (x+1<i) nx=x;
			else
			{
				if (j!=a[1] && i!=1) nx=i-1;
				else
				{
					l=i+k-1;r=n;
					while(l<=r)
					{
						mid=(l+r)>>1;
						if (pre[mid]-pre[i+k-1]!=aa*(mid-i-k+1)) r=mid-1;
						else l=mid+1;
					}
					nx=r;
				}
			}
			int pp=n-y+1;
			if (pp>i+k) ny=n-pp+1;
			else 
			{
				if (j!=a[n] && i+k-1!=n) 
				{
					ny=n-(i+k-1);
				}
				else
				{
					l=0;r=i-1;
					while(l<=r)
					{
						mid=(l+r)>>1;
						if (pre[i-1]-pre[mid]!=bb*(i-1-mid)) l=mid+1;
						else r=mid-1;
					}
					ny=n-l;
				}
			}
			if (aa==bb)
			{
				if (nx+ny+k<n) f=1;
			}
			else 
			{
				if (max(nx,ny)+k<n) f=1;
			}
		}
	}
	if (!f) printf("quailty\n");
	else printf("once again\n");
	return Accepted;
}