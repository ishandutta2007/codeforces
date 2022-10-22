#include <bits/stdc++.h>
using namespace std;
int n,m;
int l=1;
int main()
{
	scanf("%d %d",&n,&m);
	while(n>0 && l<=m)
	{
		l=(l<<1);
		n--;
	}
	printf("%d",m%l);
	return 0;
}