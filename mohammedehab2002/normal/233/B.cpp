#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
using namespace std;
int s(long long x)
{
	ostringstream con;
	string s;
	int ans=0,i;
	con << x;
	s=con.str();
	for (i=0;i<s.size();i++)
	ans+=(s[i]-'0');
	return ans;
}
int main()
{
	long long n,ans,i;
	cin >> n;
	ans=sqrt(n);
	for (i=ans-100;i<=ans+100;i++)
	{
		if (i<=0)
		continue;
		if ((i*i)+s(i)*i==n)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
}