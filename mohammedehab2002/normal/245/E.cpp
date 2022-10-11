#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s;
	int i,n1=0,n2=0,ans=0;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='+')
		{
			if (n2==0)
			ans++;
			else
			n2--;
			n1++;
		}
		else
		{
			if (n1==0)
			ans++;
			else
			n1--;
			n2++;
		}
	}
	cout << ans;
}