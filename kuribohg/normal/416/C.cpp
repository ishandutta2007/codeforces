#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1010;
int n,m,mc,mp,maxnum,maxsub,ans[MAXN];
bool used[MAXN];
pair<int,int> a[MAXN],p[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&p[i].first);
	for(int i=1;i<=m;i++) p[i].second=i;
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++)
	{
		maxnum=-1000000000;
		for(int j=1;j<=n;j++)
		{
			if(a[j].first>p[i].first) continue;
			if(!used[j]&&a[j].second>maxnum) maxnum=a[j].second,maxsub=j;
		}
		if(maxnum!=-1000000000) ans[maxsub]=p[i].second,mp+=maxnum,mc++,used[maxsub]=true;
		else continue;
	}
	printf("%d %d\n",mc,mp);
	for(int i=1;i<=n;i++)
		if(ans[i]) printf("%d %d\n",i,ans[i]);
	return 0;
}