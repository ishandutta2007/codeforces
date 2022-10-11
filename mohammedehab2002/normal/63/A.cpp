#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i,x;
	cin >> n;
	string s[n*2],type[]={"rat","woman","man","captain"};
	for (i=0;i<n*2;i++)
	{
		cin >> s[i];
		if (s[i]=="child" && i%2)
		s[i]="woman";
	}
	for (x=0;x<4;x++)
	{
		for (i=0;i<n*2;i+=2)
		{
			if (s[i+1]==type[x])
			cout << s[i] << endl;
		}
	}
}