#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int p[11]={0,1,2,3,4,5};
int a[11][11],ans,maxnum;
int main()
{
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			scanf("%d",&a[i][j]);
	do
	{
		ans=0;
		ans+=a[p[1]][p[2]]+a[p[2]][p[1]];
		ans+=a[p[3]][p[4]]+a[p[4]][p[3]];
		ans+=a[p[2]][p[3]]+a[p[3]][p[2]];
		ans+=a[p[4]][p[5]]+a[p[5]][p[4]];
		ans+=a[p[3]][p[4]]+a[p[4]][p[3]];
		ans+=a[p[4]][p[5]]+a[p[5]][p[4]];
		maxnum=max(maxnum,ans);
	}while(next_permutation(p+1,p+5+1));
	printf("%d\n",maxnum);
	return 0;
}