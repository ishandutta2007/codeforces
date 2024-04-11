#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
bool check(int n)
{
	if(n<0) n=-n;
	while(n>0)
	{
		if(n%10==8) return true;
		n/=10;
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=1000;i++) if(check(n+i)) {ans=i;break;}
	printf("%d\n",ans);
	return 0;
}