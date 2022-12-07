#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,x,p,s,ans;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p);
		s+=p;
	}
	s=abs(s);
	ans=(s-1)/x;
	if(s==0) ans=-1;
	printf("%d\n",ans+1);
	return 0;
}