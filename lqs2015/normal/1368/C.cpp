#include<bits/stdc++.h>
using namespace std;
int n,cnt,x,y;
pair<int,int> ans[11111];
int main()
{
	scanf("%d",&n);
	if (n&1)
	{
		ans[cnt=1]=make_pair(0,0);
		for (int i=1;i<=n/2;i++)
		{
			ans[++cnt]=make_pair(x+1,y);ans[++cnt]=make_pair(x+2,y);ans[++cnt]=make_pair(x+3,y);
			ans[++cnt]=make_pair(x+1,y+1);ans[++cnt]=make_pair(x+2,y+1);
			ans[++cnt]=make_pair(x+1,y-1);ans[++cnt]=make_pair(x+2,y-1);
			x+=3;
		}
		ans[++cnt]=make_pair(x+1,0);ans[++cnt]=make_pair(x+2,0);
		ans[++cnt]=make_pair(x+1,1);ans[++cnt]=make_pair(x+1,-1);
		ans[++cnt]=make_pair(x+1,-2);ans[++cnt]=make_pair(x+2,-2);
		ans[++cnt]=make_pair(x+3,-2);ans[++cnt]=make_pair(x+3,-1);ans[++cnt]=make_pair(x+3,0);
		ans[++cnt]=make_pair(x+1,2);ans[++cnt]=make_pair(x+1,3);
		ans[++cnt]=make_pair(-1,0);ans[++cnt]=make_pair(-1,1);ans[++cnt]=make_pair(-1,2);ans[++cnt]=make_pair(-1,3);
		for (int i=0;i<=x;i++) ans[++cnt]=make_pair(i,3);
	}
	else
	{
		ans[cnt=1]=make_pair(0,0);
		for (int i=1;i<=n/2;i++)
		{
			ans[++cnt]=make_pair(x+1,y);ans[++cnt]=make_pair(x+2,y);ans[++cnt]=make_pair(x+3,y);
			ans[++cnt]=make_pair(x+1,y+1);ans[++cnt]=make_pair(x+2,y+1);
			ans[++cnt]=make_pair(x+1,y-1);ans[++cnt]=make_pair(x+2,y-1);
			x+=3;
		}
		ans[++cnt]=make_pair(-1,0);ans[++cnt]=make_pair(x+1,0);
		ans[++cnt]=make_pair(-1,1);ans[++cnt]=make_pair(x+1,1);
		ans[++cnt]=make_pair(-1,2);ans[++cnt]=make_pair(x+1,2);
		ans[++cnt]=make_pair(-1,3);ans[++cnt]=make_pair(x+1,3);
		for (int i=0;i<=x;i++) ans[++cnt]=make_pair(i,3);
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}