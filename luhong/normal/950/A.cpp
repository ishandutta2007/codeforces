#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a,b,c,ans=-1;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=c;i++)ans=max(ans,min(a+i,b+(c-i)));
	printf("%d",ans*2);
	return 0;
}