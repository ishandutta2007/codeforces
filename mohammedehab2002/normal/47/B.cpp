#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,x,arr[]={0,0,0};
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	for (i=0;i<3;i++)
	{
		if (s[i][1]=='>')
		arr[s[i][0]-'A']++;
		else
		arr[s[i][2]-'A']++;
	}
	for (i=0;i<3;i++)
	{
		for (x=0;x<3;x++)
		{
			if (arr[i]==arr[x] && i!=x)
			{
				cout << "Impossible";
				return 0;
			}
		}
	}
	for (i=0;i<3;i++)
	{
		if (arr[i]==0)
		cout << (char)(i+'A');
	}
	for (i=0;i<3;i++)
	{
		if (arr[i]==1)
		cout << (char)(i+'A');
	}
	for (i=0;i<3;i++)
	{
		if (arr[i]==2)
		cout << (char)(i+'A');
	}
}