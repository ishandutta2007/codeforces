#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s;
	int n,t;
	cin >> n >> t >> s;
	for (int i=0;i<t;i++)
	{
		for (int x=0;x<s.size()-1;x++)
		{
			if (s[x]=='B' && s[x+1]=='G')
			{
				swap(s[x],s[x+1]);
				x++;
			}
		}
	}
	cout << s;
}