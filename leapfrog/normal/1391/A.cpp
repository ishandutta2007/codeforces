#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ');
	}
	return 0;
}