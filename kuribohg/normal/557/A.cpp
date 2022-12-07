#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a1,a2,b1,b2,c1,c2,ans1,ans2,ans3;
int main()
{
	scanf("%d%d%d%d%d%d%d",&n,&a1,&a2,&b1,&b2,&c1,&c2);
	ans1=min(a2,n-b1-c1);
	n-=ans1;
	ans2=min(b2,n-c1);
	n-=ans2;
	ans3=n;
	printf("%d %d %d\n",ans1,ans2,ans3);
	return 0;
}