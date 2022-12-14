#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long p,q,ss,hws,a[11],mx;
bool f[10000011],ff[10000011];
void doit1(int n)
{
	int cnt=0,ts=n,res=0;
	while(ts)
	{
		a[cnt++]=ts%10;
		ts/=10;
	}
	for (int i=1;i<cnt;i++)
	{
		res=res*10+a[i];
	}
	res=n*pow(10,cnt-1)+res;
	ff[res]=1;
}
void doit2(int n)
{
	int cnt=0,ts=n,res=0;
	while(ts)
	{
		a[cnt++]=ts%10;
		ts/=10;
	}
	for (int i=0;i<cnt;i++)
	{
		res=res*10+a[i];
	}
	res=n*pow(10,cnt)+res;
	ff[res]=1;
}
int main()
{
	cin>>p>>q;
	for (int i=2;i<=sqrt(10000000);i++)
	{
		for (int j=2;j<=5000000;j++)
		{
			if (i*j>10000000) break;
			f[i*j]=1; 
		}
	}
	for (int i=1;i<10000;i++)
	{
		if (i<1000) 
		{
			doit1(i);
			doit2(i);
		}
		else doit1(i);
	}
	for (int i=1;i<=10000000;i++)
	{
		if (!f[i] && i!=1) ss++;
		if (ff[i]) hws++; 
		if (ss*q<=hws*p) mx=i;
	}
	cout<<mx<<endl;
	return 0;
}