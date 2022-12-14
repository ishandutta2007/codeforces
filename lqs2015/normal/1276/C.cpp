#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[444444],arr[444444],cnt,num[444444],nnum[444444],lst,cur,pos,ans,x,y,Ans[1111111];
pair<int,int> c[444444];
map<int,int> mp;
int get(int a,int b)
{
	return a*y+b;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++) arr[i]=a[i];
	sort(arr+1,arr+n+1);
	cnt=unique(arr+1,arr+n+1)-arr-1;
	for (int i=1;i<=cnt;i++) mp[arr[i]]=i;
	for (int i=1;i<=n;i++) a[i]=mp[a[i]];
	for (int i=1;i<=n;i++) num[a[i]]++;
	for (int i=1;i<=cnt;i++)
	{
		nnum[num[i]]++;
	}
	lst=cnt;
	for (int i=1;i<=700;i++)
	{
		cur+=lst;
		lst-=nnum[i];
		pos=0;
		for (int j=1;i*j<=n;j++)
		{
			if (i*j>cur) break;
			pos=j;
		}
		if (pos<i) continue;
		if (ans<pos*i)
		{
			ans=pos*i;
			x=i;y=pos;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=cnt;i++)
	{
		c[i]=make_pair(min(num[i],x),i);
	}
	sort(c+1,c+cnt+1);
	reverse(c+1,c+cnt+1);
	pos=1;
	for (int j=0;j<y;j++)
	{
		for (int i=0;i<x;i++)
		{
			if (c[pos].first==0) pos++;
			c[pos].first--;
			Ans[get(i,(i+j)%y)]=arr[c[pos].second];
		}
	}
	printf("%d %d\n",x,y);
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			printf("%d ",Ans[get(i,j)]);
		}
		printf("\n");
	}
	return Accepted;
}