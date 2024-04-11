#include<bits/stdc++.h>
using namespace std;
int T;
int a,b,x,y;
int main()
{
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		int d=x-y;
		if(d<0) d=-d;
		if(d%(a+b)!=0) printf("-1\n");
		else printf("%d\n",d/(a+b));
	}
	return 0;
}