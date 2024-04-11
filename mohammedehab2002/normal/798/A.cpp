#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	bool b=1;
	string s;
	cin >> s;
	for (int i=0;i<s.size()/2;i++)
	{
		if (s[i]!=s[s.size()-i-1])
		{
			if (b)
			b=0;
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}
	if (s.size()%2==0 && b)
	cout << "NO";
	else
	cout << "YES";
}