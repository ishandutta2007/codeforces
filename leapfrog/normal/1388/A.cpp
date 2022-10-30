#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		if(n<=30) {puts("NO");continue;}
		puts("YES");
		if(n-30==6) puts("5 6 10 15");
		else if(n-30==10) puts("6 10 15 9");
		else if(n-30==14) puts("6 10 15 13");
		else printf("6 10 14 %d\n",n-30);
	}
	return 0;
}