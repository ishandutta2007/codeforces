#include <iostream>
#include <string.h>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	int n,i,a1,a2,test,ans=0;
	string s1,s2;
	cin >> n >> s1 >> s2;
	for (i=0;i<n;i++)
	{
		if (s1[i]!='0' && s2[i]!='0')
		test=abs((int)s1[i]-(int)s2[i]);
		else
		{
			if (s1[i]=='0' && s2[i]!='0')
			test=s2[i]-'1'+1;
			else if (s1[i]!='0' && s2[i]=='0')
			test=s1[i]-'1'+1;
			else
			test=0;
		}
		if (test>5)
		test=10-test;
		ans+=test;
	}
	cout << ans;
}