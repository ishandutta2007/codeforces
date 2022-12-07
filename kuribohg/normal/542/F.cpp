#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
#include<vector>
using namespace std;
int n,T,x,y,ans;
vector<int> a[1010];
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	}
	for(int x=1;x<=T;x++)
	{
		sort(a[x].begin(),a[x].end(),greater<int>());
		int len=a[x].size();
		if(len>0) ans=max(ans,a[x][0]);
		for(int i=0;i+1<len;i+=2)
			a[x+1].push_back(a[x][i]+a[x][i+1]);
		if(len&1) a[x+1].push_back(a[x][len-1]);
	}
	printf("%d\n",ans);
	return 0;
}