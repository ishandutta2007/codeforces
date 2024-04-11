#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;double a=0,b=0,x;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&x),b=b+(2*a+1)*x,a=(a+1)*x;
	return printf("%.8lf\n",b),0;
}