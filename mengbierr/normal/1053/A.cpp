#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
ll n,m,k;
int main()
{
	cin>>n>>m>>k;
	if(k%2==0)
	{
		k/=2;
		int lim=sqrt(k);
		for(int i=2;i<=lim;i++)
		{
			while(k%i==0)
			{
				if(n%i==0) n/=i;
				else if(m%i==0) m/=i;
				else
				{
					puts("NO");
					return 0;
				}k/=i;
			}
			
		}
		if(n%k==0) n/=k;
		else if(m%k==0) m/=k;
		else
		{
			puts("NO");
			return 0;
		}
		puts("YES");
		puts("0 0");
		cout<<n<<" "<<0<<endl;
		cout<<0<<" "<<m<<endl;
	}
	else
	{
		int lim=sqrt(k);
		int n1=n,m1=m;
		for(int i=2;i<=lim;i++)
		{
			while(k%i==0)
			{
				if(n%i==0) n/=i;
				else if(m%i==0) m/=i;
				else
				{
					puts("NO");
					return 0;
				}k/=i;
			}
		}
		if(n%k==0) n/=k;
		else if(m%k==0) m/=k;
		else
		{
			puts("NO");
			return 0;
		}
		if(n*2<=n1) n*=2;
		else if(m*2<=m1) m*=2;
		puts("YES");
		puts("0 0");
		cout<<n<<" "<<0<<endl;
		cout<<0<<" "<<m<<endl;
	}
}