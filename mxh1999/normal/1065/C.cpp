#include<bits/stdc++.h>
using namespace std;

const int maxn=200010;
int n,m;
int a[maxn],num[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	int maxx=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
		maxx=max(maxx,a[i]);
	}
	int now=m;
	int ans=0;
	for (int i=maxx;i>=1;i--)
	{
		if (num[i]==n)	break;
		if (now<num[i])
		{
			ans++;
			now=m;
		}
		now-=num[i];
		num[i-1]+=num[i];
	}
	if (now!=m)	ans++;
	printf("%d\n",ans);
	return 0;
}