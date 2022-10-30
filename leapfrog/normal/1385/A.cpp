#include<bits/stdc++.h>
using namespace std;
int t,a[5];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d%d",a+1,a+2,a+3),sort(a+1,a+4);
		if((a[1]!=a[2]&&a[2]!=a[3])||(a[1]==a[2]&&a[2]!=a[3])) puts("NO");
		else puts("YES"),printf("1 %d %d\n",a[1],a[2]);
	}
	return 0;
}