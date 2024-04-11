#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int i,x;
	string s,a,ans;
	cin >> s >> a;
	if (s=="0" && a=="0")
	{
		cout << "OK";
		return 0;
	}
	sort (s.begin(),s.end());
	for (i=0;i<s.size();i++)
	{
		if (s[i]!='0')
		break;
	}
	ans+=s[i];
	for (x=0;x<i;x++)
	ans+=s[x];
	for (x=i+1;x<s.size();x++)
	ans+=s[x];
	if (ans==a)
	cout << "OK";
	else
	cout << "WRONG_ANSWER";
}