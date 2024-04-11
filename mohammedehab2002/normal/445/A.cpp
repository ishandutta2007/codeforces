#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m,i,x;
	cin >> n >> m;
	string s[n];
	for (i=0;i<n;i++)
	cin >> s[i];
	for (i=0;i<n;i++)
	{
		for (x=0;x<m;x++)
		{
			if (s[i][x]=='.')
			{
				if ((i+x)%2)
				cout << 'W';
				else
				cout << 'B';
			}
			else
			cout << '-';
		}
		cout << endl;
	}
}