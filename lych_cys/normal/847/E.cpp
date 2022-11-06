#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],cnt,ly;
char s[100005];
bool check(int x)
{
	int now=1;
	for (int i=1;i<=cnt;i++)
	{
		if (now>ly)break;
		if (a[i]-x<=b[now]&&a[i]+x>=b[now])
		{
			int r=max(b[now]+x-abs(b[now]-a[i]),(x+a[i]+b[now])/2);
			while(now<=ly&&b[now]<=r) now++;
		}
		//else return 0;
	}
	return now>ly;
}
int main()
{
	scanf("%d",&n);
	
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='P')
			a[++cnt]=i;
		else if (s[i]=='*') b[++ly]=i;
	}
	int l=0,r=n*2,ans=n*2,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if (check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
}