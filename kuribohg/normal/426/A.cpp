#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,p,sum,maxnum;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p);
		if(p>maxnum) maxnum=p;
		sum+=p;
	}
	if(sum-maxnum<=m) puts("YES");
	else puts("NO");
	return 0;
}