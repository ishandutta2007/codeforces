#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		int p=n%4,t=n/4;t+=!!p;
		for(int i=t;i<n;i++) putchar('9');
		for(int i=1;i<=t;i++) putchar('8');
		putchar('\n');
	}
	return 0;
}