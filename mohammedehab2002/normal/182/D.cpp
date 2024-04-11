#include <iostream>
#include <string.h>
using namespace std;
string s1,s2;
bool check(string s,int i)
{
	for (int x=0;x<s.size();x++)
	{
		if (s[x]!=s[x%i])
		return false;
	}
	return true;
}
bool check2(int i)
{
	string a1=s1.substr(0,i);
	string a2=s2.substr(0,i);
	return (a1==a2);
}
int main()
{
	int ans=0;
	cin >> s1 >> s2;
	for (int i=1;i<=min(s1.size(),s2.size());i++)
	{
		if (s1.size()%i==0 && s2.size()%i==0)
		{
			if (check2(i) && check(s1,i) && check(s2,i))
			ans++;
		}
	}
	cout << ans;
}