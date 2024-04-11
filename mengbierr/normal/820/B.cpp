#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
int main()
{
	double n,a;
	cin>>n>>a;
	double x=180/n;
	double minn=23333;int now;
	for(int i=1;i<=n-2;i++)
	{
		if(fabs(i*x-a)<minn)
		{
			minn=fabs(i*x-a);
			now=i;
		}
	}
	printf("1 %.0lf %d",n,now+1);
}