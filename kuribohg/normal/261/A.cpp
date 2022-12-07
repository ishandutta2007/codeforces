#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;
const int MAXN=100010;
int m,n,cur,ans,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(b+1,b+n+1,greater<int>());
	cur=1;
	for(int i=1;;i++)
	{
		int x=a[1];
		while(x--)
		{
			if(cur>=n+1) break;
			ans+=b[cur];
			cur++;
		}
		if(cur>=n+1) break;
		cur+=2;
	}
	printf("%d\n",ans);
	return 0;
}