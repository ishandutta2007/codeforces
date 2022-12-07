#include<bits/stdc++.h>

using namespace std;

int n,k,y;
double a,t,l,v1,v2,g;

int main()
{
	scanf("%d %lf %lf %lf %d",&n,&l,&v1,&v2,&k);
	y=n/k;g=y;
	if(n%k!=0)g+=1;
	a=(v1+v2)*l/(2*g*v1+v2-v1);
	t=a/v2+(l-a)/v1;
	printf("%0.10lf",t);
	return 0;
}