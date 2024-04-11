#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
long long n,a[100005],ans;
long long gcd(long long x,long long y)
{
	if(x==0) return y;
	else if(y==0) return x;
	return !x?y:gcd(y,x%y);
}
int main()
{
	puts("YES");
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int x=a[1],y;
	for(int i=2;i<=n;i++)
	x=gcd(x,a[i]);
	if(x!=1)
	{
		puts("0");return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		while(a[i]%2==1)
		{
			x=a[i],y=a[i+1];
			a[i]=x-y;a[i+1]=x+y;
			a[i]=abs(a[i]);a[i+1]=abs(a[i+1]);
			ans++;
			//cout<<a[i]<<" "<<a[i+1]<<endl;
		}
	}
	//cout<<"ok";
	while(a[n]%2==1)
	{
		x=a[n-1],y=a[n];
		a[n-1]=x-y;a[n]=x+y;
		ans++;
		a[n-1]=abs(a[n-1]);a[n]=abs(a[n]);
	}
	cout<<ans;
}