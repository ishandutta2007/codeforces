#include <iostream>
#include <string.h>
using namespace std;
string s,c="heidi";
int main()
{
	cin >> s;
	int x=0;
	for (int i=0;i<s.size() && x<5;i++)
	{
		if (s[i]==c[x])
		x++;
	}
	if (x==5)
	cout << "YES";
	else
	cout << "NO";
}