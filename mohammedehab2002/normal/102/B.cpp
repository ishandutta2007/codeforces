#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
string sum(string s)
{
	int i,sum=0;
	for (i=0;i<s.size();i++)
	sum+=((int)(s[i]-'0'));
	ostringstream con;
	con << sum;
	return con.str();
}
int main()
{
	int ans=0;
	string s;
	cin >> s;
	while (s.size()>1)
	{
		s=sum(s);
		ans++;
	}
	cout << ans;
}