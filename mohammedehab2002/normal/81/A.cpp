#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i;
	string s;
	cin >> s;
	for (i=s.size()-2;i>=0;i--)
	{
		if (s[i]==s[i+1])
		s.erase(i,2);
	}
	cout << s;
}