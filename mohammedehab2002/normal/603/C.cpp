#include <bits/stdc++.h>
using namespace std;
int mex(int a,int b)
{
	int ret=0;
	while (ret==a || ret==b)
	ret++;
	return ret;
}
int gr(int x)
{
	if (x<4)
	return x%2;
	if (x%2)
	return 0;
	return mex(gr(x-1),gr(x/2));
}
int main()
{
	int n,k,x=0;
	scanf("%d%d",&n,&k);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		if (k%2)
		x^=gr(a);
		else if (a<3)
		x^=a;
		else
		x^=(a+1)%2;
	}
	printf(x? "Kevin":"Nicky");
}