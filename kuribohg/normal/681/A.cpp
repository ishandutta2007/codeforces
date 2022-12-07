#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%*s%d%d",&a,&b);
		if(a>=2400&&b>a) {puts("YES");return 0;}
	}
	puts("NO");
	return 0;
}