#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll a[200010],nw,b[200010];
int main()
{
	int n,i,j;cin>>n;
	for (i=1;i<=n/2;i++) cin>>a[i];
	for (i=1;i<=n/2;i++)
	{
		b[2*i]=a[i];
		for (j=1;j<=200000;j++)
		{
			ll t=(nw+j)*(nw+j),t1=t+a[i],t2=sqrt(t1);
			if (t2*t2==t1) {b[2*i-1]=t-(nw*nw),nw=t2;break;}
		}
		if (j==200001) {puts("No");return 0;}
	}
	puts("Yes");for (i=1;i<=n;i++) cout<<b[i]<<' ';
}
/*
a*a
a*a+2ay+y*y
a*a+2ax+x*x
(2a+x+y)(x-y)=ai;
*/