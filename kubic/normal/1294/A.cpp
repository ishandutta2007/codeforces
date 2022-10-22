#include <bits/stdc++.h>
using namespace std;
int T,a,b,c,n,t; 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&a,&b,&c,&n);
		if((a+b+c+n)%3) {puts("NO");continue;}
		t=(a+b+c+n)/3;
		puts((t>=a && t>=b && t>=c)?"YES":"NO"); 
	}return 0;
}