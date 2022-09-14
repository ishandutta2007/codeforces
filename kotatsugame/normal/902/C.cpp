#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1<<17];
int b[1<<18],c[1<<18];
main()
{
	cin>>n;
	for(int i=0;i<=n;i++)scanf("%d",a+i);
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		flag&=a[i]<2||a[i+1]<2;
	}
	if(flag)
	{
		puts("perfect");
	}
	else
	{
		puts("ambiguous");
		int f=0,p=1;
		for(int i=0;i++<n;)
		{
			for(int j=0;j<a[i];j++)b[++f]=p,c[f]=p;
			if(a[i]>1&&a[i-1]>1)c[f]=p+1;
			p+=a[i-1];
		}
		for(int i=0;i<=f;i++)printf("%d%c",b[i],i==f?10:32);
		for(int i=0;i<=f;i++)printf("%d%c",c[i],i==f?10:32);
	}
}