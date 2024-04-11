#include<bits/stdc++.h>
using namespace std;
int n,m,len;
int get(int x,int y)
{
	return (x-1)*m+y;
}
char opt[11111111];
int f[11111111],sum[11111111],l,r,mid,cur,cf[11111111];
bool can[11111111];
bool check(int mid)
{
	memset(can,0,sizeof(can));
	memset(cf,0,sizeof(cf));
	len=mid*2+1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (i+mid>n || j+mid>m || i-mid<=0 || j-mid<=0) continue;
			cur=sum[get(i+mid,j+mid)];
			if (i-mid>1) cur-=sum[get(i-mid-1,j+mid)];
			if (j-mid>1) cur-=sum[get(i+mid,j-mid-1)];
			if (i-mid>1 && j-mid>1) cur+=sum[get(i-mid-1,j-mid-1)];
			if (cur==len*len) 
			{
				can[get(i,j)]=1;
				cf[get(i-mid,j-mid)]++;
				if (i+mid<n) cf[get(i+mid+1,j-mid)]--;
				if (j+mid<m) cf[get(i-mid,j+mid+1)]--;
				if (i+mid<n && j+mid<m) cf[get(i+mid+1,j+mid+1)]++; 
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (i>1) cf[get(i,j)]+=cf[get(i-1,j)];
			if (j>1) cf[get(i,j)]+=cf[get(i,j-1)];
			if (i>1 && j>1) cf[get(i,j)]-=cf[get(i-1,j-1)];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if ((!cf[get(i,j)]) && f[get(i,j)]) return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",opt);
		for (int j=1;j<=m;j++)
		{
			if (opt[j-1]=='X') f[get(i,j)]=1;
			else f[get(i,j)]=0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			sum[get(i,j)]=f[get(i,j)];
			if (i>1) sum[get(i,j)]+=sum[get(i-1,j)];
			if (j>1) sum[get(i,j)]+=sum[get(i,j-1)];
			if (i>1 && j>1) sum[get(i,j)]-=sum[get(i-1,j-1)];
		}
	}
	l=0;r=min(n+10,m+10);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	check(r);
	printf("%d\n",r);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (can[get(i,j)]) printf("X");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}