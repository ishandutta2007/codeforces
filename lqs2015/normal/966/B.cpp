#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,x1,x2,p,pos,y1[333333],y2[333333],ypos,sz;
pair<int,int> k[333333],res;
pair<int,int> bit[555555];
void update(int p,int x,int y)
{
	while(p<=sz)
	{
		bit[p]=max(bit[p],make_pair(x,y));
		p+=p&(-p);
	}
}
pair<int,int> query(int p)
{
	pair<int,int> res=make_pair(-1e9,-1e9);
	while(p>=1)
	{
		res=max(res,bit[p]);
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&x1,&x2);
	sz=1;
	while(sz<n) sz*=2;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k[i].first);
		k[i].second=i;
	}
	sort(k+1,k+n+1);
	for (int i=1;i<=n;i++)
	{
		if (x1%i==0) p=x1/i;
		else p=x1/i+1;
		pos=lower_bound(k+1,k+n+1,make_pair(p,0))-k;
		pos=n+1-pos;
		y1[i]=pos;
	}
	for (int i=1;i<=n;i++)
	{
		if (x2%i==0) p=x2/i;
		else p=x2/i+1;
		pos=lower_bound(k+1,k+n+1,make_pair(p,0))-k;
		pos=n+1-pos;
		y2[i]=pos;
		update(sz-i+1,y2[i]-i,i);
		if (!ypos && y2[i]>=i)
		{
			ypos=i;
		}
	}
	reverse(k+1,k+n+1);
	for (int i=1;i<=n;i++)
	{
		if (y1[i]<i) continue;
		pos=y1[i]-i;
		if (ypos && ypos<=pos) 
		{
			printf("Yes\n");
			printf("%d %d\n",i,ypos);
			for (int j=1;j<=i;j++)
			{
				printf("%d ",k[pos+j].second);
			}
			printf("\n");
			for (int j=1;j<=ypos;j++)
			{
				printf("%d ",k[j].second);
			}
			printf("\n");
			return 0;
		}
		res=query(sz-pos);
		if (res.first<i) continue;
		printf("Yes\n");
		printf("%d %d\n",i,res.second);
		for (int j=1;j<=i;j++)
		{
			printf("%d ",k[pos+j].second);
		}
		printf("\n");
		for (int j=1;j<=pos;j++)
		{
			printf("%d ",k[j].second);
		}
		for (int j=y1[i]+1;j<=y1[i]+res.second-pos;j++)
		{
			printf("%d ",k[j].second);
		}
		printf("\n");
		return 0;
	}
	printf("No\n");
	return 0;
}