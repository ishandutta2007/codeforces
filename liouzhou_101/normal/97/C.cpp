#include<cstdio>
#include<iostream>

using namespace std;

int n;
double p[110];
double ans;

int main()
{
	cin>>n;
	for (int i=0;i<=n;++i)
		cin>>p[i];
	for (int i=0;i<=n/2;++i)
		for (int j=n/2+1;j<=n;++j)
			ans=max(ans,(p[i]*(j-n*0.5)+p[j]*(n*0.5-i))/(j-i));
	printf("%.10lf\n",ans);
	return 0;
}