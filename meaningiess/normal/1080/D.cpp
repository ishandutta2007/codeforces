#include<iostream>
#include<cstring>
#include<cstdio>
#define ll unsigned long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		ll n,i,k,maxnn=0,rr=1;cin>>n>>k;
		if (n==2 && k==3) {puts("NO");continue;}
		for (i=1;i<=n;i++) {maxnn+=rr,rr*=4;if (maxnn>k) break;}
		if (maxnn<k) {printf("NO\n");continue;}
		ll nwnw=0,t=2,ansss=0;
		for (i=0;;i++)
		{
			if (nwnw+t-1>k) {printf("YES %I64d\n",max(0ll,(long long)n-(long long)i));break;}
			nwnw+=t-1;t*=2;
		}
	}
}