#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	bool c=false;
	for (int i=0;i<n;i++)
	{
		string s;
		int a,b;
		cin >> s >> a >> b;
		if (a>=2400 && b>a)
		c=true;
	}
	if (c)
	cout << "YES";
	else
	cout << "NO";
}