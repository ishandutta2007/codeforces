#include<bits/stdc++.h>
using namespace std;

const int maxn=200010;
int a[maxn],t[maxn];
int n,m;

int que[maxn];
pair<int,int> quee[maxn];
bool check(int mid)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
	if (a[i]>=mid)
		que[++cnt]=t[i];
	sort(que+1,que+cnt+1);
	if (cnt<mid)	return false;
	int all=0;
	for (int i=1;i<=mid;i++)
		all+=que[i];
	return all<=m;
}
void outit(int mid)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
	if (a[i]>=mid)
		quee[++cnt]=make_pair(t[i],i);
	sort(quee+1,quee+cnt+1);
	printf("%d\n",mid);
	for (int i=1;i<=mid;i++)
		printf("%d ",quee[i].second);
	printf("\n");
}

int main()
{
	scanf("%d%d",&n,&m);
	bool ok=false;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&t[i]);
		if (t[i]<=m)	ok=true;
	}
	if (!ok)
	{
		printf("0\n0\n");
		return 0;
	}
	int l=1,r=n;
	while (l<r)
	{
		int mid=(l+r+1)>>1;
		if (check(mid))	l=mid;else r=mid-1;
	}
	printf("%d\n",l);
	outit(l);
	return 0;
}