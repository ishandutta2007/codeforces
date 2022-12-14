#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
unsigned long long a[2222222],b[2222222],cur;
int n;
char sa[2222222],sb[2222222];
void FWT(unsigned long long *a)
{
	for (int i=n-1;i>=0;i--)
	{
		for (int j=(1<<n)-1;j>=0;j--)
		{
			if (j&(1<<i)) a[j]+=a[j^(1<<i)];
		}
	}
}
void IFWT(unsigned long long *a)
{
	for (int i=0;i<n;i++)
	{
		for (int j=(1<<n)-1;j>=0;j--)
		{
			if (j&(1<<i)) a[j]-=a[j^(1<<i)];
		}
	}
}
int main()
{
	scanf("%d%s%s",&n,sa,sb);
	for (int i=0;i<(1<<n);i++)
	{
		cur=1;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j)) cur*=4;
		}
		a[i]=(sa[i]-'0')*cur;
		b[i]=(sb[i]-'0')*cur;
	}
	FWT(a);
	FWT(b);
	for (int i=0;i<(1<<n);i++) a[i]*=b[i];
	IFWT(a);
	for (int i=0;i<(1<<n);i++)
	{
		cur=1;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j)) cur*=4;
		}
		printf("%u",(a[i]/cur)&3);
	}
	return 0;
}