#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s[n];
	for (int i=0;i<n;i++)
	cin >> s[i];
	for (int i=0;i<n;i++)
	{
		if (s[i][0]==s[i][1] && s[i][0]=='O')
		{
			cout << "YES" << endl;
			s[i][0]='+';
			s[i][1]='+';
			for (int x=0;x<n;x++)
			cout << s[x] << endl;
			return 0;
		}
		if (s[i][3]==s[i][4] && s[i][3]=='O')
		{
			cout << "YES" << endl;
			s[i][3]='+';
			s[i][4]='+';
			for (int x=0;x<n;x++)
			cout << s[x] << endl;
			return 0;
		}
	}
	cout << "NO";
}