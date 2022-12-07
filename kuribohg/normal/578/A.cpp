#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int x,y,k;
double ans=1e20;
int main()
{
	scanf("%d%d",&x,&y);
	k=x+y;
	int p=(int)floor(k*1.0/y);
	if(p&1) p--;
	if(p!=0) ans=min(ans,k*1.0/p);
	k=x-y;
	if(k>0)
	{
		p=(int)floor(k*1.0/y);
		if(p&1) p--;
		if(p!=0) ans=min(ans,k*1.0/p);
	}
	if(ans==1e20) puts("-1");
	else printf("%.010lf\n",ans);
	return 0;
}