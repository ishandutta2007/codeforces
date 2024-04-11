#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n&1)
	{
		for(int i=0;i<n;i++) printf("%d ",i);
		puts("");
		for(int i=0;i<n;i++) printf("%d ",i);
		puts("");
		for(int i=0;i<n;i++) printf("%d ",(i+i)%n);
		puts("");
	}
	else puts("-1");
	return 0;
}