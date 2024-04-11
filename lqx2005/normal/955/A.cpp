#include <bits/stdc++.h>
#define int long long
using namespace std;
const double inf=1000000000000000;
int hh,mm;
int h,d,c,n,Begin;
signed main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&hh,&mm,&h,&d,&c,&n);
	int num;
	if(h%n==0) num=h/n;
	else num=h/n+1;	
	double ans=(double)num*(double)(c); 
	if(hh>=20) ans=min(ans,(double)num*(double)(0.8*c));
	else
	{
		int Time=hh*60+mm;
		Time=1200-Time;
		h+=Time*d;
		if(h%n==0) num=h/n;
		else num=h/n+1;		
		ans=min(ans,(double)num*(double)(0.8*c));		
	}
	printf("%.10lf\n",ans);
	return 0;
}