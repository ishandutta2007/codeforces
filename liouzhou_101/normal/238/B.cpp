#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100010;
const int INF=1000000000;

int n,h;
pair<int,int> a[MaxN];
int v[MaxN];

int main()
{
	cin>>n>>h;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	int ans=INF,get;
	for (int i=0;i<=n;++i)
	{
		int x=INF,y=0;
		if (i>1)
			x=min(x,a[1].first+a[2].first);
		if (i<n-1)
			x=min(x,a[i+2].first+a[i+1].first);
		if (i>=1&&i<n)
			x=min(x,a[1].first+a[i+1].first+h);
		if (i==n)
			y=max(y,a[n-1].first+a[n].first);
		if (i<n-1)
			y=max(y,a[n].first+a[n-1].first);
		if (i>=1&&i<n)
			y=max(y,a[n].first+a[i].first+h);
		if (y-x<ans)
		{
			ans=y-x;
			get=i;
		}
	}
	for (int i=1;i<=get;++i)
		v[a[i].second]=1;
	for (int i=get+1;i<=n;++i)
		v[a[i].second]=2;
	cout<<ans<<endl;
	for (int i=1;i<=n;++i)
		printf("%d ",v[i]);
	return 0;
}