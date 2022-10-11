#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n1=count(s.begin(),s.end(),'4');
	int n2=count(s.begin(),s.end(),'7');
	if (n1==0 && n2==0)
	cout << -1;
	else
	{
		if (n1>=n2)
		cout << 4;
		else
		cout << 7;
	}
}