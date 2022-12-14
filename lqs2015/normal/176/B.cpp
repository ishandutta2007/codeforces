#include<iostream>
#include<string>
using namespace std;
string a,b,c;
long long k,ha[1111],hb[1111],pw[1111],A,B;
const long long mod=1e9+7;
long long add(long long a,long long b)
{
	return (a+b)%mod;
}
long long minu(long long a,long long b)
{
	long long res=a-b;
	if (res<0) res+=mod;
	return res;
}
long long mult(long long a,long long b)
{
	return (a*b)%mod;
}
struct mat
{
	long long a[2][2];
	mat()
	{
		a[0][0]=a[1][1]=1;
		a[0][1]=a[1][0]=0;
	}
	mat operator * (const mat &b) const
	{
		mat res;
		for (int i=0;i<=1;i++)
		{
			for (int j=0;j<=1;j++)
			{
				res.a[i][j]=0;
				for (int k=0;k<=1;k++)
				{
					res.a[i][j]=add(res.a[i][j],mult(a[i][k],b.a[k][j]));
				}
			}
		}
		return res;
	}
}m;
mat mul(mat a,long long n)
{
	mat res,p=a;
	for (long long i=n;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
}
long long nmul(long long a,long long n)
{
	long long res=1,p=a;
	for (long long i=n;i;i>>=1)
	{
		if (i&1) res=mult(res,p);
		p=mult(p,p);
	}
	return res;
}
int main()
{
	cin>>a>>b>>k;
	int n=a.size();
	for (int i=0;i<n;i++)
	{
		c=a.substr(i)+a.substr(0,i);
		if (c==b) A++;
		else B++;
	}
	if (!A)
	{
		cout<<0<<endl;
		return 0;
	}
	if (A==n)
	{
		cout<<nmul(n-1,k)<<endl;
		return 0;
	}
	m.a[0][0]=A-1;
	m.a[1][0]=A;
	m.a[0][1]=B;
	m.a[1][1]=B-1;
	m=mul(m,k);
	if (a==b) cout<<m.a[0][0]<<endl;
	else cout<<m.a[1][0]<<endl;
	return 0;
}