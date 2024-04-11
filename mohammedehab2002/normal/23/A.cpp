#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,x;
	string s;
	cin >> s;
	for (i=s.size();i>0;i--)
	{
		for (x=0;x<s.size()-i;x++)
		{
			if (s.substr(x+1).find(s.substr(x,i))!=string::npos)
			{
				cout << i;
				return 0;
			}
		}
	}
	cout << 0;
}