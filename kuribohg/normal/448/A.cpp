#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int sum1,sum2,p,n;
int main()
{
	for(int i=1;i<=3;i++) scanf("%d",&p),sum1+=p;
	for(int i=1;i<=3;i++) scanf("%d",&p),sum2+=p;
	scanf("%d",&n);
	if(n<(sum1+4)/5+(sum2+9)/10) puts("NO");
	else puts("YES");
	return 0;
}