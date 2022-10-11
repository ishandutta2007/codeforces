#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m,sub1;
	cin >> n >> m;
	string s="";
	if (n-1>m)
	{
		cout << -1;
		return 0;
	}
	if (n>=m)
	sub1=1;
	else
	sub1=2;
	while (n && m)
	{
		string p(sub1,'1');
		s+=p;
		m-=sub1;
		s+="0";
		n--;
		if (n>=m)
		sub1=1;
	}
	if (!n && m)
	{
		if (m<=2)
		{
			string p(m,'1');
			s+=p;
			m=0;
		}
	}
	if (n && !m)
	{
		if (n==1)
		{
			s="0"+s;
			n=0;
		}
	}
	if (!n && !m)
	cout << s;
	else
	cout << -1;
}