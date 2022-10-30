#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&m);
		if(n%m==0||m%n==0) puts("YES");
		else puts("NO");
	}
	return 0;
}