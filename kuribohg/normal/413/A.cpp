#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,m,minnum,maxnum,a[110],nowmin=2e9,nowmax;
int main()
{
	scanf("%d%d%d%d",&n,&m,&minnum,&maxnum);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		nowmin=min(nowmin,a[i]);
		nowmax=max(nowmax,a[i]);
	}
	if(nowmin<minnum||nowmax>maxnum) puts("Incorrect");
	else
	{
		if(nowmin==minnum&&nowmax==maxnum) puts("Correct");
		else if(nowmin==minnum||nowmax==maxnum)
		{
			if(m<n) puts("Correct");
			else puts("Incorrect");
		}
		else
		{
			if(m<=n-2) puts("Correct");
			else puts("Incorrect");
		}
	}
	return 0;
}