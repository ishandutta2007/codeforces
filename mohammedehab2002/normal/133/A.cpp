#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int i;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='H' || s[i]=='Q' || s[i]=='9')
		{
			cout << "YES";
			exit(0);
		}
	}
	cout << "NO";
}