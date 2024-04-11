#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=0;i<=100000;i++)
	{
		if(a*i+b<d) continue;
		if((a*i+b-d)%c!=0) continue;
		printf("%d\n",a*i+b);
		return 0;
	}
	printf("-1\n");
	return 0;
}