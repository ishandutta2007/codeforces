#include <iostream>
#include <string.h>
using namespace std;
#define t(n) n*(n-1)/2
int main()
{
	string s;
	int a,b,c,d,n,m;
	cin >> a >> b >> c >> d;
	for (n=0;t(n)<a;n++);
	for (m=0;t(m)<d;m++);
	if (b==0 && c==0 && a==0 && d==0)
	{
		cout << "0";
		return 0;
	}
	if (t(n)!=a || t(m)!=d || n*m!=b+c)
	{
		if (t(n)==a && t(m)==d)
		n=max(n,1),m=max(m,1);
		if (t(n)!=a || t(m)!=d || n*m!=b+c)
		{
			cout << "Impossible";
			return 0;
		}
	}
	int l=n+m;
	for (int i=0;i<l;i++)
	{
		if (c>=n)
		{
			m--;
			c-=n;
			s+="1";
		}
		else
		{
			n--;
			s+="0";
		}
	}
	cout << s;
}