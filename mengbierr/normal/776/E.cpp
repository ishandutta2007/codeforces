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
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
long long phi(long long x)
{
	long long k=sqrt(x);
	while(k*k<=x) k++;
	k--;
	long long ans=x;
	for(long long i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			ans=ans/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}
int main()
{
	long long n,k;
	cin>>n>>k;
	k=(k+1)/2;
	while((k--)&&n>1)
	{
		n=phi(n);
	}
	cout<<n%1000000007;
}